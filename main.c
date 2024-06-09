#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/init.h"

int main()
    {
        printf("\n--- Introduction to the Theory of compilers ----\n \n");
        printf("This is a series of custom implementation of Compilers Theory Algorithms related to Automaton \n");

        // Création des états
        Etat *e0 = createEtat(0, true, false);
        Etat *e1 = createEtat(1, false, false);
        Etat *e2 = createEtat(2, false, true);

        // Ajout des transitions

        Automate *automate = createAutomate(3);
        ajouteEtatRecursif(automate, e0);
        ajouteEtatRecursif(automate, e1);
        ajouteEtatRecursif(automate, e2);

        ajouteTransition(e0, 'a', e1);
        ajouteTransition(e0, 'v', e2);
        ajouteTransition(e0, 'a', e0);

        ajouteTransition(e1, 'b', e2);
        ajouteTransition(e2, 'c', e0);

        // Création de l'automate
       

        // Test de la déterminisation
        if (estDeterministe(automate))
        {
            printf("L'automate est déterministe.\n");
            printAutomate(automate);
        }
        else
        {
            printf("L'automate n'est pas déterministe.\n");
            printAutomate(automate);
        }

        return 0;
    }