#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
int firstArray[132964];
int secondArray[132964];
int size = 0;
    int i,col_one,col_two;
    float temp;

    fp = fopen("Wordnet3.mtx", "r");
    if (fp == NULL)
    {
    exit(1);
    }
          printf("z");



while (size < 132964)
{
     fscanf (fp, "%d %d %f", &col_one, &col_two,&temp);
     firstArray[size] = col_one;
     secondArray[size] = col_two;
     size++;
}


for (i=0; i<size; i++) {
   printf("array1[%d] = %d,  array2[%d] = %d\n",
          i,firstArray[i], i, secondArray[i]);
}
}
