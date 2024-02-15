#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/***********************Rappel rapide - methode de Jacobi*****************************

La méthode de Jacobi, est une méthode itérative de résolution d'un système matriciel 
de la forme Ax = b, d'ou A est une matrice  carrée d'ordre n et x, b des vecteurs de 
R[n]. Pour  cela,  on utilise  une suite  x(k)  qui  converge vers  un point fixe x, 
solution du système d'équations linéaires.

********************************************************************************************/

/***********************Rappel rapide - methode de Gauss-Seidel*****************************

La méthode de Gauss-Seidel est une méthode itérative de résolution d'un système linéaire 
(de dimension finie) de la forme Ax=b, d'ou A est une matrice  carrée d'ordre n et x, b 
des vecteurs de R[n], ce qui signifie qu'elle  génère une suite qui converge vers 
une solution de cette équation, lorsque celle-ci  en a une et lorsque des conditions 
de convergence sont satisfaites. 

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
   printf("Entrez les valeurs de la matrice quoe vous voulez tester : \n");
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
    affVect: Fonction qui fait l'affichage de vecteur

    entrée: Le vecteur qu'on va afficher et son dimension

    sortie: La fonction va retourner rien.

********************************************************************************************/
void affVect(float *A, int n){
    
    int i, j;
    for(i=0; i<n; i++){
            printf("%.2f \t", A[i]);
        
        printf("\n");
    }
}
 

/******************************************************************************************
    trouveBjac: Fonction qui permet de nous trouver le vecteur B. 
                Le vecteur B  est  choisie de  sorte que  la  solution  exacte  du système 
                d’équations est x[i]=1, pour i =1,...,n.

    entrée: La matrice test et son dimension

    sortie: La fonction va nous retourner le vecteur trouvée B.

********************************************************************************************/

float * trouveBjac(float **mat, int n)
{
    
    float *B=malloc(n*sizeof(float));
    
    for(int i = 0; i < n; i++)
    {
        B[i] = 0;
       
        for(int j = 0; j < n; j++)
        {
            
            B[i]+= mat[i][j];
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

/******************************************************************************************
    Norme: Fonction qui permet de calculer la norme d'un vecteur donnée.

    entrée: Le vecteur et son dimension.

    sortie: La fonction va nous retourner la valeur de la norme de vecteur choisie.

********************************************************************************************/

float Norme(float *vect, int n)
{
    
    float N = 0.0;
    for(int i =0; i<n; i++)
    {
        N+= vect[i]*vect[i] ;
    }

    return sqrt(N);
}


/******************************************************************************************
    initX: Fonction qui permet d'initaliser a 0 le vecteur x initial.

    entrée: La dimension de vecteur.

    sortie: La fonction va nous retourner le vecteur initial = 0 0 0.

********************************************************************************************/


float *initX(int n)
{
    float *x = malloc(n*sizeof(float));
    for(int i =0; i<n; i++)
    {
        x[i] = 0.0;
    }
    return x;
}

/******************************************************************************************
    multipl: Fonction qui permet de faire la multiplication entre une matrice carree et un vecteur.

    entrée: La matrice carree et vecteur qu'on va multiplier et leur dimension. 

    sortie: La fonction va nous retourner un vecteur qui tient la valeur de multiplication.

********************************************************************************************/

float *multipl(float **A, float *b, int n)
{
    float *mult = malloc(n*sizeof(float));
    for(int i=0; i<n;i++)
    {
        mult[i] = 0.0;
        for(int j=0; j<n; j++)
        {
            mult[i]+= A[i][j]*b[j];
        }
    }
    return mult;
}

/******************************************************************************************
    soustract: Fonction qui permet de faire la soustraction entre deux vecteurs.

    entrée: Les deux vecteurs et leur dimension.

    sortie: La fonction va nous retourner une vecteur qui est resultat de soustraction de 
    deux vecteurs entrant.

********************************************************************************************/

float *soustract(float *v1, float *v2, int n)
{
    float *soustrac = malloc(n*sizeof(float));
    for(int i =0; i<n; i++)
    {
        soustrac[i] = 0.0;
        soustrac[i]+= v1[i] - v2[i]; 
    }
    return soustrac;

}

/******************************************************************************************
    calcEpsi: Fonction qui permet de nous calculer la valeur d'epsilon.

    entrée: Une matrice carree, le vecteur b, vecteur x0 et leur dimension n.

    sortie: La fonction va nous retourner la valeur d'epsilon calculee.

********************************************************************************************/

float calcEpsi(float **A, float *b, float*x0, int n)
{
    float *epsi;
    epsi = malloc(n*sizeof(float));
    for(int i =0;i<n;i++)
    {
        epsi[i] = 0.0;
    }
   
    epsi = multipl(A, x0, n);
   
    epsi = soustract(epsi, b, n);
   
    return Norme(epsi, n);
}

/******************************************************************************************
    xk: Fonction qui permet de calculer la valeur de x^(k+1)

    entrée: La matrice test A, le vecteur b, vecteur x0, leur dimension n et un entier i

    sortie: La fonction va nous retourner la valeur de x^(k+1)

********************************************************************************************/


float xk(float **A, float *b, float *x0, int n, int i)
{
    float a;
    
    float XK ;
    
    float sum = 0;
     a = 1/A[i][i];
        
    for(int j =0; j<n; j++)
    {
        if(i != j)
          {
             sum = sum + A[i][j]*x0[j];
          }
    }
    sum = b[i] - sum;
    XK = a*sum;
    
    return XK;

}

/******************************************************************************************
    errRel: Fonction qui permet de calculer la valeur d'erreur relaive.

    entrée: Un vecteur.

    sortie: La fonction va nous retourner la valeur d'erreur relative.

********************************************************************************************/

float errRel(float *x0)
{
    float err1,err2,err3;
    err1=1-x0[0];
    err2=1-x0[1];
    err3=1-x0[2];

    if ((err1>=err2)&&(err1>=err3))
    {
        return (err1);
    }
    else if((err2>=err1)&&(err2>=err3))
        {
            return(err2);
        }
        else
        {
            return (err3);
        }


}

/******************************************************************************************
    Jacobi: Fonction qui realise la methode de Jacobi --> Algorithme donnee en cours

    entrée: La matrice test, le vecteur b, le vecteur x0, leur dimension et epsilon.

    sortie: La fonction va nous retourner le nombre d'iterations pour cette methode.

********************************************************************************************/
int Jacobi(float **A, float *b, float *x0, int n, float epsi)
{
    int   k = 0;
    float *x0k1 = malloc(n*sizeof(float));
    float epsi1 = 1;
    
    while( (epsi1 >= epsi)  && (k < 50) )
    {
        for(int i = 0; i < n; i++)
        {  
            x0k1 [i]= xk(A, b, x0, n, i);
        }
        

        epsi1 = calcEpsi(A, b, x0k1, n);
        x0 = x0k1;
        printf("L'erreur relative de l'iteration %d est : %f \n", k+1, errRel(x0));
        k = k+1;
        
    }
    return k;
}

/******************************************************************************************
    GS: Fonction qui realise la methode de Gauss-Seidel --> Algorithme donnee en cours.

    entrée: La matrice test, le vecteur b, le vecteur x0, leur dimension et epsilon.

    sortie: La fonction va nous retourner le nombre d'iterations pour cette methode.

********************************************************************************************/

int GS(float **A, float *b, float *x0, int n, float epsi)
{
    int   k = 0;
    float epsi1 = 1;
    
    while( (epsi1 >= epsi)  && (k <50) )
    {
        for(int i=0; i<n; i++)
        {
            x0[i] = xk(A, b, x0, n,i);
        }
        
        epsi1 = calcEpsi(A, b, x0, n);
        printf("L'erreur relative de l'iteration %d est : %f \n", k+1, errRel(x0));
        
        k = k+1;
        
    }

    return k;
}





/*********************************************MAIN***************************************************************/


int main()
{
    int     n = 3;
    int     m = 3;
    float   epsi = 0.001;
    
    printf("\n=================MATRICE TEST================\n");

    float **A = allouerMat(n,n);
    entrerMatrice(A, n, m);
    printf("La matrice que vous avez entree est: \n");
    affMat(A, n, m);

    float *x0 = malloc(n*sizeof(float));
    // initialisation de vecteur x0 = 0
    x0 = initX(n);
    
    float *B = malloc(n*sizeof(float));
    B = trouveBjac(A, n);
    printf("Le vecteur B pour que xi est toujours egal a 1 est : \n");
    affVect(B, n);

    int nbIter = Jacobi(A, B, x0, n, epsi);
    printf("\n==>Nombre d'iterations pour jacobi est: %d\n\n", nbIter);
    
    int nbGS = GS(A, B, x0, n, epsi);
    printf("\n==>Nombre d iterations pour Gauss-Seidel est: %d\n", nbGS);
    
    	
    /*
    printf("================Matrice test A5==============");
    float **A5 = allouerMat(n,n);
    remplMatA5(A5,n);
    printf("\nNotre matrice A5  est: \n");
    affMat(A5, n, m);

    float *x0 = malloc(n*sizeof(float));
    // initialisation de vecteur x0 = 0
    x0 = initX(n);
    
    float *B5 = malloc(n*sizeof(float));
    B5 = trouveBjac(A5, n);
    
    printf("La matrice B5 pour que xi est toujours egal a 1 est : \n");
    affVect(B5, n);

    int nbIter = Jacobi(A5, B5, x0, n, epsi);
    printf("\n==>Nombre d'iterations pour jacobi est: %d\n\n", nbIter);
    
    int nbGS = GS(A5, B5, x0, n, epsi);
    printf("\n==>Nombre d iterations pour Gauss-Seidel est: %d\n", nbGS);
    */

    /*
    printf("================Matrice test A6==============");
    float **A6 = allouerMat(n,n);
    remplMatA6(A6,n);
    printf("\nNotre matrice A6  est: \n");
    affMat(A6, n, m);

    float *x0 = malloc(n*sizeof(float));
    // initialisation de vecteur x0 = 0
    x0 = initX(n);
    
    float *B6 = malloc(n*sizeof(float));
    B6 = trouveBjac(A6, n);
    
    printf("La matrice B6 pour que xi est toujours egal a 1 est : \n");
    affVect(B6, n);

    int nbIter = Jacobi(A6, B6, x0, n, epsi);
    printf("\n==>Nombre d'iterations pour jacobi est: %d\n\n", nbIter);
    
    int nbGS = GS(A6, B6, x0, n, epsi);
    printf("\n==>Nombre d iterations pour Gauss-Seidel est: %d\n", nbGS);
    */

    return 0;

}