// Himanshu Mohanty
// 2105719
// CSE36
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n1, n2, n3;
    printf("Enter the number of element in the first array:");
    scanf("%d", &n1);
    int *ptr1 = (int *)malloc(n1 * sizeof(int));
    printf("Enter the element of first array\n");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &ptr1[i]);
    }
    printf("\nEnter the number of element in the Second array:");
    scanf("%d", &n2);
    int *ptr2 = (int *)malloc(n2 * sizeof(int));
    printf("Enter the element of Second array\n");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &ptr2[i]);
    }
    n3 = n1 + n2;
    int arr[n3];
    for (int i = 0; i < n1; i++)
    {
        arr[i] = ptr1[i];
    }
    for (int i = n1; i < n3; i++)
    {
        arr[i] = ptr2[i - n1];
    }
    printf("\nArray after merging\n");
    for (int i = 0; i < n3; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
