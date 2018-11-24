#include <stdio.h>

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
     i=0;
     j=0;
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
  int a, b, c, d, m, n, o, sum;

  printf("\nEnter the number of rows and column in matrix 1: ");
  scanf("%d %d", &a, &b);

  int A[a][b];
  readMatrixR(A[0],a,b);

  printf("\nEnter the number of rows and column in matrix 2: ");
  scanf("%d %d", &c, &d);

  int B[c][d];
  readMatrixR(B[0],c,d);

  int C[a][d];
  if(b!=c)
  {
    printf("\nThe matrices are not compatible for multiplication.");
    return 0;
  }
  else
  {
    for(m=0;m<a;m++)
    {
      for(n=0;n<d;n++)
      {
        sum = 0;
        for(o=0;o<b;o++)
        {
          sum += A[m][o]*B[o][n];
        }
        C[m][n] = sum;
      }
    }
  }

  printMatrix(C[0],a,d);
  return 0;
}
