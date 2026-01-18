#include "vehicule.h"
#include <stdio.h>

// Calcul du revenu
double Revenu_Vehicule(Vehicule v) { return v.prixParJour * v.joursLoues; }

// Calcul du bénéfice
double Benefice_Vehicule(Vehicule v) {
  return Revenu_Vehicule(v) - v.coutMaintenance;
}

// Saisie d'un véhicule
Vehicule Saisie_Vehicule() {
  Vehicule v;

  printf("\n--- Saisie d'un véhicule ---\n");

  printf("Immatriculation: ");
  scanf("%49s", v.immatriculation);

  printf("Marque: ");
  scanf("%49s", v.marque);

  printf("Année: ");
  while (scanf("%d", &v.annee) != 1 || v.annee < 1900 || v.annee > 2100) {
    printf("Année invalide. Recommencez: ");
    while (getchar() != '\n')
      ;
  }

  do {
    printf("Prix par jour (>0): ");
    scanf("%lf", &v.prixParJour);
  } while (v.prixParJour <= 0);

  do {
    printf("Jours loués (0-365): ");
    scanf("%d", &v.joursLoues);
  } while (v.joursLoues < 0 || v.joursLoues > 365);

  do {
    printf("Coût de maintenance (>=0): ");
    scanf("%lf", &v.coutMaintenance);
  } while (v.coutMaintenance < 0);

  v.benefice = Benefice_Vehicule(v);
  return v;
}

// Saisie de n véhicules
void Saisie_Vehicules(Vehicule parc[], int n) {
  for (int i = 0; i < n; i++)
    parc[i] = Saisie_Vehicule();
}

// Calcul des bénéfices
void Calcul_Benefices(Vehicule parc[], int n) {
  for (int i = 0; i < n; i++)
    parc[i].benefice = Benefice_Vehicule(parc[i]);
}

// Tri par bénéfice décroissant
void Trier_Vehicules_Par_Benefice(Vehicule parc[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int idxMax = i;
    for (int j = i + 1; j < n; j++) {
      if (parc[j].benefice > parc[idxMax].benefice)
        idxMax = j;
    }
    if (idxMax != i) {
      Vehicule temp = parc[i];
      parc[i] = parc[idxMax];
      parc[idxMax] = temp;
    }
  }
}

// Analyse performance : tri + meilleur/pire
void Analyse_Performance(Vehicule parc[], int n, int *idxMeilleur,
                         int *idxMoinsRentable) {
  Trier_Vehicules_Par_Benefice(parc, n);
  *idxMeilleur = 0;
  *idxMoinsRentable = n - 1;
}

// Affichage
void Affiche_Vehicule(Vehicule v) {
  printf("Immatriculation: %s, Marque: %s, Année: %d, Prix/jour: %.2f, Jours "
         "loués: %d, Coût maintenance: %.2f, Bénéfice: %.2f\n",
         v.immatriculation, v.marque, v.annee, v.prixParJour, v.joursLoues,
         v.coutMaintenance, v.benefice);
}

void Affiche_Vehicules(Vehicule parc[], int n) {
  for (int i = 0; i < n; i++) {
    printf("Véhicule %d: ", i + 1);
    Affiche_Vehicule(parc[i]);
  }
}

// Bénéfice total
double Benefice_Total(Vehicule parc[], int n) {
  double total = 0;
  for (int i = 0; i < n; i++)
    total += parc[i].benefice;
  return total;
}
