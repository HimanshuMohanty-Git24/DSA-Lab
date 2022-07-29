#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int n, max, min;
    int secMax, secMin;
    printf("Enter the number of element in the array:");
    scanf("%d", &n);
    int *ptr = (int *)malloc(n * sizeof(int));
    printf("Enter the element of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    max = secMax = 0;
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] > max)
        {
            secMax = max;
            max = ptr[i];
        }
        else if (ptr[i] < min && ptr[i] > secMax)
        {
            secMax = ptr[i];
        }
    }
    min = secMin = max;
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] < min)
        {
            secMin = min;
            min = ptr[i];
        }
        else if (ptr[i] > min && ptr[i] < secMin)
        {
            secMin = ptr[i];
        }
    }
    printf("\nSecMax:%d\n", secMax);
    printf("\nSecMin:%d\n", secMin);
    return 0;
}
