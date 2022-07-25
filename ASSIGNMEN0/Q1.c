// Himanshu Mohanty
// 2105719
// CSE36
#include <stdio.h>
void splitString(char s[100], int query, int flag, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '.')
        {
            flag = i;
            break;
        }
    }
    if (query == 0)
    {
        for (int j = 0; j < flag; j++)
        {
            printf("%c", s[j]);
        }
    }
    else if (query == 1)
    {
        for (int z = flag + 1; s[z] != '\0'; z++)
        {
            printf("%c", s[z]);
        }
    }
}

int main()
{
    char s[100];
    int query, flag;
    printf("Enter a string:");
    scanf("%s", s);
    printf("Enter the integer to print the specific part:");
    scanf("%d", &query);
    int n = sizeof(s) / sizeof(s[0]);
    splitString(s, query, flag, n);
    return 0;
}