#include <stdio.h> #include <stdlib.h> #include<math.h>

void printmatrix(int m,int n,float A[100][100])

{

            for(int i=0;i<m;i++)

            {

                            for(int j=0;j<n;j++)

                            {

                                            printf("%9.4f\t",A[i][j]);

                            }

                            printf("\n");

            }

}

void matrixmult(int m,int n,int q,float S[100][100],float T[100][100],float C[100][100])

{

            {

    for (int i=0;i<m;i++)

        for(int j=0;j<q;j++)

        {

            C[i][j]=0;

            for(int k=0;k<n;k++)

            C[i][j]+= S[i][k]*T[k][j];

        }

}

            printmatrix(m,q,C);

}

void Minor(float A[100][100], float M[100][100],int p,int q,int n)

{

int s=0,t=0;

for(int i=0;i<n;i++)

{

    for(int j=0;j<n;j++)

    {

        if(i!=p && j!=q)

        {

            M[s][t++]=A[i][j];

            if(t==n-1)

            {

                t=0;

                s++;

            }

        }

    }

}

}

float Determinant(float A[100][100],int n)

{

float D=0;

if(n==1)

{

    D=A[0][0];

}

else if(n==2)

{

    D=A[0][0]*A[1][1]-A[0][1]*A[1][0];

}

else

{

    float Min[100][100];

    float sign=1;

    for(int i=0;i<n;i++)

    {

        Minor(A,Min,0,i,n);

        D+=sign*A[0][i]*Determinant(Min,n-1);

        sign=-sign;

    }

}

return D;

}

void cofactor(float a[100][100],float c[100][100],float n)

{

            float b[100][100];

            int l,h,m,k,i,j;

            for (h=0;h<n;h++)

{

                            for (l=0;l<n;l++)

    {

                                            m=0;

                                            k=0;

                                            for (i=0;i<n;i++)

        {   for (j=0;j<n;j++)

                                                            {

                if (i != h && j != l)

                {

                    b[m][k]=a[i][j];

                    if (k<(n-2))

                    {

                        k++;

                    }

                    else

                    {

                        k=0;

                        m++;

                    }

                                                                            }

                     c[h][l] = pow(-1,(h+l))*Determinant(b,(n-1));

            }

        }

    }

}

}

void inverse(float A[100][100],float n)

{

float in[100][100],c[100][100];

cofactor(A,c,n);

float det=Determinant(A,n);

if(det==0)

{

    printf("inverse of A does not exist\n");

}

else

 {

     for(int i=0;i<n;i++)

     {

         for(int j=0;j<n;j++)

         {

             in[i][j]=c[j][i]/det;

         }

     }

     printmatrix(n,n,in);

 }

}

int main()

{

int m,n,p,q;

//getting two matrices

printf("enter the dimensions of matrix A(m*n):\n");

scanf("%d %d",&m,&n);

float A[100][100];

printf("enter the elements of matrix A\n:");

for(int i=0;i<m;i++)

{

    for(int j=0;j<n;j++)

    {

        scanf("%f",&A[i][j]);

    }

}

printf("enter the dimensions of matrix B(p*q):\n");

scanf("%d %d",&p,&q);

float B[100][100];

printf("enter the elements of matrix B\n:");

for(int i=0;i<p;i++)

{

    for(int j=0;j<q;j++)

    {

        scanf("%f",&B[i][j]);

    }

}

float M[100][100];float M1[100][100];

//checking the type of matrix A is

if(m==1)

{

    printf("matrix A is a row matrix\n");

}

if(n==1)

{

    printf("matrix A is a column matrix\n");

}

if(m==n)

{

    printf("matrix A is a square matrix\n");

}

if(m!=n)

{

    printf("matrix A is a rectangular matrix\n");

}

//operations between the matrices

if(m!=p||n!=q)

{

    printf("the dimensions of the matrices A and B are not equal\n");

}

if(m==p&&n==q)

{

    float k;

    float S[100][100],D[100][100],cM[100][100];

    printf("the matrices are of same dimensions\n");

    printf("enter the value of k:\n");

    scanf("%f",&k);

    for(int i=0;i<m;i++)

    {

        for(int j=0;j<n;j++)

        {

            S[i][j]=A[i][j]+B[i][j];

            D[i][j]=A[i][j]-B[i][j];

            cM[i][j]=k*A[i][j];

        }

    }

    printf("A+B=\n");

    printmatrix(m,n,S);

    printf("A-B=\n");

    printmatrix(m,n,D);

    printf("k*A=\n");

    printmatrix(m,n,cM);

}

if(n!=p)

{

    printf("matrix multiplication of A,B cannot happen\n");

    if(m!=q)

    {

        printf("matrix multiplication of B,A cannot happen\n");

    }

}

if(n==p&&q!=m)

{

    printf("A*B=\n");

    matrixmult(m,n,q,A,B,M);

    printf("matrix multiplication of B,A cannot happen\n");

}

 if(n!=p&&q==m)

{

    printf("B*A=\n");

    matrixmult(m,n,q,B,A,M1);

    printf("matrix multiplication of A,B cannot happen\n");

}

if(n==p&&m==q)

{

    int check;

    printf("AB=\n");

    matrixmult(m,n,m,A,B,M);

    printf("BA=\n");

    matrixmult(n,m,n,B,A,M1);

    if(n==m)

    {

        for(int i=0;i<m;i++)

        {

            for(int j=0;j<m;j++)

            {

                if(M[i][j]!=M1[i][j])

                {

                    check=0;

                }

                else

                {

                    check=1;

                }

            }

        }

    }

    if(check==1)

    {

        printf("AB=BA is verified\n");

    }

    else

    {

        printf("AB!=BA\n");

    }

}

//operations on A and At

float At[100][100],A1[100][100],A2[100][100];

for(int i=0;i<n;i++)

{

    for(int j=0;j<m;j++)

    {

        At[i][j]=A[j][i];

    }

}

printf("At=\n");

printmatrix(n,m,At);

int test;

{

    printf("A*At=\n");

    matrixmult(m,n,m,A,At,A1);

    printf("At*A=\n");

    matrixmult(n,m,n,At,A,A2);

    if(m==n)

    {

        for(int i=0;i<m;i++)

        {

            for(int j=0;j<m;j++)

            {

                if(A1[i][j]==A2[i][j])

                {

                    test=1;

                }

                else

                {

                    test=0;

                }

            }

        }

    }

if(test==1)

{

    printf("At*A=A*At is verified\n");

}

else

{

    printf("At*A!=A*At\n");

}

}

//operations on square matrix A

int diag,iden,up,low,sym,orth,orth1;

float trace=0,A3[100][100],det,C[100][100];

if(m!=n)

{

    printf("the matrix A is not square matrix\n");
    printf("The cofactors do not exist for a non square matrix\n");


}

else

{

    for(int i=0;i<m;i++)

    {

        for(int j=0;j<m;j++)

        {

            //diagonal matrix

            if(i!=j)

            {

                if(A[i][j]!=0)

                {

                    diag=1;

                }

            }

            //identity matrix

            if(i==j)

            {

                if(A[i][j]!=1)

                {

                    iden=1;

                }

            }

            //upper triangular matrix

            if(i>j)

            {

                if(A[i][j]!=0)

                {

                    up=1;

                }

            }

            //lower triangular matrix

            if(i<j)

            {

                if(A[i][j]!=0)

                {

                    low=1;

                }

            }

            //symmetric

            if(A[i][j]!=At[i][j])

            {

                sym=1;

            }

            //trace

            if(i==j)

            {

                trace+=A[i][j];

            }

            //orthogonal

            {if(i==j)

            {

                if(A1[i][j]!=1)

                {

                    orth=1;

                }

            }

            else



            {

                if(A1[i][j]!=0)

                {

                    orth1=1;

                }

            }

            }

        }

    }

if(diag!=1)

{

    printf("The matrix A is a diagonal matrix\n");

}
else
{
	printf("The matrix A is not a diagonal matrix\n");

}
if(diag!=1&&iden!=1)

{

    printf("The matrix A is an identity matrix\n");

}
else
{
	printf("The matrix A is not an identity matrix\n");
}

if(up!=1)

{

    printf("The matrix A is an upper triangular  matrix\n");

}
else
{
	printf("The matrix A is not an upper triangular  matrix\n");
}

if(low!=1)

{

    printf("The matrix A is a lower triangular matrix\n");

}
else
{
	printf("The matrix A is not a lower triangular matrix\n");

}
//triangular

if(up!=1||low!=1)

{

    printf("The matrix A is triangular matrix\n");

}
else
{
	printf("The matrix A is not a triangular matrix\n");
}

if(sym!=1)

{

    printf("The matrix A is a symmetric matrix\n");

}

else

{

    printf("The matrix A is not a symmetric matrix\n");

}


if(orth!=1&&orth1!=1)

{

    printf("The matrix A is an orthogonal matrix\n");

}

else

{

    printf("The matrix A is not an orthogonal matrix\n");

}
printf("trace(A)=%f\n",trace);

//A,At

printf("At=\n");

printmatrix(n,m,At);

printf("A*At=\n");

matrixmult(n,n,n,A,At,A1);

printf("At*A=\n");

matrixmult(n,n,n,At,A,A2);

printf("A*A=\n");

matrixmult(n,n,n,A,A,A3);

det=Determinant(A,m);

printf("determinant of matrix A=%f\n",det);



cofactor(A,C,n);


for(int i=0;i<n;i++)

{

    for(int j=0;j<n;j++)

    {

        printf("The cofactor of A[%d][%d]=%f\n",i+1,j+1,C[i][j]);

    }

}
}



if(det!=0)

{

    printf("The inverse of matrix A :\n");

}

inverse(A,n);

return 0;

}
