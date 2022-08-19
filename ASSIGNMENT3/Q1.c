#include <stdio.h>
#include <math.h>
int gcd(int x, int p)
{
    int gcd;
    for (int i = 1; i <= x && i <= p; ++i)
    {

        if (x % i == 0 && p % i == 0)
            gcd = i;
    }
    if (gcd == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int prime(int p)
{
    int count = 0;
    for (int i = 1; i <= p; i++)
    {
        if (p % i == 0)
        {
            count++;
        }
    }
    if (count == 2)
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
    int x, a, p, remainder, power, res1, res2;
    x = 4, p = 5, a = 10;
    int gflag, pflag;
    gflag = gcd(x, p);
    pflag = prime(p);
    if (gflag == 1 && pflag == 1 && a > (p - 1))
    {
        remainder = a % p;
        if (remainder == 0)
        {
            res1 = 1;
            printf("\nResult is :%d\n", res1);
        }
        else
        {
            res2 = pow(x, remainder);
            printf("\nResult is :%d\n", res2);
        }
    }
    else
    {
        printf("Requirement not met !!");
    }
    return 0;
}
