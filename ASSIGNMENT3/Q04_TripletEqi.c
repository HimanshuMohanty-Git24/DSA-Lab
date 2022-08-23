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
    printf("\nInput matrix\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
            if (arr[i][j] != 0)
            {
                ctr++;
            }
        }
        printf("\n");
    }
    int tri[ctr][3];
    tri[0][0] = m;
    tri[0][1] = n;
    tri[0][2] = ctr;
    int r1 = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                tri[r1][0] = i;
                tri[r1][1] = j;
                tri[r1][2] = arr[i][j];
                r1++;
            }
        }
    }
    printf("\nTriplet Equivalance\n");
    for (int i = 0; i <= ctr; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", tri[i][j]);
        }
        printf("\n");
    }
    int tritp[3][ctr];
    printf("\nTriplet transpose\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= ctr; j++)
        {
            printf("%d ", tri[j][i]);
            tritp[i][j] = tri[j][i];
        }
        printf("\n");
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