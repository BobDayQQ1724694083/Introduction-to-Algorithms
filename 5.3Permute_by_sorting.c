#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int RandInt(int i, int j);
int *Permute_by_sorting(int A[]);

int RandInt(int i, int j)
{ 
    int a;
    srand((unsigned)time(NULL));
    a = i + rand() % (j - i + 1); 
    return a;
}

int *Permute_by_sorting(int A[])
{
    int i;
    int temp;
    int n = sizeof(A) / sizeof(A[0]); //let n equal the length of array A
    int *P = malloc(sizeof(int) * n);

    for(i = 0; i < n; i++)
        P[i] = RandInt(1, pow(n, 3));
    
    sort A, using P as sort keys
    return P;
}
