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
    int *poly = (int *)malloc((hd + 1) * sizeof(int));
    printf("\nFIRST POLYNOMIAL\n");
    for (int i = 0; i <= hd1; i++)
    {
        printf("Enter the coefficient of X^%d:", i);
        scanf("%d", &poly[i]);
    }
    printf("\n\n");
    int *poly1 = (int *)malloc((hd + 1) * sizeof(int));
    printf("\nSECOND POLYNOMIAL\n");
    for (int i = 0; i <= hd2; i++)
    {
        printf("Enter the coefficient of X^%d:", i);
        scanf("%d", &poly1[i]);
    }
    if (hd1 > hd2)
    {
        poly1[hd] = 0;
    }
    else
    {
        hd = hd2;
        poly[hd] = 0;
    }
    int *polysum = (int *)malloc((hd + 1) * sizeof(int));
    for (int i = 0; i <= hd; i++)
    {
        polysum[i] = poly[i] + poly1[i];
    }

    printf("\nFINAL POLYNOMIAL AFTER SUM\n");
    for (int i = hd; i >= 0; i--)
    {
        printf("Coefficient of X^%d:%d\n", i, polysum[i]);
    }

    return 0;
}
