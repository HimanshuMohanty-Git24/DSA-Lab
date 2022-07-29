// Himanshu Mohanty
// 2105719
// CSE36
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, pos, val;
    printf("Enter the number of element in the array:");
    scanf("%d", &n);
    int *ptr = (int *)malloc((n + 1) * sizeof(int));
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
    printf("\nEnter the position where you want to insert:");
    scanf("%d", &pos);
    printf("Enter the value you want to insert:");
    scanf("%d", &val);
    for (int i = n; i > (pos - 1); i--)
    {
        ptr[i] = ptr[i - 1];
    }
    ptr[pos - 1] = val;
    printf("Output array\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", ptr[i]);
    }

    return 0;
}
