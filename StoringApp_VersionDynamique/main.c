#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include "fournisseur.h"
#include "header.h"
#include "gestion_Client.h"
#include "Gestion_des_entree.h"





int main (void){
    int chx;
    while(1){

        printf("********** Gestion du Stock **********");
        printf("\n 1 Gestion d'article ");
        printf("\n 2 Gestion des Entrées en stock");
        printf("\n 3 Gestion des Sorties du stock");
        printf("\n 0 quiter");
        printf("\n Saisie votre choix: \n");
        scanf("%d", &chx);
        switch (chx)
        {
            case 1:
                {
                    main1();
                    break;
                }
            case 2:
                {

                    main2_2();
                    break;
                }    
            case 3:
                {
                    main1_3();
                    break; 
                }
            case 0:
                {
                    exit(1); 
                }
            default:
                break;
        }

 }


return 0;
}