#include <stdio.h>

/* Tasks para hoje:
    - (0) Estudar floating point conversion. (X)
    - (1) Fazer os exercícios da ficha 1 todos. (X)
    - (2) Refazer o programa de ler binário mas com bitwise operators. (X)
    - (3) Estudar Assembly (testar diversas operações em C para testar com assembly).
*/

int main() {
    
    int* p = 565; // ou int *p = 3

    printf("%d", p);

    return 0;
}

// void test1() {
//     int* ip;
//     int *ip;

//     int var = 7;
//     int *var_ptr = &var;

//     printf("%d\n", *var_ptr);
//     printf("%d\n", var_ptr);
//     printf("%d\n\n", &var);

//     *var_ptr = 3;

//     printf("%d\n", *var_ptr);
//     printf("%d\n", var_ptr);
//     printf("%d\n", &var);

//     // Cenas complicadas, ignorar por enquanto.
//     for (int i = 0; i <= 100000; i++)
//         *(int*) i = 0;
// }