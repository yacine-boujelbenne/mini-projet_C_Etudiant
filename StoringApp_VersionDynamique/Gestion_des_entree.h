#ifndef GESTION_DES_ENTREE_H_INCLUDED
#define GESTION_DES_ENTREE_H_INCLUDED

// Structure d'entrée en stock
typedef struct entree{
    int Code_Fournisseur;          // Code du fournisseur
    int Code_Article;              // Code de l'article
    int Qte_Entree;                // Quantité entrée en stock
    float Prix_Unitaire_Achat;     // Prix unitaire d'achat de l'article
    char Date_Entree_Stock[11];    // Date d'entrée en stock au format JJ/MM/AAAA
} entree;

struct cellule_en{
    entree valeur_en;
    struct cellule_en *suivant_en;
};

typedef struct cellule_en *Liste_Entree;


entree Saisir_Entree();
Liste_Entree insert(entree element,Liste_Entree Lst);
//************************************************* 
void saisir_entree_stock();                            // Fonction pour saisir une entrée en stock
void afficher_entrees_stock(entree en);                         // Fonction pour afficher les entrées en stock
void gestion_entree_stock();//kima el main: mech tlem fiha kol les fonction  wba3d t3aytelha fl main te3ek
entree* Rechercher_entree(Liste_Entree Lst, int ident);
void Affiche_Liste_entree_stock(Liste_Entree Lst); 
void main2_2();

extern Liste_Entree liste_entree;

#endif//GESTION_DES_ENTREE_H_INCLUDED