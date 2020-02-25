#include <stdio.h>

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