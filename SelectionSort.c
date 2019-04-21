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

void selectionSort(int arr[], int size)
{
  int i, j, sm, pos;

  for(i=0;i<size;i++)
  {
    pos = i;
    for(j=i;j<size;j++)
    {
      if(arr[j]<arr[i]) pos = j;
    }
    swap(arr+i, arr+pos);
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
  selectionSort(arr, size);
  display(arr, size);
}
