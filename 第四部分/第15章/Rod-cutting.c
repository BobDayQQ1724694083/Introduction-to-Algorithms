#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define pSize 10

int max(int a, int b);
int cutRot(int p[], int n);

/*自顶向下cutRot过程*/
int memoizedCutRot(int p[], int n);
int memoizedCutRodAux(int p[], int n, int r[]);

/*自底向上法*/
int bottomUpCutRod(int p[], int n);

/*重构解*/
struct solution
{
    int *r; //计算最大收益值
    int *s; //保存最优解对应的第一段钢条的切割长度
};
typedef struct solution *bestCutWay;

bestCutWay extenedBottomUpCutRod(int p[], int n, bestCutWay result);
void printCutRodSolution(int p[], int n, bestCutWay result);

int main()
{
    int n = 10;
    int p[pSize] = {1, 5, 8, 9, 10, 17, 17, 20, 24};

    bestCutWay result = malloc(sizeof(struct solution));
    result->r = malloc(sizeof(int) * n);
    result->s = malloc(sizeof(int) * n);

    printf("best solution is %d\n", memoizedCutRot(p, n));
    printf("best solution is %d\n", cutRot(p, n));
    printf("best solution is %d\n", bottomUpCutRod(p, n));
    printCutRodSolution(p, n, result);
}

int max(int a, int b)
{
    return (a > b ? a : b);
}

int cutRot(int p[], int n)
{
    if (n == 0)
        return 0;
    int q = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        // printf("i = %d\n", i);
        q = max(q, p[i - 1] + cutRot(p, n - i));
    }
    return q;
}

int memoizedCutRot(int p[], int n)
{
    int *r = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        r[i] = INT_MIN;
    return memoizedCutRodAux(p, n, r);
}

int memoizedCutRodAux(int p[], int n, int r[])
{
    int q = INT_MIN;
    if (n != 0 && r[n - 1] >= 0) //防止n - 1 = -1数组越界
    {
        return r[n - 1]; //说明已经保存了当前情况下的最大收益
    }
    if (n == 0)
        q = 0;
    else
    {
        for (int i = 1; i <= n; i++)
            q = max(q, p[i - 1] + memoizedCutRodAux(p, n - i, r));
    }
    r[n - 1] = q;
    return q;
}

int bottomUpCutRod(int p[], int n)
{
    int q;
    int *r = malloc(sizeof(int) * n);
    r[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        q = INT_MIN;
        for (int i = 1; i <= j; i++)
            q = max(q, p[i - 1] + r[j - i]);
        r[j] = q;
    }
    return r[n];
}

bestCutWay extenedBottomUpCutRod(int p[], int n, bestCutWay result)
{
    int q;
    result->r[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        q = INT_MIN;
        for (int i = 1; i <= j; i++)
        {
            if (q < p[i - 1] + result->r[j - i])
            {
                q = p[i - 1] + result->r[j - i];
                result->s[j - 1] = i;
            }
        }
        result->r[j] = q;
    }
    return result;
}

void printCutRodSolution(int p[], int n, bestCutWay result)
{
    ;
    
    result = extenedBottomUpCutRod(p, n, result);
    while(n > 0)
    {
        printf("%d ", result->s[n - 1]);
        n = n - result->s[n - 1];
    }
}
