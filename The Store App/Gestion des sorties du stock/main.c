#include <stdio.h>
#include "Gestion_sortie.h"
#include <stdlib.h>
#include <string.h>
#include<time.h>



int main()

{
    int Id ;
    int rech =-1;
    Sortie stc[100];
    cortie stc1[100];
    int taille_stc=0;
    int choix =0;
    char rep[5];
    time_t secondes ;
    struct tm instant;

    time(&secondes);
    instant =*localtime(&secondes);
    FILE* fich;
    while (1)
    {
        printf("\n **************************\n\t %d/%d/%d\t %d:%d \n****************************", instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900,instant.tm_hour,instant.tm_min);
        printf("\n       **************************\n\tmenu\t\n****************************");
        printf("\n                          1. Gestion des clients");
        printf("\n                          2. gestion des sorties ");
        printf("\n                          3. Afficher les statistiques de stock");
        printf("\n                          0. Quitter");
        printf("\n       *******************************************************************\n");
        printf("\n       ->Introduire votre choix: ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
        {
            gestion_des_clients(stc1, &taille_stc);
            break;
        }
        case 2:
        {
            Gestion_des_sorties(stc, &taille_stc);
            break;
        }
        case 3:
        {
            Afficher_Stats();
            break;
        }
        case 0:
        {
            fich=fopen("backup.txt","wt");
            if (fich==NULL)
                printf("\n le fichier n'exixte pas");
            else
            {
                for(int i ;i<taille_stc;i++)
                {
                    fprintf(fich, "%d \n%d \n%d \n%f %d \n", stc[i].Code_Art, stc[i].Code_Client,stc[i].date_Sortie_Stock,stc[i].Prix_unitaire_de_vente,stc[i].Qtsortie);
                    
                }
            }
            fclose(fich);
            exit(1);
        }
        default:
        {
            printf("\n choix erronee");
            break;
        }
        
    


    }

}
}