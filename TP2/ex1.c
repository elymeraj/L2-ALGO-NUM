#include <stdlib.h>
#include <stdio.h>

#include "interpolation.h"
#include "util.h"

int main(){
    
    double P;
    double P1;

    // 4.1
    /*
    int     n = 20;
    int     temp;
    double  *T = malloc(n*sizeof(double));
    double  *D = malloc(n*sizeof(double));

    printf("Entrez la temperature T : ");
    scanf("%d",&temp);


    T[0]=0;     D[0]=0.99987;
    T[1]=2;     D[1]=0.99997;
    T[2]=4;     D[2]=1.00000;
    T[3]=6;     D[3]=0.99997;
    T[4]=8;     D[4]=0.99988;
    T[5]=10;    D[5]=0.99973;
    T[6]=12;    D[6]=0.99953;
    T[7]=14;    D[7]=0.99927;
    T[8]=16;    D[8]=0.99897;
    T[9]=18;    D[9]=0.99846;
    T[10]=20;   D[10]=0.99805;
    T[11]=22;   D[11]=0.999751;
    T[12]=24;   D[12]=0.99705;
    T[13]=26;   D[13]=0.99650;
    T[14]=28;   D[14]=0.99664;
    T[15]=30;   D[15]=0.99533;
    T[16]=32;   D[16]=0.99472;
    T[17]=34;   D[17]=0.99472;
    T[18]=36;   D[18]=0.99333;
    T[19]=38;   D[19]=0.99326;

    P = Lagrange(T, D, temp, n);
    P1 = Neville(T, D, temp, n);
    */

    //4.2
    /*
    int n = 21;
    int r;
    printf("entrez la valeur de r : ");
    scanf("%d",&r);
    double * R = NULL;
    double * D = NULL;
    R = malloc(n*sizeof(double));
    D = malloc(n*sizeof(double));

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

    P  = Lagrange(R, D, r, n);
    P1 = Neville(R, D, r, n);
 
    free(R);
    free(D);
    */

    //4.3
    
    int n = 11;
    int X;
    //printf("entrez la valeur de X : ");
    //scanf("%d",&X);
    double * x = NULL;
    double * y = NULL;
    x = malloc(n*sizeof(double));
    y = malloc(n*sizeof(double));
    
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
    
    P = Lagrange(x, y, X, n);
    P1 = Neville(x, y, X, n);
    
    
    return 0;
}