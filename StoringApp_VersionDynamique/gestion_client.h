#ifndef GESTION_DES_CLIENTS
#define GESTION_DES_CLIENTS



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
}client_struct;



struct cellule_client
{
    client_struct valeur_client;
    struct cellule_client* suivant_client;
};
typedef struct cellule_client *Liste_client;


struct cellule_sortie
{
    Sortie valeur_sortie;
    struct cellule_sortie *suivant_sortie;
};
typedef struct cellule_sortie *Liste_sortie;




client_struct* Rechercher_client(Liste_client Lst, int ident);

Sortie* Rechercher_sortie(Liste_sortie Lst, int ident);

Sortie Add_stc();

client_struct Add_client();

void Affiche_client(client_struct e);

void Affiche_list_clients(Liste_client Lst);
void gestion_des_clients();
void Gestion_des_sorties();
void Modifier_client(client_struct *rech);
Liste_sortie* Supprimer_sorties(Liste_sortie *Lst,int code);
Liste_client* Supprimer_clients(Liste_client *Lst,int code);

void main1_3();
Liste_client insere_client(client_struct element, Liste_client Lst);
Liste_sortie insere_sortie(Sortie element, Liste_sortie Lst);
extern Liste_sortie liste_sortie;
extern Liste_client liste_client;

#endif

