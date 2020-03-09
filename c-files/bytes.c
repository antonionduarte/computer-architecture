#include <stdio.h>
#include <limits.h>

int main() {
	printf("Short Bytes: %lu\n", sizeof(short));
	printf("Short Max Value: %d\n", SHRT_MAX);
	printf("Short Min Value: %d\n", SHRT_MIN); 
	printf("\n");
	printf("Integer Bytes: %lu\n", sizeof(int));
	printf("Integer Max Value: %d\n", INT_MAX);
	printf("Integer Min Value: %d\n", INT_MIN);
	printf("Unsigned Integer Bytes: %lu, Range: %u .. %d", sizeof(unsigned int), UINT_MAX, 0);
	// Note the usage of %lu for unsigned longs, %u for unsigned ints, %d for ints.
	printf("\n");
}