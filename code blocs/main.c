#include <stdio.h>
#include "etudiant.h"
#include <stdlib.h>
#include <string.h>

int main()
{
    int Id;
    int rech= -1;
    Etudiant Tableau_Etud[100];
    int taille_tab =0;
    int choix=0;
    char rep[5];
    FILE* fich;
    int i=0;
    fich=fopen("backup.txt","rt");
    if (fich==NULL)
                printf("\n le fichier n'exixte pas");
            else
            {while (!feof(fich))
            {
                fscanf(fich,"%d %s %s %f \n", &Tableau_Etud[i].identifiant, Tableau_Etud[i].Nom, Tableau_Etud[i].Prenom, &Tableau_Etud[i].Notes);
                i++;
            }
            taille_tab=i;
            }
            fclose(fich);
    while (1)
    {
        printf("\n ****");
        printf("\n 1. Saisir tableau d'etudiants");
        printf("\n 2. Ajouter un etudiant");
        printf("\n 3. Rechercher un etudiant");
        printf("\n 4. Modifier un etudiant");
        printf("\n 5. Supprimer un etudiant");
        printf("\n 6. Afficher tableau d'etudiants");
        printf("\n 0. Quitter");
        printf("\n Introduire votre choix: ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
        {
            Saisir_Tab_Etd(Tableau_Etud,&taille_tab);
            break;
        }
        case 2:
        {
            Ajouter_Tab_Etud(Tableau_Etud,&taille_tab);
            break;
        }
        case 3:
        {
            printf("\n Introduire l'identifiant à chercher: ");
            scanf("%d",&Id);
            rech=Rechercher_Etd(Tableau_Etud,taille_tab,Id);
            if (rech == -1)
            {
                printf("\n Identifiant inexistant");
            }
            else
            {
                Affiche_etd(Tableau_Etud[rech]);
            }
            break;
        }
        case 4:
        {

            printf("\n Introduire l'identifiant de l'etudiant à modifier: ");
            scanf("%d",&Id);
            rech=Rechercher_Etd(Tableau_Etud,taille_tab,Id);
            if (rech==-1)
            {
                printf("\n Identifiant inexistant");
            }
            else
            {
                Affiche_etd(Tableau_Etud[rech]);
                printf("\n Etes vous sur de vouloir modifier cet etudiant? ");
                scanf("%s",rep);
                if (strcmp(rep,"oui")==0)
                {
                    Modifier_Etd(Tableau_Etud, rech);
                }

            }
            break;
        }
        case 5:
        {
             printf("\n Introduire l'identifiant de l'etudiant à supprimer: ");
            scanf("%d",&Id);
            rech=Rechercher_Etd(Tableau_Etud,taille_tab,Id);
            if (rech==-1)
            {
                printf("\n Identifiant inexistant");
            }
            else
            {
                Affiche_etd(Tableau_Etud[rech]);
                printf("\n Etes vous sur de vouloir supprimer cet etudiant? ");
                scanf("%s",rep);
                if (strcmp(rep,"oui")==0)
                {
                    Supprimer_Etud(Tableau_Etud,&taille_tab, rech);
                }

            break;
        }
        case 6:
        {




            Affiche_Tab_etd(Tableau_Etud,taille_tab);


            break;
        }
        case 0:
        {
            fich=fopen("backup.txt","wt");
            if (fich==NULL)
                printf("\n le fichier n'exixte pas");
            else
            {for(int i=0 ;i<taille_tab;i++)
            {
                fprintf(fich,"%d %s %s %d  \n", &Tableau_Etud[i].identifiant, Tableau_Etud[i].Nom, Tableau_Etud[i].Prenom, &Tableau_Etud[i].Notes);

            }

            }
            fclose(fich);
            exit(1);
        }
        default:
        {
            printf("\n choix erronee");
            break;
        }
        }
    }


    }
    return 0;
}
