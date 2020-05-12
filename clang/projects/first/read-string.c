#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {

    char str[SIZE];

    do {
        fgets(str, SIZE, stdin);
        str[strlen(str) - 1] = '\0';
        printf("->%s\n", str);
    } while (strcmp(str, "fim!") != 0);

    return 0;
}