#ifndef GESTIONNEUR
#define GESTIONNEUR

typedef struct Gst {
    int Code_Art;
    char Nom_Art[25];
    char Description[25];
    float Seuil_stock[4];
}Gst;

Gst Gestion_des_Articles();

void Gestion_des_Entrées_en_stock();

void Gestion_des_Sorties_du_stock();

void quitter();








#endif