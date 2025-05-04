/*#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct {
    int code_art;
    char nom_art[50];
    char description[100];
    int seuil_stock;
} Article;

struct cellule {
    Article valeur;
    struct cellule *suivant;
};
typedef struct cellule* Liste_Article;

Liste_Article insere_article(Article article, Liste_Article L);
void affiche_article(Article article);
Liste_Article rechercher_article(Liste_Article L, int code);
void afficher_liste_articles(Liste_Article L);
Article saisir_article();

#endif // HEADER_H_INCLUDED
*/
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct {
    int code_art;
    char nom_art[50];
    char description[100];
    int seuil_stock;
} Article;

struct cellule_article {
    Article valeur;
    struct cellule_article *suivant;
};
typedef struct cellule_article *Liste_Article;



void ajouter_article(Liste_Article *Lst);
void modifier_article(Article *art);
void supprimer_article(Liste_Article *Lst, int code);
Liste_Article insere(Article element, Liste_Article Lst);
Article* rechercher_article(Liste_Article Lst, int code);
void main1();
extern Liste_Article liste_articles;
#endif // HEADER_H_INCLUDED