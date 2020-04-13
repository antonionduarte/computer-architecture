#include <stdio.h>
#include <stdlib.h>

int gamble(float n, float x)
{
    static int c = 0;
    while (n>0)
    {
        x = 2 * x;
        n = n - x;
        c++;
    }
    return c;
}

float gamble2(int n, float x)
{ 
    int c = 0;
    static float y = 0.5;
    float aux, aux2;
    while (y>0)
    {
        y = y - 0.01;
        aux = y;
        c = 0;
        aux2 = x;
        while (aux2>0)
        {
            aux = 2 * aux;
            aux2 = aux2 - aux;
            c++;
        }
        if (c == n)
        {
            return y;
            break;
        }
    }
    return -1;
}

int main() {
   float n = 15.7;
   //float x = 0.07;
   int z;
   printf("Quanto dinheiro tem? ");
   scanf("%f", &n);
   printf("\nQual e o numero de elementos do comboio que quer coneguir aguentar? ");
   scanf("%d", &z);
   //printf("%d\n", gamble(n,x));
   printf("A sua primeira aposta deve ser no valor de: %.2f", gamble2(z,n));
   return 0;
}