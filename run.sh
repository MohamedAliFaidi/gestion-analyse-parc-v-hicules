#!/bin/bash


rm -f *.o gestion_parc

echo "Compilation de vehicule.c..."
gcc -c vehicule.c -o vehicule.o

echo "Compilation de main.c..."
gcc -c main.c -o main.o

echo "Linking..."
gcc main.o vehicule.o -o gestion_parc

# Vérifier si l'exécutable a été créé avec succès
if [ -f "./gestion_parc" ]; then
    echo "Compilation réussie !"
    echo "Exécution du programme..."
    ./gestion_parc
else
    echo "Erreur de compilation."
fi
