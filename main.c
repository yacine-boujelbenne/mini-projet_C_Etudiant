#include<stdio.h>
#include <stdlib.h>
#include "etudiant.h"

int main(){
    int Id;
    int rech=-1;

    Etudiant Tableau_Etud[100];
    int taille_tab=0;
    Saisir_Tab_Etd(Tableau_Etud,&taille_tab);
    Affiche_Tab_etd(Tableau_Etud,taille_tab);
    printf("\n introduire l'identifiant a chercher: ");
    scanf("%d",&Id);
    rech = Rechercher_Etd(Tableau_Etud,taille_tab,Id);
    if(rech == -1){
        printf("_n Identifiant inexistent");

    }else{
        printf("\n Etudiant trouvé: ");
        Affiche_etd(Tableau_Etud[rech]);
    }
    return 0;
}


/*
    Etudiant Tableau_Etud[100];
    int taille_tab=0;
    Saisir_Tab_Etd(Tableau_Etud,&taille_tab);
    Affiche_Tab_etd(Tableau_Etud,taille_tab);
*/
