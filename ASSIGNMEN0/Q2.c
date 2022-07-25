// Himanshu Mohanty
// 2105719
// CSE36
#include <stdio.h>

void splitStrDynamic(char s[], char op, int flag[], int onesCount, int query, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i] == op)
        {
            flag[onesCount] = i;
            onesCount++;
        }
        else
            flag[onesCount] = 0;
    }
    if (query == 0)
    {
        for (int j = 0; j < flag[0]; j++)
        {
            printf("%c", s[j]);
        }
        printf("\t");
        for (int z = 0; z < flag[1]; z++)
        {
            printf("%c", s[z]);
        }
    }
    else if (query == 1)
    {
        for (int z = flag[0] + 1; s[z] != '\0'; z++)
        {
            printf("%c", s[z]);
        }
        printf("\t");
        for (int k = (flag[1] + 1); s[k] != '\0'; k++)
        {
            printf("%c", s[k]);
        }
    }
}

int main()
{
    char s[100], op, temp;
    int flag[100];
    int onesCount = 0;
    int query;
    printf("Enter a string:");
    scanf("%s", s);
    scanf("%c", &temp);
    printf("Enter the operator to split:");
    scanf("%c", &op);
    printf("Enter the integer to print the specific part:");
    scanf("%d", &query);
    int n = sizeof(s) / sizeof(s[0]);
    splitStrDynamic(s, op, flag, onesCount, query, n);
    return 0;
}
