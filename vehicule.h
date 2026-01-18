#ifndef VEHICULE_H
#define VEHICULE_H

#define MAX_STRING 50

typedef struct {
  char immatriculation[MAX_STRING];
  char marque[MAX_STRING];
  int annee;
  double prixParJour;
  int joursLoues;
  double coutMaintenance;
  double benefice;
} Vehicule;

Vehicule Saisie_Vehicule(Vehicule parc[], int nVehiculesExistants);
void Saisie_Vehicules(Vehicule parc[], int n);
double Revenu_Vehicule(Vehicule v);
double Benefice_Vehicule(Vehicule v);
void Calcul_Benefices(Vehicule parc[], int n);
double Benefice_Total(Vehicule parc[], int n);
void Analyse_Performance(Vehicule parc[], int n);
void Affiche_Vehicule(Vehicule v);
void Affiche_Vehicules(Vehicule parc[], int n);
void Trier_Vehicules_Par_Benefice(Vehicule parc[], int n);

#endif
