#include <stdio.h>

// Constants

#define MAX_SIZE 9

// Declarations

void printBinary(int val);

// Main

int main() {
    for (int i = 256; i > 0; i--)
        printBinary(i);


}

// Functions

void printBinary(int val) {
    int result[MAX_SIZE];

    for (int i = 0; i <= MAX_SIZE - 1; i++)
        result[i] = 0;

    for (int i = 0; val >= 1 && i <= MAX_SIZE - 1; i++) {
        result[i] = val % 2;
        val = val / 2;
    }

    for (int i = MAX_SIZE - 1; i >= 0; i--) {
        int binary = result[i];
        printf("%d", binary);
    }

    printf("\n");
}

