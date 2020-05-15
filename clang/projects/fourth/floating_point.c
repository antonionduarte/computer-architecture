#include <stdio.h>

void print_signal(int* x) {
    if ((*x & (1 << 31)) == 0) printf("%c", '+'); // Verifies if the most significant bit 
    else printf("%c", '-');
}

void print_mantisse(int* x) {
    for (int i = 0; i < 23; i++) {
        if ((*x & (1 << 31)) != 0) printf("%d", 1);
        else printf("%d", 0);
        *x = *x << 1;
    }
}

void print_case_zero(int* x) {
    if (*x == 0) printf("%c%d%c", '+', 0, '.');
    else if (*x == (1 << 31)) printf("%c%d%c", '-', 0, '.');
    for (int i = 0; i < 23; i++)
        printf("%d", 0);
}

int main() { 
    float num = 0;
    scanf("%f", &num);
    int x = * (int *) &num; // This operation converts the float number to an unsigned integer.
    if (x == 0 || x == (1 << 31))
        print_case_zero(&x);
    else {
        print_signal(&x);
        x = x << 9; // Remove the sign and exponent bits.
        printf("%d%c", 1, '.'); // Adds the hidden bit and the dot.
        print_mantisse(&x);
    }
    printf("\n");
    return 0;
}