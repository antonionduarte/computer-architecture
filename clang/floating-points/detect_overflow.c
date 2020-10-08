#include <stdio.h>

#define OPERATION_OVERFLOW "operation overflow"

// Checks for overflow in multiplication, if there is an overflow prints "operation overflow", if not prints the result.
void check_product_overflow(long long a,long long b) {
    long long c = a * b;
    if (a == 0 || b == 0)
        printf("%lld\n", c);
    else {
        if ((c / a) != b) printf("%s\n", OPERATION_OVERFLOW);
        else printf("%lld\n", c);
    }
}

// Checks for overflow in   sum, if there is an overflow prints "operation overflow", if not prints the result.
void check_sum_overflow(long long a, long long b) {
    long long c = a + b;
    if (((a > 0) && (b > 0) && (c < 0)) || ((a < 0) && (b < 0) && (c > 0)))
        printf("%s\n", OPERATION_OVERFLOW);
    else
        printf("%lld\n", c);
}

int main() {
    long long a = 0;
    long long b = 0;

    scanf("%lld", &a);
    scanf("%lld", &b);

    check_sum_overflow(a, b);
    check_product_overflow(a, b);

    return 0;
}
