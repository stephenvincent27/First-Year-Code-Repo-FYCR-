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

void display(int arr[], int size)
{
  if(size == 0)
  {
    printf("\n");
    return;
  }
  printf("%d ", *(arr));
  display(arr+1, size-1);
}


int partition(int arr[], int low, int high)
{
  int pivot = arr[low];

  int i = low, j;

  for(j=low+1; j<=high; j++)
  {
    if(arr[j]<=pivot)
    {
      i++;
      swap(arr+i, arr+j);
    }
  }
  swap(arr+low, arr+i);
  return i;
}

void quickSort(int arr[], int low, int high)
{
  if(low>=high) return;

  int p = partition(arr, low, high);

  quickSort(arr, low, p-1);
  quickSort(arr, p+1, high);
}

int main()
{
  int size;

  printf("Enter the size of array: ");
  scanf("%d", &size);

  int arr[size];

  read(arr, size);
  quickSort(arr, 0, size-1);
  display(arr, size);
}
