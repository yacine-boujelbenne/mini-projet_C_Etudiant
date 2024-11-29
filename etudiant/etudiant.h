#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED
typedef struct {
    int identifiant;
    char Nom[25];
    char Prenom[25];
    float Notes[4];
    float Moy;
}Etudiant;

Etudiant Saisir_etd();
void Saisir_Tab_Etd(Etudiant Tab[], int* N);
void Ajouter_Tab_Etud(Etudiant Tab[], int* N);
void Affiche_etd(Etudiant e);

void Affiche_Tab_etd(Etudiant Tab[], int N);

int Rechercher_Etd(Etudiant Tab[], int N,int ident);


void Modifier_Etud(Etudiant tab_Etud[], int rech);
void Supprimer_Etud(Etudiant tab_Etud[],int* N , int rech);



#endif