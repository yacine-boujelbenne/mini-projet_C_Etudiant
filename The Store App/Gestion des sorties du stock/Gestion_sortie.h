#ifndef GESTION_DES_SORTIES
#define GESTION_DES_SORTIES

typedef struct {
    int day;
    int month;
    int year;
} date;


typedef struct
{
    int Code_Client;
    int Code_Art;
    float Prix_unitaire_de_vente;
    int Qtsortie;
    date date_Sortie_Stock;

}Sortie;

typedef struct clt{

int code_client;

char Nom[100];
char Adress[100];
int Tel;
}cortie;

Sortie Add_stc();

cortie Add_client();
void Affiche_client(cortie e);
int Rechercher_client(cortie Tab[], int N,int ident);
void Affiche_liste_clients(cortie Tab[], int N);
void gestion_des_clients(cortie stc[], int* N);
void Gestion_des_sorties(Sortie stc[], int* N);
void Modifier_client(cortie Tab[], int rech );
void Supprimer_clients(cortie tab_client[],int* N , int rech);
void Afficher_Stats();







#endif