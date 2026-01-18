#include <stdio.h>
#include "vehicule.h"

#define MAX_VEHICULES 100

int main(){
    int n; Vehicule parc[MAX_VEHICULES];
    do{printf("Nombre de véhicules (1-%d): ",MAX_VEHICULES); scanf("%d",&n);}while(n<=0||n>MAX_VEHICULES);
    Saisie_Vehicules(parc,n);
    Calcul_Benefices(parc,n);
    Analyse_Performance(parc,n);
    printf("\n--- Véhicules par bénéfice décroissant ---\n"); Affiche_Vehicules(parc,n);
    printf("\nLe plus rentable:\n"); Affiche_Vehicule(parc[0]);
    printf("Le moins rentable:\n"); Affiche_Vehicule(parc[n-1]);
    printf("\nBénéfice total: %.2f\n",Benefice_Total(parc,n));
    return 0;
}
