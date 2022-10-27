// Recursive method
#include <stdio.h>
#include <stdlib.h>
int linSear(int m, int arr[], int key)
{
    if (m < 0)
    {
        return -1;
    }
    if (arr[m] == key)
    {
        return m;
    }
    else
    {
        return linSear(m - 1, arr, key);
    }
}
int main()
{
    int n, key;
    printf("Enter the number of element:");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter the element:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the key:");
    scanf("%d", &key);
    int res;
    res = linSear(n - 1, a, key);
    if (res != -1)
    {
        printf("Yes %d is present at %d postion", key, (res + 1));
    }
    else
    {
        printf("%d not found in the array !!", key);
    }
    return 0;
}