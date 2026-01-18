#include <stdio.h>
#include <string.h>
#include "vehicule.h"

double Revenu_Vehicule(Vehicule v){return v.prixParJour*v.joursLoues;}
double Benefice_Vehicule(Vehicule v){return Revenu_Vehicule(v)-v.coutMaintenance;}

Vehicule Saisie_Vehicule(Vehicule parc[], int nVehiculesExistants){
    Vehicule v;
    int unique;
    do{
        unique=1;
        printf("Immatriculation: ");
        scanf("%49s", v.immatriculation);
        for(int i=0;i<nVehiculesExistants;i++)
            if(strcmp(v.immatriculation,parc[i].immatriculation)==0){printf("Déjà existante\n");unique=0;break;}
    }while(!unique);
    printf("Marque: "); scanf("%49s",v.marque);
    do{printf("Année: "); scanf("%d",&v.annee);}while(v.annee<1900||v.annee>2100);
    do{printf("Prix/jour: "); scanf("%lf",&v.prixParJour);}while(v.prixParJour<=0);
    do{printf("Jours loués: "); scanf("%d",&v.joursLoues);}while(v.joursLoues<0||v.joursLoues>365);
    do{printf("Coût maintenance: "); scanf("%lf",&v.coutMaintenance);}while(v.coutMaintenance<0);
    v.benefice=Benefice_Vehicule(v); return v;
}

void Saisie_Vehicules(Vehicule parc[], int n){for(int i=0;i<n;i++) parc[i]=Saisie_Vehicule(parc,i);}
void Calcul_Benefices(Vehicule parc[], int n){for(int i=0;i<n;i++) parc[i].benefice=Benefice_Vehicule(parc[i]);}

void Trier_Vehicules_Par_Benefice(Vehicule parc[], int n){
    for(int i=0;i<n-1;i++){
        int idxMax=i;
        for(int j=i+1;j<n;j++) if(parc[j].benefice>parc[idxMax].benefice) idxMax=j;
        if(idxMax!=i){Vehicule tmp=parc[i];parc[i]=parc[idxMax];parc[idxMax]=tmp;}
    }
}

void Analyse_Performance(Vehicule parc[], int n){Trier_Vehicules_Par_Benefice(parc,n);}
void Affiche_Vehicule(Vehicule v){printf("%s %s %d %.2f %d %.2f %.2f\n",v.immatriculation,v.marque,v.annee,v.prixParJour,v.joursLoues,v.coutMaintenance,v.benefice);}
void Affiche_Vehicules(Vehicule parc[], int n){for(int i=0;i<n;i++){printf("%d: ",i+1);Affiche_Vehicule(parc[i]);}}
double Benefice_Total(Vehicule parc[], int n){double t=0;for(int i=0;i<n;i++) t+=parc[i].benefice; return t;}
