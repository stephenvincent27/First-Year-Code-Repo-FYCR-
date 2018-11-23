#include <stdio.h>

 void readMatrix(int *p, int row, int col)
 {
   int i, j;
   for(i=0;i<row;i++)
   {
     for(j=0;j<col;j++)
     {
       printf("\nEnter the [%d][%d] element of matrix: ", i, j);
       scanf("%d", (p+i*col+j));
     }
   }
 }

 void readMatrixR(int *p, int row, int col)
 {
   static int i=0, j=0;
   if (i==row)
   {
     return;
   }
   if (j==col)
   {
     j=0;
     i++;
     readMatrixR(p,row,col);
     return;
   }

   printf("\nEnter the [%d][%d] element of matrix: ", i, j);
   scanf("%d", (p+i*col+j));
   j++;
   readMatrixR(p,row,col);
 }

   void printMatrix(int *p, int row, int col)
   {
     int i, j;
     for(i=0;i<row;i++)
     {
       for(j=0;j<col;j++) printf("%d  ", *(p+i*col+j));
       printf("\n");
     }
   }

int main()
{
  int a, b, c, d;

  printf("\nEnter the number of rows and column in matrix 1: ");
  scanf("%d %d", &a, &b);

  int A[a][b];
  readMatrixR(A[0],a,b);

  printf("\nEnter the number of rows and column in matrix 2: ");
  scanf("%d %d", &c, &d);

  int B[c][d];
  readMatrixR(B[0],c,d);

  printMatrix(A[0],a,b);

  return 0;
}
