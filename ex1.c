#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/***********************Rappel rapide - methode de Gauss Simple*****************************

La méthode de Gauss consiste à transformer le système linéaire Ax = b en un système linéaire 
équivalent  A’x = b’  ayant la  même  solution  et tel  que A’ soit triangulaire supérieure.
Anotre  cas, on  prends la  solution  x = 1 et  il faut qu'on trouve et afficher la matrice 
triangulaire et le vecteur B pour qu'elle la solution est egal a x[i] =1.

********************************************************************************************/


/******************************************************************************************
    allouerMat: Alloue la memoire pour les matrices qu'on va utiliser

    entrée: dimensions de matrice

    sortie: La fonction retourne notre matrice
            si la matric est NULLE, la fonction va retourner rien

********************************************************************************************/

float ** allouerMat(int n, int m)
{
    n = m;
    int i;
    float ** mat = NULL;
    mat = malloc(n*sizeof(float *));
    if(mat == NULL){return NULL;}

    for(i=0;i<n;i++)
    {
        mat[i] = NULL;
        mat[i] = malloc(n *sizeof(float));
        if (mat[i] == NULL)
           {
               printf("erreur d'allocation");
            
            return NULL;}
    }
    return mat;
}

/******************************************************************************************
    entrerMatrice: Fonction qui demande à l'utilisateur d'entrer la matrice qui va tester

    entrée: Matrice test et ses dimensions

    sortie: La fonction va retourner rien.

********************************************************************************************/

void entrerMatrice(float **A, int n, int m)
{
   printf("Entrez les valeurs de notre matrice : \n");
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%f", &A[i][j]);
        }
    } 
}  

/******************************************************************************************
    affMat: Fonction qui fait l'affichage de la matrice 

    entrée: La matrice qu'on va afficher et ses dimensions

    sortie: La fonction va retourner rien.

********************************************************************************************/

void affMat(float **A, int n, int m){
    
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%.2f \t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/******************************************************************************************
    TriangGauss: Fonction qui permet de nous triangulariser la matrice entrant avec la 
                 méthode de Gauss.

    entrée: La matrice test et ses dimensions

    sortie: La fonction va nous retourner rien.

********************************************************************************************/

void TriangGauss(float **A,  int n, int m ){


	float pivot = 0 ;
	for (int k = 0; k <= n-1; k++){	
		for(int i = k+1; i < n; i++){	
			pivot = (A[i][k]/A[k][k]);
			for (int j = k; j < n; j++){
				A[i][j]-= pivot * A[k][j];
            }

        }
			             
	}

} 

/******************************************************************************************
    trouveB: Fonction qui permet de nous trouver la matrice B qui est de dimension 3x1. 
             Le vecteur B  est  choisie de  sorte que  la  solution  exacte  du système 
             d’équations est x[i]=1, pour i =1,...,n.

    entrée: La matrice test et ses dimensions

    sortie: La fonction va nous retourner le vecteur trouvée B.

********************************************************************************************/

float ** trouveB(float **mat, int n, int m)
{
    
    float **B=allouerMat(1,3);
    
    for(int i = 0; i < n; i++)
    {
        B[i][0] = 0;
       
        for(int j = 0; j < m; j++)
        {
            
            B[i][0]+= mat[i][j];
        }
    }
    
    return B;
}

/******************************************************************************************
    remplMatA5: Fonction qui permet de remplir la matrice test A5 en suivant la régle 
                donnée.

    entrée: La matrice test et la dimension n

    sortie: La fonction va nous retourner rien.

********************************************************************************************/

void remplMatA5(float ** A5, int n){
    int i, j;
    for(i = 0; i < n; i++)
    {
        A5[i][i] = 1;
    }
    for(j = 1; j < n; j++)
    {
        A5[1][j] = A5[j][1] = 1/((float)pow(2,(float)j)); //ici le pow permet de mettre 2 à la puissance j
    }
}

/******************************************************************************************
    remplMatA6: Fonction qui permet de remplir la matrice test A6 en suivant la régle 
                donnée.

    entrée: La matrice test et la dimension n

    sortie: La fonction va nous retourner rien.

********************************************************************************************/

//Fonction pour remplir la matrice A6 avec le regle donnee 
void remplMatA6(float **A6, int n)
{
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                A6[i][j]=3;
            }
            else if(j==i+1 && i<n)
            {
                A6[i][j]=-1;
            }
            else if(j==i-1 && i>1)
            {
                A6[i][j]=-2;
            }else
            {
                A6[i][j]=0;
            }
        }
    }
    
}



/*********************************************MAIN***************************************************************/


int main()
{
    int n,m; n=3; m=3; //initialisation n = m car on manipule des matrices carree 
    /*
    printf("\n================MATRICE TEST A1===============\n");
    // POUR MATRICE TEST A1
    float **A1 = allouerMat(3,3);
    entrerMatrice(A1, n, m);
    printf("Notre matrice A1 avant la triangularisation est: \n");
    affMat(A1, n, m);
    printf("Notre matrice A1 apres la triangularisation est : \n");
    TriangGauss(A1, n, m);
    affMat(A1, n, m);
    float **B1 = allouerMat(1,3);
    B1 = trouveB(A1, n, m);
    printf("La matrice B1 pour que xi est toujours egal a 1 est : \n");
    affMat(B1, 3, 1);


    printf("\n\n================MATRICE TEST A2===============\n\n");
    // POUR MATRICE TEST A2
    float **A2 = allouerMat(3,3);
    entrerMatrice(A2, n, m);
    printf("Notre matrice A2 avant la triangularisation est: \n");
    affMat(A2, n, m);
    printf("Notre matrice A2 apres la triangularisation est : \n");
    TriangGauss(A2, n, m);
    affMat(A2, n, m);
    float **B2 = allouerMat(1,3);
    B2 = trouveB(A2, n, m);
    printf("La matrice B2 pour que xi est toujours egal a 1 est : \n");
    affMat(B2, 3, 1);


    printf("\n\n================MATRICE TEST A3===============\n\n");
    // POUR MATRICE TEST A3
    float **A3 = allouerMat(3,3);
    entrerMatrice(A3, n, m);
    printf("Notre matrice A3 avant la triangularisation est: \n");
    affMat(A3, n, m);
    printf("Notre matrice A3 apres la triangularisation est : \n");
    TriangGauss(A3, n, m);
    affMat(A3, n, m);
    float **B3 = allouerMat(1,3);
    B3 = trouveB(A3, n, m);
    printf("La matrice B3 pour que xi est toujours egal a 1 est : \n");
    affMat(B3, 3, 1);


    printf("\n\n================MATRICE TEST A4===============\n\n");
    // POUR MATRICE TEST A4
    float **A4 = allouerMat(3,3);
    entrerMatrice(A4, n, m);
    printf("Notre matrice A4 avant la triangularisation est: \n");
    affMat(A4, n, m);
    printf("Notre matrice A4 apres la triangularisation est : \n");
    TriangGauss(A4, n, m);
    affMat(A4, n, m);
    float **B4 = allouerMat(1,3);
    B4 = trouveB(A4, n, m);
    printf("La matrice B4 pour que xi est toujours egal a 1 est : \n");
    affMat(B4, 3, 1); */


    // POUR MATRICE TEST A5
    printf("\n\n================MATRICE TEST A5===============\n\n");
    float **A5 = allouerMat(n,m);
    remplMatA5(A5,n);
    printf("Notre matrice A5 avant la triangularisation est: \n");
    affMat(A5, n, m);
    printf("Notre matrice A5 apres la triangularisation est : \n");
    TriangGauss(A5, n, m);
    affMat(A5, n, m);
    float **B5 = allouerMat(1,3);
    B5 = trouveB(A5, n, m);
    printf("La matrice B5 pour que xi est toujours egal a 1 est : \n");
    affMat(B5, 3, 1); 


    // POUR MATRICE TEST A6
    printf("\n\n================MATRICE TEST A6===============\n\n");
    float **A6 = allouerMat(n,m);
    remplMatA6(A6,n);
    printf("Notre matrice A6 avant la triangularisation est: \n");
    affMat(A6, n, m);
    printf("Notre matrice A6 apres la triangularisation est : \n");
    TriangGauss(A6, n, m);
    affMat(A6, n, m);
    float **B6 = allouerMat(1,3);
    B6 = trouveB(A6, n, m);
    printf("La matrice B6 pour que xi est toujours egal a 1 est : \n");
    affMat(B6, 3, 1);

    return 0;	

}