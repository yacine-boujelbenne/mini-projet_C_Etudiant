#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Gestion_des_entree.h"
#include"fournisseur.h"
#include"header.h"
#include "gestion_client.h"


Liste_Entree liste_entree=NULL;
extern Liste_fournisseur liste_fournisseur;


entree* Rechercher_entree(Liste_Entree Lst, int ident)
{
    struct cellule_en* courrant;
    courrant =Lst;
    while (courrant!=NULL)
    {
    //traitement afficher l’entudiant
    if (courrant->valeur_en.Code_Article==ident)
        return &(courrant->valeur_en);
    courrant=courrant->suivant_en;
    }

    return NULL;
}

void obtenir_date_actuelle(char *date_str) {
    time_t seconde;
    struct tm instant;
    time(&seconde);
    instant=*localtime(&seconde);  // Format JJ/MM/AAAA
    snprintf(date_str, 11, "%02d/%02d/%d", instant.tm_mday, instant.tm_mon + 1, instant.tm_year + 1900);
}

entree Saisir_Entree(){



    //Initialisation de donnee des autre structures
    int code_fournisseur;
    int code_article;
    entree en;
    Sortie sortie;
    fournisseur* rech_fr;
    fournisseur fr;
    Article* rech_article;
    Article ar;
    Sortie* rech_entree;
    //fn d'initialisation des entree
    

    

    //fin des règlage de temps

    //ouvrir la fichier Farticles.txt
    FILE* fichier;





    fichier=fopen("Farticles.txt","rt");
    if(fichier==NULL){
        printf("\nErreur lors de l'ouverture du fichier Farticles.txt");
    }else{
        while(fscanf(fichier,"%d %s %s %d",&ar.code_art,
        ar.nom_art,ar.description,&ar.seuil_stock)==4){
            liste_articles=insere(ar,liste_articles);
        }fclose(fichier);
    }
    //ouverture de la fichier fournisseur.txt
    fichier=fopen("fournisseur.txt","rt");
    if(fichier==NULL){
        printf("\nFichier inexistante\n");
    }else{
        /*while(!feof(fichier)){
            fscanf(fichier,"%d",&fr.Code_Fournisseur);
            fscanf(fichier,"%s",fr.Nom_Fournisseur);
            fscanf(fichier,"%s",fr.Adresse_Fournisseur);
            fscanf(fichier,"%d",&fr.Telephone_Fournisseur);
            liste_fournisseur=insert(fr,liste_fournisseur);
        }*/
        while (fscanf(fichier, "%d %s %s %d", &fr.Code_Fournisseur, fr.Nom_Fournisseur, fr.Adresse_Fournisseur, &fr.Telephone_Fournisseur) == 4) {
            liste_fournisseur = insert_fournisseur(fr, liste_fournisseur);
        }
        fclose(fichier);
    }
    //vérifier si l code fournisseur dans le fichier fournisseur.txt

    do{ 
        printf("\n*********************");
        printf("\n Saisie code fournisseur:");
        scanf("%d",&code_fournisseur);
        rech_fr=rechercher_fournisseur(liste_fournisseur,code_fournisseur);
        if(rech_fr==NULL){printf("Fournisseur inexistent dans la fichier fournisseur.txt");}
        else{en.Code_Fournisseur=rech_fr->Code_Fournisseur;}


    }while(rech_fr==NULL);
    do{
        printf("\n*********************");
        printf("\n Saisie code article:");
        scanf("%d",&code_article);
        rech_article=rechercher_article(liste_articles,code_article);
        if(rech_article==NULL){printf("Article inexistant dans la fichier Farticles.txt");}
        else{en.Code_Article=rech_article->code_art;}
    }while(rech_article==NULL);
    printf("\nIntroduire le Prix_unitaire d'achat: ");
    scanf("%f",&en.Prix_Unitaire_Achat);
    printf("\nIntroduire la quantité d'entree: ");
    scanf("%d",&en.Qte_Entree);
    rech_entree=Rechercher_sortie(liste_sortie, code_article);
    if (rech_entree == NULL){
        sortie.Code_Art= en.Code_Article;
        sortie.Qtsortie = en.Qte_Entree;
        liste_sortie = insere_sortie(sortie, liste_sortie);

    }else{
        rech_entree->Qtsortie+= en.Qte_Entree;
        obtenir_date_actuelle(en.Date_Entree_Stock);
        printf("\nLa date d'entree en stock :%s",en.Date_Entree_Stock);
          

       
   
    }
        fichier=fopen("les_sorties.txt","wt");
        if (fichier == NULL) {
            printf("\nErreur lors de l'ouverture du fichier");
        }
        else{

            Liste_sortie courant = liste_sortie;
            while (courant != NULL) {
                fprintf(fichier, "%d\n", courant->valeur_sortie.Code_Art);
                fprintf(fichier, "%d\n", courant->valeur_sortie.Qtsortie);
                courant = courant->suivant_sortie;

            }
            fclose(fichier);
               
            printf(" done saving! \n"); 
        }
     return en;
}

Liste_Entree insert(entree element, Liste_Entree Lst){
    struct cellule_en* courrant;
    courrant=(struct cellule_en *)malloc(sizeof(struct cellule_en));
    courrant->valeur_en=element;
    courrant->suivant_en=Lst;
    return courrant;
}



void gestion_entree_stock() {
    entree en;
    FILE *fichier;
    char rep[4];
    
    do {
        // Load existing entries from the file
        fichier = fopen("FcmdeEntree.txt", "rt");
        if (fichier == NULL) {
            printf("\nFichier inexistant. Aucun chargement effectué.\n");
        } else {
            while (!feof(fichier)) {
                entree ens;
                if (fscanf(fichier, "%d %d %d %f %s", 
                           &ens.Code_Fournisseur, 
                           &ens.Code_Article, 
                           &ens.Qte_Entree, 
                           &ens.Prix_Unitaire_Achat, 
                           ens.Date_Entree_Stock) == 5) {
                    liste_entree = insert(ens, liste_entree);
                }
            }
            fclose(fichier);
        }

        en = Saisir_Entree();
        entree* new_entree = Rechercher_entree(liste_entree, en.Code_Article);
        if (new_entree != NULL) {
            new_entree->Prix_Unitaire_Achat = en.Prix_Unitaire_Achat;
            strcpy(new_entree->Date_Entree_Stock, en.Date_Entree_Stock);
        } else {
            liste_entree = insert(en, liste_entree);
        }
        fichier = fopen("FcmdeEntree.txt", "wt");
        if (fichier == NULL) {
            printf("\nErreur lors de l'ouverture du fichier pour sauvegarde.\n");
        } else {
            Liste_Entree courant = liste_entree;
            while (courant != NULL) {
                fprintf(fichier, "%d %d %d %f %s\n", 
                        courant->valeur_en.Code_Fournisseur, 
                        courant->valeur_en.Code_Article, 
                        courant->valeur_en.Qte_Entree, 
                        courant->valeur_en.Prix_Unitaire_Achat, 
                        courant->valeur_en.Date_Entree_Stock);
                courant = courant->suivant_en;
            }
            fclose(fichier);
            printf("\nFichier sauvegardé avec succès !\n");
        }
        printf("\nVoulez-vous ajouter une autre commande (oui/non) ? ");
        scanf("%s", rep);

    } while (strcmp(rep, "oui") == 0);

    printf("\nFin de la gestion des entrées en stock.\n");
}






void main2_2(){
    entree en;
   // struct cellule_en* courrant;
    int choix;
    FILE* fichier;
    /*fichier=fopen("fournisseur.txt","rt");
    if(fichier==NULL){
        printf("Erreur d'ouverture du fichier\n");
    }else{
        while (fscanf(fichier, "%d %s %s %d", &fr.Code_Fournisseur, fr.Nom_Fournisseur, fr.Adresse_Fournisseur, &fr.Telephone_Fournisseur) == 4) {
            liste_fournisseur = insert_fournisseur(fr, liste_fournisseur);
        }
        fclose(fichier);
    }*/
    fichier=fopen("FcmdeEntree.txt","rt");
    if(fichier==NULL){printf("Erreur d'ouverture du fichier");}
    else{
        while(fscanf(fichier,"%d %d %d %f %s",&en.Code_Fournisseur,&en.Code_Article,
        &en.Qte_Entree,&en.Prix_Unitaire_Achat,en.Date_Entree_Stock)==4){
            liste_entree=insert(en,liste_entree);
        }
    }

                fichier = fopen("les_sorties.txt", "rt");
                if (fichier == NULL) {
                    printf("\nFichier inexistant");
                } else {
                    while (!feof(fichier)) {
                        Sortie sortiess;
                        fscanf(fichier, "%d\n", &sortiess.Code_Art);
                        fscanf(fichier, "%d\n", &sortiess.Qtsortie);
                        if (Rechercher_sortie(liste_sortie,sortiess.Code_Art)!= NULL)
                        {
                            liste_sortie= *Supprimer_sorties(&liste_sortie,sortiess.Code_Art);
                        }
                            liste_sortie = insere_sortie(sortiess, liste_sortie);

                        
                    }
                    
                }
                fclose(fichier);

    
    while (1) {
        printf("\n****** Gestion des Entrées en Stock ******\n");
        printf("1. Gestion des fornisseurs\n");
        printf("2. Saisir une entrée en stock\n");
        printf("3. Affiche statistiques \n");
        printf("0. Quitter\n");
         printf("\n***********************************");
        printf("\nChoisissez une option: ");
        scanf("%d", &choix);
        switch(choix){
            case 1:{
                main2_1();
                break;
            }
            case 2:{
                gestion_entree_stock();
                break;
                }
            case 3:
            {
                fichier=fopen("les_sorties.txt","rt");
                if (fichier == NULL) {
                    printf("\nFichier inexistant");
                } else {
                    int f = 0;
                    while (!feof(fichier)) {
                        Sortie sortie;
                        fscanf(fichier, "%d\n", &sortie.Code_Art);
                        fscanf(fichier, "%d\n", &sortie.Qtsortie);
                        printf("produit n'%d : %s \n quantite : %d \n **************\n",f+1,rechercher_article(liste_articles,sortie.Code_Art)->nom_art,sortie.Qtsortie);
                        f++;
                    }
                    fclose(fichier);
                }

                printf("**********************\n");
            break;
            }
            case 0:{
                /*fichier=fopen("FcmdeEntree.txt","wt");
                if(fichier==NULL){printf("\nErreur de creation de fichier");}
                else{
                    courrant=liste_entree;
                    while(courrant!=NULL){
                        fprintf(fichier, "%d %d %d %f %s \n", courrant->valeur_en.Code_Fournisseur, 
                            courrant->valeur_en.Code_Article,courrant->valeur_en.Qte_Entree,courrant->valeur_en.Prix_Unitaire_Achat,
                            courrant->valeur_en.Date_Entree_Stock);
                            courrant=courrant->suivant_en;
                    }
                    fclose(fichier);
                    printf("\nFichier sauvegarde avec succes");
                }*/
                return;
            }default:
                printf("\nChoix invalide!");
        }   
    }
}