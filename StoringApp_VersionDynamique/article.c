#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>


Liste_Article liste_articles = NULL;

Liste_Article insere(Article element,Liste_Article Lst) {
    struct cellule_article* courant = (struct cellule_article*) malloc(sizeof(struct cellule_article));
    courant->valeur = element;
    courant->suivant = Lst;
    return courant;
}

Article* rechercher_article(Liste_Article Lst, int code) {
    struct cellule_article* courant = Lst;
    while (courant != NULL) {
        if (courant->valeur.code_art == code)
            return &courant->valeur;
        courant = courant->suivant;
    }
    return NULL;
}

void ajouter_article(Liste_Article *Lst) {
    Article article;
    printf("\nSaisir le code de l'article : ");
    while (scanf("%d", &article.code_art) != 1) {
        printf("\nCode invalide. Veuillez réessayer : ");
        while(getchar() != '\n');
    }
    getchar();
    printf("\nSaisir le nom de l'article : ");
    fgets(article.nom_art, 50, stdin);
    article.nom_art[strcspn(article.nom_art, "\n")] = 0;
    printf("\nSaisir la description de l'article : ");
    fgets(article.description, 100, stdin);
    article.description[strcspn(article.description, "\n")] = 0;
    printf("\nSaisir le seuil de stock : ");
    while (scanf("%d", &article.seuil_stock) != 1) {
        printf("\nSeuil de stock invalide. Veuillez réessayer : ");
        while(getchar() != '\n');
    }
    *Lst = insere(article, *Lst);
}

void modifier_article(Article *art) {
    int choix;
        printf("\nQue voulez-vous modifier?\n");
        printf("\n1. Nom de l'article\n");
        printf("2. Description de l'article\n");
        printf("3. Seuil de stock\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch(choix){
            case 1:{
                printf("\nModifier le nom de l'article : ");
                getchar();
                fgets(art->nom_art, 50, stdin);
                art->nom_art[strcspn(art->nom_art, "\n")] = 0;
                break;
            }
            case 2:{
                printf("\nModifier la description de l'article : ");
                fgets(art->description, 100, stdin);
                art->description[strcspn(art->description, "\n")] = 0;
                break;
            }
            case 3:{
                printf("\nModifier le seuil de stock : ");
                while (scanf("%d", &art->seuil_stock) != 1) {
                printf("\nSeuil de stock invalide. Veuillez réessayer : ");
                while(getchar() != '\n');
                }
                break;
            }
            default:{
                printf("\nChoix eronnee.\n");
                
            }
        }
       
}

void supprimer_article(Liste_Article *Lst, int code) {


    Liste_Article courant = *Lst;
    Liste_Article precedent = NULL;
    while (courant != NULL && courant->valeur.code_art != code) {
        precedent = courant;
        courant = courant->suivant;
    }

    if (courant != NULL) {
        if (precedent == NULL) {
            *Lst = courant->suivant;
        } else {
            precedent->suivant = courant->suivant;
        }
        free(courant);
        printf("\nArticle supprimé.\n");
    } else {
        printf("\nArticle non trouvé.\n");
    }
}

void main1() {
    int choix = 0;
    int code;
    Article *rech ;
    char rep[3];
    FILE *fichier;
    time_t seconde;
    struct tm instant;
    time(&seconde);
    instant = *localtime(&seconde);

    fichier = fopen("Farticles.txt", "rt");
    if (fichier == NULL) {
        printf("\nFichier inexistant");
    } else {
        while (!feof(fichier)) {
            Article article;
            fscanf(fichier, "%d\n", &article.code_art);
            fgets(article.nom_art, 50, fichier);
            article.nom_art[strcspn(article.nom_art, "\n")] = 0;
            fgets(article.description, 100, fichier);
            article.description[strcspn(article.description, "\n")] = 0;
            fscanf(fichier, "%d\n", &article.seuil_stock);
            if (rechercher_article(liste_articles, article.code_art)==NULL)
            {
                liste_articles = insere(article, liste_articles);
            }
            
        }
        fclose(fichier);
    }

    while (1) {
        printf("\n *************\n");
        printf("\n*** Gestion des articles ***\n");
        printf("\n *************\n");
        printf("\n1. Ajouter article\n");
        printf("2. Modifier article\n");
        printf("3. Supprimer article\n");
        printf("0. Quitter\n");
        printf("\n *************\n");
        printf("\n\t %d/%d/%d %d:%d", instant.tm_mday, instant.tm_mon + 1, instant.tm_year + 1900, instant.tm_hour, instant.tm_min);
        printf("\n *************\n");
        printf("\nIntroduire votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                do {
                    ajouter_article(&liste_articles);
                    printf("\nVoulez-vous ajouter un autre article ? (oui/non) : ");
                    scanf("%s", rep);
                } while (strcmp(rep, "oui") == 0);
                break;
            case 2:
                printf("\nSaisir le code de l'article à modifier : ");
                scanf("%d", &code);
                rech = rechercher_article(liste_articles, code);
                if (rech != NULL) {
                    modifier_article(rech);
                } else {
                    printf("\nArticle inexistant\n");
                }
                break;
            case 3:
                printf("\nSaisir le code de l'article à supprimer : ");
                scanf("%d", &code);
                rech = rechercher_article(liste_articles, code);
                if (rech != NULL) {
                    supprimer_article(&liste_articles, code);
                } else {
                    printf("\nArticle inexistant\n");
                }
                break;
            case 0:
                fichier = fopen("Farticles.txt", "wt");
                if (fichier == NULL) {
                    printf("\nErreur lors de l'ouverture du fichier");
                } else {
                    Liste_Article courant = liste_articles;
                    while (courant != NULL) {
                        fprintf(fichier, "%d\n", courant->valeur.code_art);
                        fputs(courant->valeur.nom_art, fichier);
                        fputs("\n", fichier);
                        fputs(courant->valeur.description, fichier);
                        fputs("\n", fichier);
                        fprintf(fichier, "%d\n", courant->valeur.seuil_stock);
                        courant = courant->suivant;
                    }
                    fclose(fichier);
                }
                return;
            default:
                printf("\nChoix erroné");
        }
    }
}
