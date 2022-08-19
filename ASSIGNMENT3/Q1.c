#include <stdio.h>
#include <math.h>
int gcd(int x, int p)
{
    while (x != p)
    {
        if (x > p)
        {
            x = x - p;
        }
        else
        {
            p = p - x;
        }
    }
    if (x == 1)
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
    int count;
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
    int x, a, p, res, power;
    scanf("%d%d%d", &x, &a, &p);
    int gflag, pflag;
    gflag = gcd(x, p);
    pflag = prime(p);
    if (gflag == 1 && pflag == 1)
    {
        power = pow(x, a);
        res = power % p;
    }
    return 0;
}
