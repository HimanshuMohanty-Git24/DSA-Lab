// Himanshu Mohanty
// 2105719
// CSE36
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, pos = 1;
    printf("Enter the number of element in the array:");
    scanf("%d", &n);
    int *ptr = (int *)malloc(n * sizeof(int));
    printf("Enter the element of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    printf("Input array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }
    ptr[pos - 1] = 0;
    printf("\nOutput array\n");
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] != 0)
        {
            printf("%d ", ptr[i]);
        }
    }

    return 0;
}
