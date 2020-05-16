#include <stdio.h>

int main() {

    int i = 3;
    int* j = &i;

    int c = *j;

    printf("%d\n", c);

    return 0;
}