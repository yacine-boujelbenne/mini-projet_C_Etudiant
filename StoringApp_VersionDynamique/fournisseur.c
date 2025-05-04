#include "fournisseur.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
Liste_fournisseur liste_fournisseur=NULL;


fournisseur Saisir_fournisseur(){
    fournisseur fr;
    fournisseur* rech;//unicité de fournisseur
    do{
        printf("\n**************");
        printf("\nIntroduire le code de fournisseur: ");
        scanf("%d",&fr.Code_Fournisseur);
        rech=rechercher_fournisseur(liste_fournisseur,fr.Code_Fournisseur);
        if(rech!=NULL)printf("fournisseur exist deja");
    }while(rech!=NULL);
    printf("\nIntroduire le nom du fournisseur: ");
    fflush(stdin);
    gets(fr.Nom_Fournisseur);
    printf("\nIntroduire l'adresse du fournisseur: ");
    fflush(stdin);
    gets(fr.Adresse_Fournisseur);
    printf("\nIntroduire le telephone du fournisseur: ");
    scanf("%d",&fr.Telephone_Fournisseur);
    return fr;
} 
void Affiche_fournisseur(fournisseur fr){
    printf("\n**************\nCode Fournisseur: %d",fr.Code_Fournisseur);
    printf("\nNom Fornisseur: %s",fr.Nom_Fournisseur);
    printf("\nAdresse Fournisseur: %s",fr.Adresse_Fournisseur);
    printf("\nTelephone Fournisseur: %d",fr.Telephone_Fournisseur);
    printf("\n**************");
}
void Modifier_fournisseur(fournisseur *Fr){
    int choix;
    printf("\n1 .Modifier le nom du fournisseur: ");
    printf("\n2 .Modifier l'adresse du fournisseur: ");
    printf("\n3 .Modifier le telephone du fournisseur: ");
    printf("\nIntroduire votre choix: ");
    scanf("%d",&choix);
    switch(choix){
        case 1:{
            printf("\nModifier le nom: ");
            /*fgets(Fr->Nom_Fournisseur, sizeof(Fr->Nom_Fournisseur), stdin);
            Fr->Nom_Fournisseur[strcspn(Fr->Nom_Fournisseur, "\n")] = '\0';*/
            /*fflush(stdin);
            gets(Fr->Nom_Fournisseur);*/
            scanf("%s",Fr->Nom_Fournisseur);
            break;
        }
        case 2:{
            printf("\nModifier l'adresse: ");
            /*fgets(Fr->Adresse_Fournisseur, sizeof(Fr->Adresse_Fournisseur), stdin);
            Fr->Adresse_Fournisseur[strcspn(Fr->Adresse_Fournisseur, "\n")] = '\0';*/
            /*fflush(stdin);
            gets(Fr->Adresse_Fournisseur);*/
            scanf("%s",Fr->Adresse_Fournisseur);
            break;
        }
        case 3:{
            printf("\nModifier le telephone: ");
            scanf("%d",&Fr->Telephone_Fournisseur);
            break;
        }
        default : printf("\nChoix invalide!");
    }
}
void Affiche_Liste_fr(Liste_fournisseur Lst)
{
    struct cellule* courrant;
    courrant =Lst;
    while (courrant!=NULL)
    {
        Affiche_fournisseur(courrant->valeur_fr);
        courrant=courrant->suivant_fr;
    }
}

Liste_fournisseur insert_fournisseur(fournisseur element,Liste_fournisseur Lst){
    struct cellule* courrant;
    courrant=(struct cellule *)malloc(sizeof(struct cellule));
    courrant->valeur_fr=element;
    courrant->suivant_fr=Lst;
    return courrant;
}
fournisseur* rechercher_fournisseur(Liste_fournisseur Lst, int ident)
{
    struct cellule* courrant;
    courrant =Lst;
    while (courrant!=NULL)
    {
        if (courrant->valeur_fr.Code_Fournisseur==ident)
            return &(courrant->valeur_fr);
        courrant=courrant->suivant_fr;
    }
    return NULL;
}


void Supprimer_fournisseur(Liste_fournisseur *Lst,int code){

    Liste_fournisseur courant = *Lst;
    Liste_fournisseur precedent = NULL;
    while (courant != NULL && courant->valeur_fr.Code_Fournisseur != code) {
        precedent = courant;
        courant = courant->suivant_fr;
    }

    if (courant != NULL) {
        if (precedent == NULL) {
            *Lst = courant->suivant_fr;
        } else {
            precedent->suivant_fr = courant->suivant_fr;
        }
        free(courant);
        printf("\nFournisseur supprimé.\n");
    } else {
        printf("\nFournisseur non trouvé.\n");
    }
}

//main function:
void main2_1(){
    fournisseur fr;
    int Code_Fournisseur=-1;
    int choix;
    fournisseur* rech;
    struct cellule* courrant;
    char rep[4];
    FILE* fichier;
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant=*localtime(&secondes);
    printf("***%d/%d/%d************%d:%d:%d**********\n", instant.tm_mday,instant.tm_mon+1,instant.tm_year + 1900,
    instant.tm_hour,instant.tm_min,instant.tm_sec);
    fichier=fopen("fournisseur.txt","rt");
    if(fichier==NULL){
        printf("\nFichier inexistante\n");
    }else{
        /*while(!feof(fichier)){
            fscanf(fichier,"%d",&fr.Code_Fournisseur);
            fscanf(fichier,"%s",fr.Nom_Fournisseur);
            fscanf(fichier,"%s",fr.Adresse_Fournisseur);
            fscanf(fichier,"%d",&fr.Telephone_Fournisseur);
            liste_fournisseur=insert_fournisseur(fr,liste_fournisseur);
        }*/
        while (fscanf(fichier, "%d %s %s %d", &fr.Code_Fournisseur, fr.Nom_Fournisseur, fr.Adresse_Fournisseur, &fr.Telephone_Fournisseur) == 4) {
            liste_fournisseur = insert_fournisseur(fr, liste_fournisseur);
        }
        fclose(fichier);
    }
    while(1){
        printf("\n***********************************");
        printf("\n 1. Ajouter un fournisseur ");
        printf("\n 2. Rechercher un fournisseur ");
        printf("\n 3. Modifier un fournisseur ");
        printf("\n 4. Supprimer un fournisseur ");
        printf("\n 5. Afficher Liste de fournisseurs ");
         printf("\n 0. Quitter ");
        printf("\n***********************************");
        printf("\n Introduire votre choix: ");
        scanf ("%d",&choix);
        switch(choix){
            case 1:{
                do{
                    fr=Saisir_fournisseur();
                    if (rechercher_fournisseur(liste_fournisseur,fr.Code_Fournisseur)!=NULL){
                        printf("\nCe fournisseur existe deja");
                    }
                    else{
                        liste_fournisseur=insert_fournisseur(fr,liste_fournisseur);}
                    printf("\nVoulez vous ajouter un autre fournisseur? (oui/non): ");
                    scanf("%s",rep);
                }while(strcmp(rep,"oui")==0);
                break;
            }
            case 2:{
                printf("\nEntrez le code du fournisseur a rechercher: ");
                scanf("%d",&Code_Fournisseur);
                rech=rechercher_fournisseur(liste_fournisseur,Code_Fournisseur);
                if(rech==NULL){
                    printf("\nFournisseur inexistant");
                }
                else{ 
                    Affiche_fournisseur(*rech);
                }
                break;
            }
            case 3:{
                printf("\nIntroduire le code du fournisseur a modifier: ");
                scanf("%d",&Code_Fournisseur);
                rech=rechercher_fournisseur(liste_fournisseur,Code_Fournisseur);
                if(rech==NULL)printf("\nFournisseur inexistant");
                else{
                    Affiche_fournisseur(*rech);
                    printf("\nVoulez vous modifier cet fournisseur? (oui/non):");
                    scanf("%s",rep);
                    if(strcmp(rep,"oui")==0){
                        Modifier_fournisseur(rech);
                    }
                }
                break;
            }
            case 4:{
                int Id;
                printf("\nSaisir le code de fournisseur à supprimer : ");
                scanf("%d", &Id);
                rech = rechercher_fournisseur(liste_fournisseur, Id);//supprimer_fournisseur
                if (rech != NULL) {
                    Supprimer_fournisseur(&liste_fournisseur,Id);
                } else {
                    printf("\nfournisseur inexistant\n");
                }
                break;
            }
            case 5:{
                Affiche_Liste_fr(liste_fournisseur);
                break;
            }
            case 0:{
                fichier=fopen("fournisseur.txt","wt");
                if (fichier==NULL){
                    printf("\nErreur de creation de fichier");
                }else{
                    courrant=liste_fournisseur;
                    while(courrant!=NULL){
                        fprintf(fichier,"%d %s %s %d\n",courrant->valeur_fr.Code_Fournisseur,
                            courrant->valeur_fr.Nom_Fournisseur,
                            courrant->valeur_fr.Adresse_Fournisseur,
                            courrant->valeur_fr.Telephone_Fournisseur);
                        courrant=courrant->suivant_fr;
                    }
                    fclose(fichier);
                    printf("\nFichier sauvegarde avec succes");
                }
                return;
            }
            default:{
                printf("\nChoix invalide!");
            }
        }
    }
}