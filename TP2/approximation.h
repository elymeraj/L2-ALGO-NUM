#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef APPROX
#define APPROX

/******************************************************************************************
    lineaire: Fonction qui permet de nous afficher la droite de regression lineaire.

    entree: un tableau x et un tableau y de dimension 1 qu'ils prennent les valeurs de points 
            testees, deux pointeures a, b de type double et n le nombre de points testees.

    sortie: La fonction va nous retourner rien car il est de type void.

********************************************************************************************/

void linaire (double *x ,double *y ,double* a,double* b, int n)
{
    double as1 = 0;
    double as2 = 0;
    double      as;
    double      bs;
    double  xB = 0;
    double  yB = 0;

    for(int i = 0;i < n; i++)
    {
        xB+= x[i]; //calcul de X barre
        yB+= y[i]; //calcul de Y barre
    }

    for(int i=0;i<n;i++)
    {
        as1+= (x[i] - xB/n)*(y[i] - yB/n); //calcul du nominateur de a
        as2+= (x[i]- xB/n)*(x[i] - xB/n); //calcul du d�nominateur de a
    }
    as = as1/as2;
    bs = yB/n - as*(xB/n);

    *a = as;
    *b = bs;
}

/******************************************************************************************
    puiss : Fonction qui realise l'ajustement puissance de type y = a*x^b.

    entree: un tableau x et un tableau y de dimension 1 qu'ils prennent les valeurs de points 
            testees, deux pointeures a, b de type double et n le nombre de points testees.

    sortie: La fonction va nous retourner rien car il est de type void.

********************************************************************************************/

void puis(double *x, double *y, double *a, double* b, int n ){
    double as1 = 0;
    double as2 = 0;
    double      as;
    double      bs;
    double  xB = 0;
    double  yB = 0;
    //on remplace x par ln(x)
    //on remplace y par ln(y)
    for(int i=0;i<n;i++)
    {
        xB += log(x[i]); //somme de ln(x[i])
        yB += log(y[i]); // somme de ln(y[i])
    }
    for(int i=0;i<n;i++)
    {
        as1+= (log(x[i]) - xB/n)*(log(y[i]) - yB/n);
        as2+= (log(x[i]) - xB/n)*(log(x[i]) - xB/n);

    }
    printf("as1 = %f\n", as1);
    printf("as2 = %f\n", as2);
    as = as1/as2;
    bs = yB/n-as*(xB/n);
    bs = exp(bs); //on remplace b par e^b
    *a = bs;
    *b = as;
}


#endif