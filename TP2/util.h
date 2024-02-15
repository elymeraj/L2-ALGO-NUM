#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef UTIL
#define UTIL


/******************************************************************************************
    affCoord: Fonction qui affiche les coordonnees de tout nos points.

    entree: un tableau x et un tableau y de dimension 1 qu'ils prennent les valeurs de points 
            testees,  et n-> nombre de points qu'on teste.
            
    sortie: La fonction va retourner rien car il est de type void.

********************************************************************************************/


void affCoord(double *x, double *y, int n)
{
    if(n > 1 && x != NULL && y != NULL)
    {
        printf("Coordonnees (x, y):\n");
        for(int i =0; i<n; i++)
        {
            printf("|%+010.5f, %+010.5f|\n", x[i], y[i]);
        }
        printf("\n");
    }
    else
    {
        printf("ERROR");
        exit(-1);
    }
}

#endif