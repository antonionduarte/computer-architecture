#include <stdio.h>

int main() {
    int c, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;

    for (int i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0']; // Use c - '0' to get the numerical value of the char.
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    printf("Histogram:\n");

    printf("White: ");

    while (nwhite > 0) {
        printf("[]");
        --nwhite;
    }

    printf("\n");
    printf("Other: ");

    while (nother > 0) {
        printf("[]");
        --nother;
    }

    printf("\n");
  
    for (int i = 0; i < 10; i++) {
        printf("    %d", i);
        printf(": ");
        while (ndigit[i] > 0) {
            printf("[]");
            --ndigit[i];
        }
        printf("\n");
    }
}

// Output example:

// Histogram:

//  White: [][]
//  Other: [][][]
//      1: [][][][]
//      2: []
//      3: [][][][][][][][][]
//      4: [][]
//      ..
//      9: []