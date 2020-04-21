#include <stdio.h>

void verifyIf(int num);
unsigned char invertBit(unsigned char toInvert);

int main() {
    // Exercise 2-3:
    char toInvert;
    while (toInvert !=  EOF) {
        scanf("%c", &toInvert);
        printf( "%c\n", invertBit(toInvert));
    }
    return 0;
}

void verifyIf(int num) {
    if ((num & 1) == 0) printf("Par\n");
    else printf("Impar\n");
}

unsigned char invertBit(unsigned char toInvert) {
    return toInvert ^ 0b100000;
}