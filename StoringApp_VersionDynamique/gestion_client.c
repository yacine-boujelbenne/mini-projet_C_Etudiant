#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "gestion_client.h"
#include "header.h"
#include <time.h>

client_struct stc1;
Sortie stc;
Sortie empty;
Liste_sortie liste_sortie ;
FILE* fich;
Liste_client liste_client ;


Liste_client insere_client(client_struct element, Liste_client Lst)
{
    struct cellule_client* Courrant;
    Courrant = (struct cellule_client *)malloc(sizeof(struct cellule_client ));
    Courrant ->valeur_client = element;
    Courrant ->suivant_client = Lst;
    return(Courrant);
}



Liste_sortie insere_sortie(Sortie element, Liste_sortie Lst)
{
    struct cellule_sortie* Courrant;
    Courrant = (struct cellule_sortie *)malloc(sizeof(struct cellule_sortie ));
    Courrant->valeur_sortie = element;
    Courrant ->suivant_sortie = Lst;
    return(Courrant);
}



client_struct* Rechercher_client(Liste_client Lst, int ident)
{
    struct cellule_client* courrant;
    courrant =Lst;
    while (courrant!=NULL)
    {
    //traitement afficher l’entudiant
    if (courrant->valeur_client.code_client==ident)
        return &(courrant->valeur_client);
    courrant=courrant->suivant_client;
    }

    return NULL;
}




Sortie* Rechercher_sortie(Liste_sortie Lst, int ident)
{
    struct cellule_sortie* courrant;
    courrant =Lst;
    while (courrant!=NULL)
    {
    //traitement afficher l’entudiant
    if (courrant->valeur_sortie.Code_Art==ident)
        return &(courrant->valeur_sortie);
    courrant=courrant->suivant_sortie;
    }

    return NULL;
}





client_struct Add_client()
{
    char nom[50]; char adr[50];
    client_struct etd;
    client_struct* resh;
       do
        {
            printf("\n Introduire le Code Client: ");
            scanf("%d", &etd.code_client);

            resh = Rechercher_client(liste_client,etd.code_client);

        if (resh != NULL){
            printf("*** code client deja exist! ***");
            break;
            }

        }while (resh != NULL);
    printf("\n Introduire le Nom: ");
    getchar();
    fgets(nom, 50, stdin);
    nom[strcspn(nom, "\n")] = 0;
    strcpy(etd.Nom,nom);
    printf("\n Introduire l'adress: ");
    getchar();
    fgets(adr, 50, stdin);
    adr[strcspn(adr, "\n")] = 0;
    strcpy(etd.Adress,adr);
    printf("\n Introduire le numero : ");
    scanf("%d", &etd.Tel);
    return etd;
}



void Modifier_client(client_struct* rech )
{
    int choix;
    printf("\n 1. Modifier le nom");
    printf("\n 2. Modifier l'Adress");
    printf("\n 3. Modifier le numero de téléphone ");
    printf("\n 0. Quiter\n");

    printf("\n                  ->Introduire votre choix: \n");
    scanf("%d",&choix);
    switch(choix)
    {
    case 1:
    {
        printf("\n Introduire le nom: ");
        scanf("%s", rech->Nom);
        break;
    }
    case 2:
    {
        printf("\n Introduire l'Adress ");
        scanf("%s", rech->Adress);
        break;
    }
    case 3:
    {
        printf("\n Introduire le numero de téléphone ");
        scanf("%d", &rech->Tel);
        break;
    }
    case 0:
    {
        return ;

    }
    default :
        printf("\n choix erronee");
    }
}





void Affiche_client(client_struct e)
{
    printf("\n ******\n Code client : %d", e.code_client);

    printf("\n nom: %s", e.Nom);
    printf("\n Adress: %s", e.Adress);
    printf("\n Tel: %d", e.Tel);

}


void Affiche_list_clients(Liste_client Lst)
{
    Liste_client courrant;
    courrant =Lst;
    while (courrant!=NULL)
    {
    //traitement afficher l’entudiant
        Affiche_client(courrant->valeur_client);
        courrant=courrant->suivant_client;
}
}

Liste_sortie* Supprimer_sorties(Liste_sortie *Lst,int code){


    Liste_sortie courant = *Lst;
    Liste_sortie precedent = NULL;
    while (courant != NULL && courant->valeur_sortie.Code_Art != code) {
        precedent = courant;
        courant = courant->suivant_sortie;
    }

    if (courant != NULL) {
        if (precedent == NULL) {
            *Lst = courant->suivant_sortie;
        } else {
            precedent->suivant_sortie = courant->suivant_sortie;
        }
        free(courant);
        printf("\nArticle supprimé.\n");
    } else {
        printf("\nArticle non trouvé.\n");
    }
    return Lst;
}

Liste_client* Supprimer_clients(Liste_client *Lst,int code){


    Liste_client courant = *Lst;
    Liste_client precedent = NULL;
    while (courant != NULL && courant->valeur_client.code_client != code) {
        precedent = courant;
        courant = courant->suivant_client;
    }

    if (courant != NULL) {
        if (precedent == NULL) {
            *Lst = courant->suivant_client;
        } else {
            precedent->suivant_client = courant->suivant_client;
        }
        printf("%d %s",courant->valeur_client.code_client, courant->valeur_client.Nom);
        free(courant);
        printf("\nArticle supprimé.\n");
    } else {
        printf("\nArticle non trouvé.\n");
    }
    return Lst;
}






// ajouter une commande de sortie 
Sortie Add_stc()
{

    Sortie etd;
    client_struct* rech_client;
    Article* rech_article;
    Sortie* sorties;

    time_t seconde;
    struct tm instant;
    time(&seconde);
    instant=*localtime(&seconde);

                FILE* fichier = fopen("les_sorties.txt", "rt");
                if (fichier == NULL) {
                    printf("\nFichier inexistant");
                } else {
                    while (!feof(fichier)) {
                        Sortie sortiess;
                        fscanf(fichier, "%d\n", &sortiess.Code_Art);
                        fscanf(fichier, "%d\n", &sortiess.Qtsortie);
                        if (Rechercher_sortie(liste_sortie,sortiess.Code_Art)!= NULL)
                        {
                            liste_sortie= *Supprimer_sorties(&liste_sortie,sortiess.Code_Art);
                        }
                            liste_sortie = insere_sortie(sortiess, liste_sortie);

                        
                    }
                    
                }
                fclose(fichier);
                //remove("les_sorties.txt");

           /* fichier = fopen("les_sorties.txt", "wt");
                if (fichier == NULL) {
                    printf("\nFichier inexistant");
                } else {
                    fprintf(fichier," ");
                }*/

    // Demander la date de sortie du stock avec contrôle
    etd.date_Sortie_Stock.day=instant.tm_mday;
    etd.date_Sortie_Stock.month=instant.tm_mon+1;
    etd.date_Sortie_Stock.year=instant.tm_year;
    // pour la mesure des essais
    int count =0;
        
        do
        {
        count ++;
        printf("\n Introduire le Code Client: ");
        scanf("%d", &etd.Code_Client);
        rech_client = Rechercher_client(liste_client,etd.Code_Client);
        if (rech_client == NULL){
            printf("*** code client introuvable! ***");
            
        }else break;
        } while (count<3);
        // sortie sans accée
        if (count == 3)
        {
            printf("verifiez vous votre donnes !");
            return empty;
        }
        
        count =0;

        do
        {
        
        printf("\n Introduire le Code article: ");
        scanf("%d", &etd.Code_Art);
        rech_article = rechercher_article(liste_articles,etd.Code_Art);
        if (rech_article == NULL){
            printf("*** code article introuvable! ***");
            count++;
            
        } else{
            rech_article->code_art = etd.Code_Art;
            break;
        } 
        } while (count<3);


        // sortie sans accée
        if (count == 3)
        {
            printf("verifiez vous votre donnes !");
            return empty;
        }

        count =0;

    // Demander le prix unitaire de vente avec contrôle
        do {
            printf("\n Introduire le Prix unitaire de vente: ");
            if (scanf("%f", &etd.Prix_unitaire_de_vente) != 1 || etd.Prix_unitaire_de_vente <= 0) {
                printf("Prix invalide. Veuillez entrer un nombre positif.\n");
                while (getchar() != '\n'); // Vider le buffer
            } else {
                break;
            }
        } while (count<3);

        // sortie sans accée
        if (count == 3)
        {
            printf("verifiez vous votre donnes !");
            return empty;
        }

        count =0;
    // Demander la quantité de sortie avec contrôle

        do {
            count ++;
            printf("\n Introduire la quantité de sortie: ");
            if (scanf("%d", &etd.Qtsortie) != 1 || etd.Qtsortie < 0) {
                printf("Quantité invalide. Veuillez entrer un entier positif.\n");
                while (getchar() != '\n'); // Vider le buffer
                
                

            } 
            else 
            {

                sorties = Rechercher_sortie(liste_sortie, etd.Code_Art);
                if (sorties==NULL){
                    break;
                }
                if (sorties->Qtsortie - rechercher_article(liste_articles,etd.Code_Art)->seuil_stock >= etd.Qtsortie)
                {

                    
                        sorties->Prix_unitaire_de_vente = etd.Prix_unitaire_de_vente;
                        sorties->date_Sortie_Stock = etd.date_Sortie_Stock;
                        sorties->Qtsortie -= etd.Qtsortie;

                        fichier=fopen("les_sorties.txt","wt");
                        if (fichier == NULL) {
                                printf("\nErreur lors de l'ouverture du fichier");
                        }else{
                            Liste_sortie courant = liste_sortie;
                            while (courant != NULL) {
                                fprintf(fichier, "%d\n", courant->valeur_sortie.Code_Art);
                                fprintf(fichier, "%d\n", courant->valeur_sortie.Qtsortie);
                                courant = courant->suivant_sortie;

                                    }
                                    printf(" done saving! \n"); 
                                }fclose(fichier);


                        break;


                }
                else
                {
                    printf("quantité insufisante \n");
                }
                }
            
        } while (count<3);

        // sortie sans accée
        if (count == 3)
        {
            printf("verifiez vous votre donnes !");
            return empty;
        }






return etd;
}


void Gestion_des_sorties()
{

    char rep[4];
    do
    {

        Add_stc();



        printf("\n  Voulez vous ajouter une autre commande : \n");
        scanf("%s", rep);

    }while (strcmp(rep,"oui")==0);




}




void gestion_des_clients()
{


    int choix;
    while (1){
        printf("\n*********\tmenu\t**********");
        printf("\n 1. Ajouter client");
        printf("\n 2. Modifier client ");
        printf("\n 3. Afficher clients ");
        printf("\n 4. Supprimer client ");
        printf("\n 0. Quitter");
        printf("\n*************************\n");
        printf("\n->Introduire votre choix: ");
        scanf("%d", &choix);
        int Id;
        switch (choix)
        {

            case 1:
                {
                    client_struct e;
                    char rep[3]="";
                    do
                    {
                        e = Add_client();
                        liste_client= insere_client(e, liste_client);
                        FILE *logFile = fopen("log.txt", "a");
                        fprintf(logFile, "Client %d added\n", e.code_client);
                        fclose(logFile);
                        printf("\n  Voulez vous ajouter une autre commande :");
                        scanf("%s", rep);

                    }while (strcmp(rep ,"oui")== 0);
                    break;
                }
            case 2:
                {
                    char rep[3];
                    printf("\n Introduire le code du client à modifier: ");
                    scanf("%d",&Id);
                    client_struct* rech_c=Rechercher_client(liste_client, Id);
                    if (rech_c== NULL)
                    {
                        printf("\n Code inexistant !");
                    }
                    else
                    {
                        Affiche_client(*rech_c);
                        printf("\n Etes vous sur de vouloir modifier cet client? ");
                        scanf("%s",rep);
                        if (strcmp(rep,"oui")==0)
                        {
                            Modifier_client(rech_c);
                        }

                    }
                    break;
                }
            case 3:
                {
                    
                    Affiche_list_clients(liste_client);
                    break;
                }
            case 4:
                {
                    printf("\nSaisir le code de l'article à supprimer : ");
                    scanf("%d", &Id);
                    client_struct* rech = Rechercher_client(liste_client, Id);//supprimer_clients
                    if (rech != NULL) {
                        liste_client= *Supprimer_clients(&liste_client,Id);
                    } else {
                        printf("\nClient inexistant\n");
                    }
                    break;
                }
            case 0:
                {

                    return ;
                }
            default:
            {
                printf("\n  choix erronne !! ");
            }

        }
    }
}






void main1_3()

{
    time_t secondes ;
    struct tm instant;

    time(&secondes);
    instant =*localtime(&secondes);

    int choix =0;

    FILE* fichier;





                fichier = fopen("Farticles.txt", "rt");
                if (fichier == NULL) {
                    printf("\nFichier inexistant");
                } else {
                    while (!feof(fichier)) {
                        Article article;
                        fscanf(fichier, "%d\n", &article.code_art);
                        fgets(article.nom_art, 50, fichier);
                        article.nom_art[strcspn(article.nom_art, "\n")] = 0;
                        fgets(article.description, 100, fichier);
                        article.description[strcspn(article.description, "\n")] = 0;
                        fscanf(fichier, "%d\n", &article.seuil_stock);

                        liste_articles = insere(article, liste_articles);
                    }
                    fclose(fichier);
                }


    fich = fopen("backup.txt", "rt");
    if (fich == NULL) {
        printf("Fichier inexistant\n");
    } else {
        while (!feof(fich)) {
            client_struct client;
            char buffer[256]; // Buffer pour lire les chaînes de caractères

            // Lire le code client
            if (fscanf(fich, "%d\n", &client.code_client) == 1) {
                // Lire le nom
                if (fgets(buffer, sizeof(buffer), fich)) {
                    buffer[strcspn(buffer, "\n")] = '\0'; // Supprimer le saut de ligne
                    strncpy(client.Nom, buffer, sizeof(client.Nom) - 1);
                    client.Nom[sizeof(client.Nom) - 1] = '\0'; // Assurer la terminaison
                }

                // Lire l'adresse
                if (fgets(buffer, sizeof(buffer), fich)) {
                    buffer[strcspn(buffer, "\n")] = '\0'; // Supprimer le saut de ligne
                    strncpy(client.Adress, buffer, sizeof(client.Adress) - 1);
                    client.Adress[sizeof(client.Adress) - 1] = '\0'; // Assurer la terminaison
                }

                // Lire le numéro de téléphone
                if (fscanf(fich, "%d\n", &client.Tel) == 1) {

                    // Ajouter le client à la liste
                    if (Rechercher_client(liste_client, client.code_client)==NULL){
                        liste_client = insere_client(client, liste_client);
                    }
                    
                }
            }
        }
        fclose(fich);
        printf("Lecture terminée avec succès !\n");
    }




    while (1)
    {


        printf("\n*************   %d/%d/%d\t %d:%d    *************", instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900,instant.tm_hour,instant.tm_min);
        printf("\n            ****\tmenu\t**** ");
        printf("\n 1. Gestion des clients");
        printf("\n 2. Gestion des sorties des articles du stock ");
        printf("\n 3. Afficher les statistiques de stock");
        printf("\n 0. Quitter");
        printf("\n************************************************** ");
        printf("\n       ->Introduire votre choix: ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
        {
            gestion_des_clients();
            break;
        }
        case 2:
        {
            Gestion_des_sorties();


            break;
        }
        case 3:
        {
            fichier=fopen("les_sorties.txt","r");
            if (fichier == NULL) {
                printf("\nFichier inexistant");
            } else {
                
                int f = 0;
                while (!feof(fichier)) {
                    Sortie sortie;
                    fscanf(fichier, "%d\n", &sortie.Code_Art);
                    fscanf(fichier, "%d\n", &sortie.Qtsortie);
                    
                    printf("produit n'%d : %s \n quantite : %d \n **************\n",f+1,rechercher_article(liste_articles,sortie.Code_Art)->nom_art,sortie.Qtsortie);
                    f++;
                }
                fclose(fichier);
            }
               
            


            printf("**********************\n");
            break;
        }
        case 0:
        {
                        fichier=fopen("backup.txt","wt");
                        if (fichier == NULL) {
                            printf("\nErreur lors de l'ouverture du fichier");
                        } else {
                            struct cellule_client* courant = liste_client;
                            while (courant != NULL) {
                                fprintf(fichier, "%d\n", courant->valeur_client.code_client);
                                fputs(courant->valeur_client.Nom, fichier);
                                fputs("\n", fichier);
                                fputs(courant->valeur_client.Adress, fichier);
                                fputs("\n", fichier);
                                fprintf(fichier, "%d\n", courant->valeur_client.Tel);
                                courant = courant->suivant_client;
                            }
                            
                        }fclose(fichier);

            return ;
        }
        default:
        {
            printf("\n choix erronee");
            break;
        }



    }

}
}


/*


                    fichier=fopen("les_sorties.txt","a");
                    if (fichier == NULL) {
                        printf("\nErreur lors de l'ouverture du fichier");
                    Liste_sortie courant = liste_sortie;
                    while (courant != NULL) {
                        fprintf(fichier, "%d\n", courant->valeur_sortie.Code_Art);
                        fprintf(fichier, "%d\n", courant->valeur_sortie.Qtsortie);
                        courant = courant->suivant;

                        }
                        fclose(fichier);
                    
                    printf(" done saving! \n"); 
                    fclose(fich);
                    */