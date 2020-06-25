/**
 * AC 19/20 - MIEI - FCT/UNL
 * TPC 3 
 **/
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024
#define MAXLINE 2048

extern int mycompare( int size, int x[], int y[] );


int readOneArr(int max, int a[]) {
	char line[MAXLINE];
	if (fgets(line, MAXLINE, stdin) == NULL) exit(1);
	int i=0;
	char *curr;
	char *new=line;
	do {
		curr=new;
		a[i] = strtol(curr, &new, 10);
		i++;
	} while (i<max && curr!=new);
	return i-1;
}

int readArrs(int max, int a[], int b[]) {
	int na = readOneArr( max, a );
	int nb = readOneArr( max, b );
	if (na!=nb) return -1;
	return na;
}

int main() {
	int i, n;
	int a1[MAX], a2[MAX];

	n = readArrs(MAX, a1, a2);
	if(n == -1) {
		fprintf(stderr,"wrong input!\n");
		return 1;
	}
	i=mycompare(n, a1, a2);
	if ( i == -1 )
		printf("equal\n");
	else
		printf("different at %d\n", i);
	return 0;
}


