#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "approximation.h"
#include "util.h"


int main()
{
    double a1, b1;
    double a2, b2;
    double a3, b3;
    double a4, b4;

    //4.1
    
    int     n1 = 20;
    double  *T = malloc(n1*sizeof(double));
    double  *DENS = malloc(n1*sizeof(double));

    T[0]=0;     DENS[0]=0.99987;
    T[1]=2;     DENS[1]=0.99997;
    T[2]=4;     DENS[2]=1.00000;
    T[3]=6;     DENS[3]=0.99997;
    T[4]=8;     DENS[4]=0.99988;
    T[5]=10;    DENS[5]=0.99973;
    T[6]=12;    DENS[6]=0.99953;
    T[7]=14;    DENS[7]=0.99927;
    T[8]=16;    DENS[8]=0.99897;
    T[9]=18;    DENS[9]=0.99846;
    T[10]=20;   DENS[10]=0.99805;
    T[11]=22;   DENS[11]=0.999751;
    T[12]=24;   DENS[12]=0.99705;
    T[13]=26;   DENS[13]=0.99650;
    T[14]=28;   DENS[14]=0.99664;
    T[15]=30;   DENS[15]=0.99533;
    T[16]=32;   DENS[16]=0.99472;
    T[17]=34;   DENS[17]=0.99472;
    T[18]=36;   DENS[18]=0.99333;
    T[19]=38;   DENS[19]=0.99326;

    linaire(T,DENS,&a1,&b1,n1);
    printf("==============================Jeu d'essai 4.1=============================\n");
    affCoord(T, DENS, n1);
    printf("a1 = %f\n", a1);
    printf("b1 = %f\n", b1);
    printf("La droite de regression lineaire est f(x) = %f*X+ %f\n",a1,b1);
    printf("\n\n");
    
    //4.2
    
    int n2 = 21;
    double * R;
    double * D;
    R = malloc(n2*sizeof(double));
    D = malloc(n2*sizeof(double));

    R[0]  = 752;     D[0]  = 85;
    R[1]  = 855;     D[1]  = 83;
    R[2]  = 871;     D[2]  = 162;
    R[3]  = 734;     D[3]  = 79;
    R[4]  = 610;     D[4]  = 81;
    R[5]  = 582;     D[5]  = 83;
    R[6]  = 921;     D[6]  = 281;
    R[7]  = 492;     D[7]  = 81;
    R[8]  = 569;     D[8]  = 81;
    R[9]  = 462;     D[9]  = 80;
    R[10] = 907;     D[10] = 243;
    R[11] = 643;     D[11] = 84;
    R[12] = 862;     D[12] = 84;
    R[13] = 524;     D[13] = 82;
    R[14] = 679;     D[14] = 80;
    R[15] = 902;     D[15] = 226;
    R[16] = 918;     D[16] = 260;
    R[17] = 828;     D[17] = 82;
    R[18] = 875;     D[18] = 186;
    R[19] = 809;     D[19] = 77;
    R[20] = 894;     D[20] = 223;
    

    linaire(R,D,&a2,&b2,n2);
    printf("==============================Jeu d'essai 4.2=============================\n");
    affCoord(R, D, n2);
    printf("a2 = %f\n", a2);
    printf("b2 = %f\n", b2);
    printf("La droite de regression lineaire est f(x) = %f*X + (%f)\n", a2, b2);
    printf("\n\n");
    //4.3
    
    int n3 = 11;
    double * x = NULL;
    double * y = NULL;
    x = malloc(n3*sizeof(double));
    y = malloc(n3*sizeof(double));

    x[0]  = 10;     y[0]  = 8.04;
    x[1]  =  8;     y[1]  = 6.95;
    x[2]  = 13;     y[2]  = 7.58;
    x[3]  =  9;     y[3]  = 8.81;
    x[4]  = 11;     y[4]  = 8.33;
    x[5]  = 14;     y[5]  = 9.66;
    x[6]  =  6;     y[6]  = 7.24;
    x[7]  =  4;     y[7]  = 4.26;
    x[8]  = 12;     y[8]  = 10.84;
    x[9]  =  7;     y[9]  = 4.82;
    x[10] =  5;     y[10] = 5.68;

    linaire(x,y,&a3,&b3,n3);
    printf("==============================Jeu d'essai 4.3=============================\n");
    affCoord(x, y, n3);
    printf("a3 = %f\n", a3);
    printf("b3 = %f\n", b3);
    printf("La droite de regression lineaire est f(x) = %f*X + %f\n", a3, b3);
    printf("\n\n");
    
    
    int n4 =7;
    double * X = NULL;
    double * Y = NULL;
    X = malloc(n4*sizeof(double));
    Y = malloc(n4*sizeof(double));

    X[0]  = 20;     Y[0]  = 352;
    X[1]  = 30;     Y[1]  = 128;
    X[2]  = 40;     Y[2]  = 62.3;
    X[3]  = 50;     Y[3]  = 35.7;
    X[4]  = 100;    Y[4]  = 6.3;
    X[5]  = 300;    Y[5]  = 0.4;
    X[6]  = 500;    Y[6]  = 0.1;

    
    puis(X, Y, &a4, &b4, n4);
    printf("==============================Jeu d'essai 4.4===========================\n");
    affCoord(X, Y, n4);
    printf("Pour l'ajustement de type y=ax^b:\n");
    printf("a4 = %f\n", a4);
    printf("b4 = %f\n", b4);
    printf("La droite de regression puissance est f(x) = %f*X^(%f)\n", a4, b4);
    


    free(T);
    free(DENS);
    free(R);
    free(D);
    free(x);
    free(y);
    free(X);
    free(Y);
    return 0;
}
