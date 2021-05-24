#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define MAX 26

void printHistograma(int histo[], int size)
{
   int i, j;
   for( i = 0; i < size; i++) {
        printf(" %3d : ", i);
		for( j = 0; j < histo[i]; j++ )
			printf("*");
		printf("\n");
    }
}

void histogramaAux(int valores[], int size, int histo[])
{
		for(int j = 0; j < size; j++){
			histo[valores[j]]++;
		}
}


extern void histograma(int valores[], int size, int histo[]);

int main( int argc, char *argv[ ])
{
   int vals[SIZE], hist[MAX], hist2[MAX], i, j;
   for (i=0; i < SIZE; i++)
		vals[i] = rand() % MAX;
   for (i=0; i < MAX; i++)
		hist[i] = 0;

   histogramaAux(vals, SIZE, hist2);
   histograma(vals, SIZE, hist );
   printHistograma( hist, MAX );

   j = -1;
   
   for (int l = 0; l < MAX; l++) {
      if (hist[l] != hist2[l]) j = l;
   }

   printf("Working: %d\n", j);

   return 0;
}

