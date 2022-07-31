// Himanshu Mohanty
// 2105719
// CSE36
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char temp;
    char *input = (char *)malloc(3 * sizeof(char));
    int numInt[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%c", &input[i]);
        scanf("%c", &temp);
        numInt[i] = (int)(input[i]);
    }
    int offset;
    printf("Enter the offset:");
    scanf("%d", &offset);
    int num = 0;
    if (offset > 0)
    {
        for (int i = 1; i <= offset; i++)
        {
            num = (numInt[2] + i);
            printf("%c ", num);
        }
    }
    if (offset < 0)
    {
        int val;
        for (int i = -(offset); i > 0; i--)
        {
            val = 26 - i;
            num = (numInt[0] + (val));
            printf("%c ", num);
        }
    }

    return 0;
}
