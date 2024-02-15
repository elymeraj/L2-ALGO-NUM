#include <stdio.h>
#include <stdlib.h>

#ifndef INTERPOLATION
#define INTEPOLATION

/******************************************************************************************
    Lagrange: Fonction qui implemente la methode d'interpolation de Lagrange

    entree: un tableau x et un tableau y de dimension 1 qu'ils prennent les valeurs de points 
            testees, la coordonnee x pour que fonction  nous retourne P(X) = y et n-> nombre 
            de points qu'on teste.

    sortie: La fonction va retourner la valeur de polynome P pour les points testees.

********************************************************************************************/

double Lagrange(double *x, double *y, double X, int n){
    double L;
    double P = 0;
    //calcul de Li(x)
    for (int i = 0; i < n; i++){
        L = 1;
        for (int j = 0; j < n; j++){
            if (j != i)
            {
                L = L*((X - x[j]) / (x[i] - x[j]));

            }
            
        }
        //calcul du polynome
        P = P + y[i]* L;

    }
    printf("Par la methode d'interpolation de Lagrange f(x) = %.5f\n\n",P);
    return (P);
}
/******************************************************************************************
    Neville: Fonction qui implemente la methode d'interpolation de Neville.

    entree: un tableau x et un tableau y de dimension 1 qu'ils prennent les valeurs de points 
            testees, la coordoneee x pour que fonction  nous retourne P(X) = y et n-> nombre 
            de points qu'on teste.

    sortie: La fonction va retourner la valeur de polynome P pour les points testees.

********************************************************************************************/

double  Neville (double *x, double *y, double X, int n)
{
    
    double  * P1=malloc(n*sizeof(double)),
            * P0=malloc(n*sizeof(double));
    P0=y;
    for(int k=1;k<n-1;k++)
    {
        for(int i=0;i<n-k;i++)
        {
            P1[i]=((X-x[i+k])*P0[i]+(x[i]-X)*P0[i+1])/(x[i]-x[i+k]);
            
        }

        P0=P1;
    }  
    printf("Par la methode d'interpolation de Neville, f(x) = %.5f\n", P1[0]);
    return P1[0];
}


#endif