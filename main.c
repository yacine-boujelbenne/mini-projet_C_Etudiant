#include<stdio.h>
#include <stdlib.h>
#include "etudiant.h"

int main(){

    printf("Hello there! \n");
    Etudiant E;
    E =Saisir_etd();
    Affiche_etd(E);
    return 0;
}


/*
    Etudiant Tableau_Etud[100];
    int taille_tab=0;
    Saisir_Tab_Etd(Tableau_Etud,&taille_tab);
    Affiche_Tab_etd(Tableau_Etud,taille_tab);
*/
