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

void insertionSort(int arr[], int size)
{
  int i, j, temp;

  for(i=1;i<size;i++)
  {
    temp = arr[i];
    for(j=i-1;j>=0;j--)
    {
      if(temp<=arr[j])
      {
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
      else break;
    }
  }
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
  insertionSort(arr, size);
  display(arr, size);
}
