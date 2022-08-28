#include <stdio.h>
#include <stdlib.h>
int main()
{
    int hd1, hd2;
    printf("Enter the order of first polynomial:");
    scanf("%d", &hd1);
    printf("Enter the order of second polynomial:");
    scanf("%d", &hd2);
    int *poly = (int *)calloc((hd1 + 1), sizeof(int));
    printf("\nFIRST POLYNOMIAL\n");
    for (int i = 0; i <= hd1; i++)
    {
        printf("Enter the coefficient of X^%d:", i);
        scanf("%d", &poly[i]);
    }
    printf("\n\n");
    int *poly1 = (int *)calloc((hd2 + 1), sizeof(int));
    printf("\nSECOND POLYNOMIAL\n");
    for (int i = 0; i <= hd2; i++)
    {
        printf("Enter the coefficient of X^%d:", i);
        scanf("%d", &poly1[i]);
    }
    int *polymul = (int *)calloc((hd1 + hd2 + 1), sizeof(int));
    for (int i = 0; i <= hd1; i++)
    {
        for (int j = 0; j <= hd2; j++)
        {
            polymul[i + j] = polymul[i + j] + (poly[i] * poly1[j]);
        }
    }
    printf("\nFINAL POLYNOMIAL AFTER MULTIPLICATION\n");
    for (int i = hd1 + hd2; i >= 0; i--)
    {
        if (i != 0)
        {
            printf("%dX^%d+", polymul[i], i);
        }
        else
        {
            printf("%dX^%d", polymul[i], i);
        }
    }

    return 0;
}
