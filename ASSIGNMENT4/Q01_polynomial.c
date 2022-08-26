#include <stdio.h>
#include <stdlib.h>
int main()
{
    int hd;
    printf("Enter the highest degree of the polynomial:");
    scanf("%d", &hd);
    int *poly = (int *)malloc((hd + 1) * sizeof(int));
    for (int i = 0; i <= hd; i++)
    {
        printf("Enter the coefficient of X^%d:", i);
        scanf("%d", &poly[i]);
    }
    printf("\nThe input polynomial\n");
    for (int i = hd; i >= 0; i--)
    {
        printf("Coefficient of X^%d:%d\n", i, poly[i]);
    }

    return 0;
}
