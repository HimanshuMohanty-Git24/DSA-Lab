#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, max, min;
    printf("Enter the number of element in the array:");
    scanf("%d", &n);
    int *ptr = (int *)malloc(n * sizeof(int));
    printf("Enter the element of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    max = min = ptr[0];
    for (int j = 0; j < n; j++)
    {
        if (ptr[j] > max)
        {
            max = ptr[j];
        }
        else if (ptr[j] < min)
        {
            min = ptr[j];
        }
    }
    printf("\nMax:%d\nMin:%d\n", max, min);

    return 0;
}