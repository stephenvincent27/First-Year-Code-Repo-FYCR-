#include <stdio.h>
#include <stdlib.h>

void read(int arr[], int size)
{
  if(size == 0) return;
  scanf("%d", arr);
  read(arr+1, size-1);
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int arr[], int size)
{
  int i, j;

  for(i=0;i<size;i++)
    for(j=0;j<size-i;j++)
      if(arr[j]>arr[j+1])
        swap(arr+j, arr+j+1);
}

void display(int arr[], int size)
{
  if(size == 0) return;
  printf("%d ", *(arr));
  display(arr+1, size-1);
}

int main()
{
  int size;

  printf("Enter the size of array: ");
  scanf("%d", &size);

  int arr[size];

  read(arr, size);
  bubbleSort(arr, size);
  display(arr, size);
}
