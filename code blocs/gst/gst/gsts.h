#ifndef GESTION_DES_SORTIES
#define GESTION_DES_SORTIES


typedef struct clt{

int code_client;



char Nom[100];
char Adress[100];
int Tel;
}Sortie;


Sortie Add_client();

void gestion_des_clients(Sortie stc[], int* N);


void Gestion_des_sorties(Sortie stc[], int* N);




#endif // GESTION_DES_SORTIES
