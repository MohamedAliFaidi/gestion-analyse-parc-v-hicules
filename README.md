# Schéma global d’exécution de l’application (langage C)

```
┌──────────────────────────┐
│        main()            │
│ (point d’entrée)         │
└────────────┬─────────────┘
             ↓
┌──────────────────────────┐
│ Saisie du nombre de       │
│ véhicules (n)             │
└────────────┬─────────────┘
             ↓
┌──────────────────────────┐
│ Saisie_Vehicules(parc,n) │
│ Remplit le tableau parc  │
└────────────┬─────────────┘
             ↓
┌──────────────────────────┐
│ Calcul_Benefices(parc,n) │
│ Appelle Benefice_Vehicule│
└────────────┬─────────────┘
             ↓
┌──────────────────────────┐
│ Analyse_Performance()    │
│ Tri par bénéfice         │
└────────────┬─────────────┘
             ↓
┌──────────────────────────┐
│ Affiche_Vehicules(parc)  │
│ + plus rentable          │
│ + moins rentable         │
└────────────┬─────────────┘
             ↓
┌──────────────────────────┐
│ Benefice_Total(parc,n)   │
│ Somme des bénéfices      │
└──────────────────────────┘
```

---

## Détail interne des appels de fonctions

```
Saisie_Vehicules()
│
├─ parc[0] ← Saisie_Vehicule()
├─ parc[1] ← Saisie_Vehicule()
├─ ...
└─ parc[n-1] ← Saisie_Vehicule()
```

```
Saisie_Vehicule()
│
├─ Saisie + contrôle des données
├─ Revenu_Vehicule()
│   └─ prixParJour × joursLoues
└─ Benefice_Vehicule()
    └─ revenu − coûtMaintenance
```

```
Analyse_Performance()
│
└─ Trier_Vehicules_Par_Benefice()
    └─ Classement décroissant
```

---

## Rôle du fichier vehicule.h dans le schéma

```
vehicule.h
│
├─ Déclare la structure Vehicule
└─ Déclare les prototypes de fonctions
```

Il permet à main.c de savoir quelles fonctions existent et comment les utiliser,
et à vehicule.c de définir ces fonctions correctement.

---

## Résumé visuel

Entrée utilisateur → Traitement → Analyse → Affichage

Ce schéma montre clairement l’ordre d’exécution et le rôle de chaque partie du code.


