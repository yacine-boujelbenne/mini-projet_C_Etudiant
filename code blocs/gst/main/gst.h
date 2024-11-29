#ifndef GESTION_DES_SORTIES
#define GESTION_DES_SORTIES

typedef struct gsts
{
    int Code_Client;
    int Code_Art;
    float Prix_unitaire_de_vente;
    int Qtsortie;
    Date Date_Sortie_Stock;

}Sortie;

typedef struct Date{
    int jour;
    int mois;
    int annee;
}Date;

Sortie Add_stc();


void gestion_des_clients();
void Gestion_des_sorties(Sortie stc[], int* N);
void Afficher_Stats();







#endif
