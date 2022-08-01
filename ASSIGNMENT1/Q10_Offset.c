// Himanshu Mohanty
// 2105719
// CSE36
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the number of input char:");
    scanf("%d", &n);
    int offset;
    char temp;
    scanf("%c", &temp);
    char *input = (char *)malloc(n * sizeof(char));
    int numInt[n];
    printf("\nENTER THE CHAR\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &input[i]);
        numInt[i] = input[i];
        scanf("%c", &temp);
    }
    printf("Enter the offset:");
    scanf("%d", &offset);
    for (int i = 0; i < n; i++)
    {
        int c = input[i] + offset;
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        {
            printf("%C ", c);
        }
        else if (c < 65 || c < 97)
        {
            int z = 26 + c;
            printf("%c ", z);
        }
    }
    free(input);
    return 0;
}
