#include <stdio.h>

void readMatrixR(int *p, int row, int col) //Function for reading a matrix, recursively (Refer to Read Matrix using Recursion.c)
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

void matrixMulR(int *a, int *b, int *c, int row, int col, int com) //Function for multiplying a matrix using recursion
{                                                                  //a and b are operands, c is the resultant matrix
  static int i, j, k, sum;                                         //row is the rows in a, col is the columns in b
                                                                   //com is the columns in a or rows in b
  if(j==com)
  {
    *(c+i*col+k)=sum;
    sum=0;
    j=0;
    if(k==col)
    {
      k=0;
      if(i==row)
      {
        i=0;
        return;
      }
      i++;
      matrixMulR(a, b, c, row, col, com);
      return;
    }
    k++;
    matrixMulR(a, b, c, row, col, com);
    return;
  }

  sum += (*(a+i*col+j))*(*(b+j*col+k));
  j++;
  matrixMulR(a, b, c, row, col, com);
  return;
}

void printMatrix(int *p, int row, int col) //function to print a matrix, non recursively
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

  int C[a][d];
  if(b!=c)
  {
    printf("\nThe matrices are not compatible for multiplication.");
    return 0;
  }
  else matrixMulR(A[0],B[0],C[0],a,d,b);

  printMatrix(C[0],a,d);
  return 0;
}
