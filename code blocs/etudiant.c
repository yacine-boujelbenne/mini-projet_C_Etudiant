#include "etudiant.h"
#include<stdio.h>
#include<string.h>

Etudiant Saisir_etd()
{
    Etudiant etd;
    printf("\n introduire l'identidiant: ");
    scanf("%d", &etd.identifiant);
    printf("\n introduire le nom: ");
    scanf("%s", &etd.Nom);
    printf("\n introduire le prenom: ");
    scanf("%s", &etd.Prenom);
    for (int i=0;i<4;i++)
    {
        printf("Note[%d]= ",i);
        scanf("%f", &etd.Notes[i]);
    }
    return etd;
}
void Saisir_Tab_Etd(Etudiant Tab[], int* N)
{
    Etudiant e;
    int i;
    char rep[3];
    i = *N;
    do
    {
        e =Saisir_etd();
        Tab[i]=e;
        i++;
        printf("\n Voulez vous ajouter un autre etudiant ");
        scanf("%s",&rep);

    }while (strcmp(rep, "oui")==0);
    *N=i;
}

void Ajouter_Tab_Etud(Etudiant Tab[], int* N){

Etudiant e;
int i;
char rep[3];
i =*N;
{e=Saisir_etd();
Tab[i]=e;
i++;
*N=i;
}
}
void Affiche_etd(Etudiant e)
{
    printf("\n ******\n identifiant : %d", e.identifiant);
    printf("\n nom: %s", e.Nom);
    printf("\n prenom: %s", e.Prenom);
    for (int j = 0; j < 4; j++)
    {
        printf("\n notes[%d]=%f",j,e.Notes[j]);

    }

}
void Affiche_Tab_etd(Etudiant Tab[], int N)
{
    int i ;
    for (i=0;i<N;i++)
    {
        Affiche_etd(Tab[i]);
    }

}

int Rechercher_Etd(Etudiant Tab[], int N,int ident)
{
    for(int i=0;i<N; i++){
        if(Tab[i].identifiant==ident){
            return i;
        }
    }


    return -1;
}


void Modifier_Etd(Etudiant Tab[],int rech )
{
    int choix;
    printf("\n 1. Modifier le nom");
    printf("\n 2. Modifier le prenom");
    printf("\n 3. Modifier la note 0");

    printf("\n 4. Modifier la note 1");

    printf("\n 5. Modifier la note 2");

    printf("\n 6. Modifier la note 3");
    scanf("%d",&choix);
    switch(choix)
    {
    case 1:
    {
        printf("\n Introduire le nom: ");
        scanf("%s", Tab[rech].Nom);
        break;
    }
    case 2:
    {
        printf("\n Introduire le prenom: ");
        scanf("%s", Tab[rech].Prenom);
        break;
    }
    case 3:
    {
        printf("\n Introduire le note 0: ");
        scanf("%f", &Tab[rech].Notes[0]);
        break;
    }
    case 4:
    {
        printf("\n Introduire le note 1: ");
        scanf("%f", &Tab[rech].Notes[1]);
        break;
    }
    case 5:
    {
        printf("\n Introduire le note 2: ");
        scanf("%f", &Tab[rech].Notes[2]);
        break;
    }
    case 6:
    {
        printf("\n Introduire le note 3: ");
        scanf("%f", &Tab[rech].Notes[3]);
        break;
    }
    default :
        printf("\n choix erronee");
    }
}


void Supprimer_Etud(Etudiant tab_Etud[],int* N , int rech){

    int i=0 ;
    int taille =*N;
    for (i = rech ; i<taille-1; i++)
    {
        tab_Etud[i]=tab_Etud[i+1];

    }
taille-=1;
(*N)=taille;
}





