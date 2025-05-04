#ifndef FOURNISSEUR_H_INCLUDED
#define FOURNISSEUR_H_INCLUDED


typedef struct fournisseur{
    int Code_Fournisseur;
    char Nom_Fournisseur[50];
    char Adresse_Fournisseur[100];
    int Telephone_Fournisseur;
} fournisseur;

struct cellule{
    fournisseur valeur_fr;
    struct cellule *suivant_fr;
};
typedef struct cellule *Liste_fournisseur;



fournisseur Saisir_fournisseur();
void Affiche_fournisseur(fournisseur fr);
void Modifier_fournisseur(fournisseur *Fr);
void Affiche_Liste_fr(Liste_fournisseur Lst);
void Supprimer_fournisseur(Liste_fournisseur *Lst,int code);
Liste_fournisseur insert_fournisseur(fournisseur element,Liste_fournisseur Lst);

fournisseur* rechercher_fournisseur(Liste_fournisseur,int ident);

void main2_1();
//void supprimer_fournisseur(); à complèter
extern Liste_fournisseur liste_fournisseur;
#endif// FOURNISSEUR_H_INCLUDED