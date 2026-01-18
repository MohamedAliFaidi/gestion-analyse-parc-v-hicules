#include "vehicule.h"
#include <stdio.h>

#define MAX_VEHICULES 100

int main() {
  int n;
  Vehicule parc[MAX_VEHICULES];
  int idxMeilleur, idxMoinsRentable;

  do {
    printf("Nombre de véhicules à saisir (1-%d): ", MAX_VEHICULES);
    scanf("%d", &n);
  } while (n <= 0 || n > MAX_VEHICULES);

  Saisie_Vehicules(parc, n);

  Calcul_Benefices(parc, n);

  Analyse_Performance(parc, n, &idxMeilleur, &idxMoinsRentable);

  printf("\n--- Liste des véhicules par bénéfice décroissant ---\n");
  Affiche_Vehicules(parc, n);

  printf("\nVéhicule le plus rentable:\n");
  Affiche_Vehicule(parc[idxMeilleur]);

  printf("Véhicule le moins rentable:\n");
  Affiche_Vehicule(parc[idxMoinsRentable]);

  printf("\nBénéfice total: %.2f euros\n", Benefice_Total(parc, n));

  return 0;
}
