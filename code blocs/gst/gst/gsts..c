#include <stdio.h>
#include "gsts.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/*
Sortie Add_stc()
{
    Sortie etd;
    printf("\n Introduire le Code Client: ");
    scanf("%d", &etd.code_client);
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
*/

Sortie Add_client()
{
    Sortie etd;
    printf("\n Introduire le Code Client: ");
    scanf("%d", &etd.code_client);
    printf("\n Introduire le Nom: ");
    scanf("%s", &etd.Nom);
    printf("\n Introduire l'adress: ");
    scanf("%s", &etd.Adress);
    printf("\n Introduire le numero : ");
    scanf("%d", &etd.Tel);
    return etd;
}



void gestion_des_clients(Sortie stc[], int* N)
{
    int choix;
        while (1)
    {
        printf("\n **************************\n\tmenu\t\n****************************");
        printf("\n 1. ajouter client");
        printf("\n 2. modifier client ");
        printf("\n 3. afficher clients ");
        printf("\n 4. supprimer client ");
        printf("\n 0. Quitter");
        printf("\n Introduire votre choix: ");
        printf("\n ******************************************************");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            {
                int  i = 0;
                Sortie e;
                char rep;
                do
                {
                    e = Add_client();
                    stc[i]=e;
                    i++;
                    printf("\n  Voulez vous ajouter une autre commande");
                    scanf("%c",&rep);
                    printf("\n  Voulez vous ajouter une autre commande");
                }while (strcmp(rep, "o")==0);
                *N=i;
                break;
                }
            case 2:
                {
                    break;
                }
            case 0:
                {
                    break;
                }

            }
}
}

/*

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


*/


/*

void Afficher_Stats()
{
    return -1;
}*/
