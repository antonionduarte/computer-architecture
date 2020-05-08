/**
 * AC 19/20 - MIEI - FCT/UNL
 * TPC 3 
 **/
#include <stdio.h>

extern int match( int a, int b, int c );


int main() {
  int x, y, z;

  scanf("%d%d%d", &x, &y, &z);
  if ( match(x, y, z) )
    printf("right bits\n");
  else
    printf("wrong bits\n");
  return 0;
}
