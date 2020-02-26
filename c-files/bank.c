#include <stdio.h>

// I actually only used this to test
// passing values by reference or value

void removeMoney(int, int);

int main() 
{
    int ammount = 10;
    int balance = 100;
    removeMoney(ammount, &balance);
    printf("%d", balance);
}

void removeMoney(int ammount, int balance) 
{
    balance -= ammount;
}