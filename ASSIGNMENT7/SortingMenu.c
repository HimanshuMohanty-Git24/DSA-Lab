#include <stdio.h>
#include <stdlib.h>
void insertionSort(int n, int arr[n])
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("\nArray after insertion sort:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void swap(int *n, int *m)
{
    int temp = n;
    n = m;
    m = temp;
}
int partition(int *arr, int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return (i + 1);
}
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int pi = partition(&arr, l, h);

        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}
int main()
{
    int choice = 0;
    int n;
    printf("\nEnter the number of element in array:");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the array element:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nSorting Menu Option\n");
    printf("\n1.Insertion Sort\n");
    printf("\n2.Quick Sort\n");
    printf("\n3.Heap Sort\n");
    printf("\n4.Radix Sort\n");
    printf("\n5.Merge Sort\n");
    printf("\n6.EXIT\n");
    while (choice != 6)
    {
        switch (choice)
        {
        case 1:
            insertionSort(n, arr);
            break;
        case 2:
            quickSort(arr, 0, n - 1);
            break;
        case 3:
            heapSort(arr);
            break;
        case 4:
            radixSort(arr);
            break;
        case 5:
            mergeSort(arr);
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("\nWrong Choice\n");
            break;
        }
    }
}
