#include <stdio.h>

int main()
{
    int m, n;
    printf("Enter the size of the matrix:");
    scanf("%d%d", &m, &n);
    int arr[m][n];
    printf("\nEnter the elements of the matrix\n");
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
    float per = ((float)ctr / (float)(m * n)) * 100;
    printf("\n%d\n", per);
    if (per >= 70)
    {
        printf("It is a sparse matrix");
    }
    else
    {
        printf("Not a sparse matrix");
    }

    return 0;
}
