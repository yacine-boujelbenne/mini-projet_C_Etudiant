#include <stdio.h>
#include "gst.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



Sortie Add_stc()
{
    Sortie etd;
    /*
    bool t1 = true;
    bool t2 = true;
    FILE* f1=fopen('Fclients.txt', 'rt');
    FILE* f2=fopen('Farticle.txt', 'rt');
    do
    {
        printf("\n Introduire le Code Client: ");
        scanf("%d", &etd.Code_Client);
        printf("\n Introduire le Code Art: ");
        scanf("%s", &etd.Code_Art);
    } while (t1 && t2);

    fclose(f1);
    fclose(f2);
    */
    printf("\n Introduire le Code Client: ");
    scanf("%d", &etd.Code_Client);
    printf("\n Introduire le Code Art: ");
    scanf("%d", &etd.Code_Art);
    printf("\n Introduire le Prix unitaire de vente: ");
    scanf("%d", &etd.Prix_unitaire_de_vente);
    printf("\n Introduire la quantité de sortie: ");
    scanf("%d", &etd.Qtsortie);
    printf("\n Introduire la Date de sortie du stock: ");
    scanf("%d %d %d", &etd.Date_Sortie_Stock.jour, &etd.Date_Sortie_Stock.mois, &etd.Date_Sortie_Stock.annee);
    return etd;
}


void gestion_des_clients()
{
    return -1;
}




void Gestion_des_sorties(Sortie stc[], int* N)
{
    FILE* fch= fopen('FCmdeSortie.txt', 'wt');
    int  i = 0;
    Sortie e;
    char rep;
    do
    {
        e = Add_stc();
        stc[i]=e;
        fprintf(fch, "%d %d %f %d %d\n", stc[i].Code_Art, stc[i].Code_Client,stc[i].Date_Sortie_Stock,stc[i].Prix_unitaire_de_vente,stc[i].Qtsortie);
        i++;
        printf("\n  Voulez vous ajouter une autre commande");
        scanf("%s",&rep);

    }while (strcmp(rep, "O")==0);
    *N=i;
    fclose(fch);
}







void Afficher_Stats()
{
    return 0;
}
