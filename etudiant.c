#include "etudiant.h"
#include<stdio.h>
#include<string.h>

Etudiant Saisir_etd()
{
    Etudiant etd;
    printf("\n introduire l'identidiant: ");
    scanf("%d", &etd.identifiant);
    printf("\n introduire le nom: ");
    scanf("%s", &etd.Nom);
    printf("\n introduire le prenom: ");
    scanf("%s", &etd.Prenom);
    for (int i=0;i<4;i++)
    {
        printf("Note[%d]= ",i);
        scanf("%f", &etd.Notes[i]);
    }
    return etd;
}
void Saisir_Tab_Etd(Etudiant Tab[], int* N)
{
    Etudiant e;
    int i;
    char rep[3];
    i = *N;
    do
    {
        e =Saisir_etd();
        Tab[i]=e;
        i++;
        printf("\n Voulez vous ajouter un autre etudiant ");
        scanf("%s",&rep);

    }while (strcmp(rep, "oui")==0);
    *N=i;
}
void Affiche_etd(Etudiant e)
{
    printf("\n ******\n identifiant : %d", e.identifiant);
    printf("\n nom: %s", e.Nom);
    printf("\n prenom: %s", e.Prenom);
    for (int j = 0; j < 4; j++)
    {
        printf("\n notes[%d]=%f",j,e.Notes[j]);

    }
    
}
void Affiche_Tab_etd(Etudiant Tab[], int N)
{ 
    int i ;
    for (i=0;i<N;i++)
    {
        Affiche_etd(Tab[i]);
    }

}

int Rechercher_Etd(Etudiant Tab[], int N,int ident)
{
    for(int i=0;i<N; i++){
        if(Tab[i].identifiant==ident){
            return i;
        }
    }
    
            
    return -1;
}