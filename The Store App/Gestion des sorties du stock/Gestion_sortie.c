#include <stdio.h>
#include "Gestion_sortie.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




cortie Add_client()
{
    cortie etd;
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
    printf("\n Introduire la Date de sortie du stock: dd mm yyyy ");
    scanf("%d %d %d", &etd.date_Sortie_Stock.day, &etd.date_Sortie_Stock.month, &etd.date_Sortie_Stock.year);
    
    return etd;
}


void gestion_des_clients(cortie stc[], int* N)
{
    int choix;
        while (1)
    {
        printf("\n    **************************\n\tmenu\t\n****************************");
        printf("\n                          1. ajouter client");
        printf("\n                          2. modifier client ");
        printf("\n                          3. afficher clients ");
        printf("\n                          4. supprimer client ");
        printf("\n                          0. Quitter");
        printf("\n             ****************************************************\n");
        printf("\n                  ->Introduire votre choix: ");
        scanf("%d", &choix);
        int Id;
        int rech;
        switch (choix)
        {
            case 1:
                {
                    int  i = 0;
                    cortie e;
                    char rep[1] ="";
                    do
                    {
                        e = Add_client();
                        stc[i]= e;
                        i++;
                        printf("\n  Voulez vous ajouter une autre commande");
                        scanf("votre repense : %s ",&rep);
                    }while (strcmp(rep ,"o")== 0);
                    *N=i;
                    break;
                }
            case 2:
                {
                    char rep[3];
                    printf("\n Introduire le code du client à modifier: ");
                    scanf("%d",&Id);
                    rech=Rechercher_client(stc,N,Id);
                    if (rech==-1)
                    {
                        printf("\n Code inexistant !");
                    }
                    else
                    {
                        Affiche_client(stc[rech]);
                        printf("\n Etes vous sur de vouloir modifier cet client? ");
                        scanf("%s",rep);
                        if (strcmp(rep,"oui")==0)
                        {
                            Modifier_client(stc, rech);
                        }

                    }
                    break;
                }
            case 3:
                {
                    Affiche_liste_clients(stc, N);
                    break;
                }
            case 4:
                {
                    printf("\nvoulez vous entrer le code client a supprimer !");
                    scanf("%d", Id);
                    rech = Rechercher_client(stc,N, Id);
                    if (rech == -1)
                    {
                        printf("\nDesole mais le client est introuvable!");
                    }
                    else
                    {
                        Supprimer_clients(stc,N,rech);
                    }

                    break;
                }
            case 0:
                {
                    return 0;
                }
            default:
            {
                printf("\nchoix erronne !! ");
            }

        }
    }
}




void Gestion_des_sorties(Sortie stc[], int* N)
{
    //FILE* fch= fopen('backup.txt','wt');
    int  i = 0;
    Sortie e;
    char rep[1];
    do
    {
        e = Add_stc();
        stc[i]=e;
        //fprintf(fch, "%d %d %02d/%02d/%04d %f %d\n", stc[i].Code_Art, stc[i].Code_Client,stc[i].date_Sortie_Stock.day,stc[i].date_Sortie_Stock.month,stc[i].date_Sortie_Stock.year,stc[i].Prix_unitaire_de_vente,stc[i].Qtsortie);
        i++;
        printf("\n  Voulez vous ajouter une autre commande");
        scanf("%s",&rep);

    }while (strcmp(rep,"o")==0);         
    *N=i;
}




void Affiche_client(cortie e)
{
    printf("\n ******\n Code client : %d", e.code_client);

    printf("\n nom: %s", e.Nom);
    printf("\n Adress: %s", e.Adress);
    printf("\n Tel: %d", e.Tel);

}


void Affiche_liste_clients(cortie Tab[], int N)
{
    int i ;
    for (i=0;i<N;i++)
    {
        Affiche_client(Tab[i]);
    }

}


//Modification les profiles clients 


void Modifier_client(cortie Tab[], int rech )
{
    int choix;
    printf("\n 1. Modifier le nom");
    printf("\n 2. Modifier l'Adress");
    printf("\n 3. Modifier le numero de téléphone ");
    printf("\n 0. Quiter");


    scanf("%d",&choix);
    switch(choix)
    {
    case 1:
    {
        printf("\n Introduire le nom: ");
        scanf("%s", Tab[rech].Nom);
        break;
    }
    case 2:
    {
        printf("\n Introduire l'Adress ");
        scanf("%s", Tab[rech].Adress);
        break;
    }
    case 3:
    {
        printf("\n Introduire le numero de téléphone ");
        scanf("%d", &Tab[rech].Tel);
        break;
    }
    case 0:
    {
        return 0;
    }
    default :
        printf("\n choix erronee");
    }
}





//fonction de recherche 

int Rechercher_client(cortie Tab[], int N,int ident)
{
    for(int i=0;i<N; i++){
        if(Tab[i].code_client==ident){
            return i;
        }
    }


    return -1;
}


//supression des clients

void Supprimer_clients(cortie tab_client[],int* N , int rech){

    int i=0 ;
    int taille =*N;
    for (i = rech ; i<taille-1; i++)
    {
        tab_client[i]=tab_client[i+1];

    }
taille-=1;
(*N)=taille;
}
