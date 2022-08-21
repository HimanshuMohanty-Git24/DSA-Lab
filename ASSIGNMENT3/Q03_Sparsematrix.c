#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    printf("Enter the size of the matrix:");
    scanf("%d%d", &m, &n);
    int **arr;
    arr = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    printf("\nEnter the element of the matrix\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int ctr = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                ctr++;
            }
        }
    }
    int cond = (m * n) / 2;
    if (ctr >= cond)
    {
        printf("It is a sparse matrix");
    }
    else
    {
        printf("Not a sparse matrix");
    }
    for (int i = 0; i < m; i++)
    {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
    return 0;
}
