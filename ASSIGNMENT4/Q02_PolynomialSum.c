#include <stdio.h>
#include <stdlib.h>
int main()
{
    int hd1, hd2;
    printf("Enter the order of first polynomial:");
    scanf("%d", &hd1);
    printf("Enter the order of second polynomial:");
    scanf("%d", &hd2);
    int hd;
    if (hd1 > hd2)
    {
        hd = hd1;
    }
    else
    {
        hd = hd2;
    }
    int *poly = (int *)calloc((hd + 1), sizeof(int));
    printf("\nFIRST POLYNOMIAL\n");
    for (int i = 0; i <= hd1; i++)
    {
        printf("Enter the coefficient of X^%d:", i);
        scanf("%d", &poly[i]);
    }
    printf("\n\n");
    int *poly1 = (int *)calloc((hd + 1), sizeof(int));
    printf("\nSECOND POLYNOMIAL\n");
    for (int i = 0; i <= hd2; i++)
    {
        printf("Enter the coefficient of X^%d:", i);
        scanf("%d", &poly1[i]);
    }
    int *polysum = (int *)calloc((hd + 1), sizeof(int));
    for (int i = 0; i <= hd; i++)
    {
        polysum[i] = poly[i] + poly1[i];
    }

    printf("\nFINAL POLYNOMIAL AFTER SUM\n");
    for (int i = hd; i >= 0; i--)
    {
        if (i != 0)
        {
            printf("%dX^%d+", polysum[i], i);
        }
        else
        {
            printf("%dX^%d", polysum[i], i);
        }
    }

    return 0;
}
