#include <stdio.h>

int power(int m, int n); // Parameter names are optional in a prototype.
// I could have written: int power(int, int);

int main() 
{
    for (int i = 0; i < 10; ++i) 
    {
        printf("%d %d %d\n", i, power(2,i), power(-3,i));
    }
    return 0;
}

int power(int base, int n)
{
    int p;

    p = 1;
    for (int i = 1; i <= n; ++i) 
    {
        p = p * base;
    }
    return p;
}