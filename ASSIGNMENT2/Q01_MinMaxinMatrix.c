#include <stdio.h>

int main(int argc, char const *argv[])
{
    int m, n, min, max;
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
    printf("\nInput Matrix\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    max = min = arr[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
            else if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }
    printf("\nMax number in the matrix:%d\nMin number in the matrix:%d\n", max, min);

    return 0;
}
