#include <stdio.h>
#include <stdlib.h>
//对于一个数组A，最大子数组有三种情况
//完全位于A[low...mid]、跨越中点、完全位于A[mid+1...high]

struct subarray
{
    int left;
    int right;
    int sum;
};
typedef struct subarray *max_subarray;
//求解跨越中点的最大子数组
//我们只需找出形如A[i..mid]和A[mid+1..j]的最大子数组，然后合并
max_subarray Find_max_crossing_subarray(int A[], int low, int mid, int high)
{
    max_subarray sub = NULL;
    int left_sum = A[mid];
    int right_sum = A[mid + 1];
    int temp_left = left_sum;
    int temp_right = right_sum;
    int max_left = mid;
    int max_right = mid + 1;
    int i;

    for (i = mid - 1; i >= low; i--)
    {
        temp_left = A[i] + temp_left;
        if (temp_left > left_sum)
        {
            left_sum = temp_left;
            max_left = i;
        }
    }

    for (i = mid + 2; i <= high; i++)
    {
        temp_right = A[i] + temp_right;
        if (temp_right > right_sum)
        {
            right_sum = temp_right;
            max_right = i;
        }
    }

    sub = malloc(sizeof(struct subarray));
    if (sub == NULL)
    {
        printf("malloc sub is out of space!!!\n");
        exit(0);
    }

    sub->sum = right_sum + left_sum;
    sub->left = max_left;
    sub->right = max_right;

    return sub;
}

max_subarray Find_maximum_subarray(int A[], int low, int high)
{
    int mid;
    max_subarray left = NULL;
    max_subarray right = NULL;
    max_subarray cross = NULL; //三个指针分别指向三种情况的最大子数组
    max_subarray temp = NULL;

    left = malloc(sizeof(struct subarray));
    right = malloc(sizeof(struct subarray));
    cross = malloc(sizeof(struct subarray));
    temp = malloc(sizeof(struct subarray));

    if (left == NULL || right == NULL || cross == NULL || temp == NULL)
    {
        printf("malloc left, right or cross out of space!!!\n");
        exit(0);
    }

    if (high == low)
    {
        temp->left = low;
        temp->right = high;
        temp->sum = A[low];

        return temp;
    }
    else
    {
        mid = (low + high) / 2;
        left = Find_maximum_subarray(A, low, mid);
        right = Find_maximum_subarray(A, mid + 1, high);
        cross = Find_max_crossing_subarray(A, low, mid, high); //θ(n)

        if(left->sum >= right->sum && left->sum >= cross->sum)
        {
            free(right);
            free(cross);
            return left;
        }else if(right->sum >= left->sum && right->sum >= cross->sum)
        {
            free(left);
            free(cross);
            return right;
        }else{
            free(left);
            free(right);
            return cross;
        }
    }
}

int main()
{
    int A[] = {6, -1, 2, -5, -5, 1}; //测试用例
    max_subarray sub = NULL;
    sub = malloc(sizeof(struct subarray));
    if (sub == NULL)
    {
        printf("malloc max_sub is out of space!!!\n");
        exit(0);
    }

    sub = Find_maximum_subarray(A, 0, 5);
    printf("left : %d\n", sub->left);
    printf("right : %d\n", sub->right);
    printf("sum : %d", sub->sum);
}
