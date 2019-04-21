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

void merge(int arr[], int low, int high)
{
  int mid = (low+high)/2;
  int n1 = mid-low+1, n2 = high-mid;

  int a[n1], b[n2];
  int i, j, k;

  for(i=0;i<n1;i++) a[i] = arr[low+i];
  for(j=0;j<n2;j++) b[j] = arr[mid+j+1];

  i = 0;
  j = 0;
  k = low;

  while(i<n1 && j<n2)
  {
    if(a[i]<=b[j])
    {
      arr[k] = a[i];
      i++;
    }
    else
    {
      arr[k] = b[j];
      j++;
    }
    k++;
  }

  while(i<n1)
  {
    arr[k] = a[i];
    i++;
    k++;
  }

  while(j<n2)
  {
    arr[k] = b[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int low, int high)
{
  if(low>=high) return;

  int mid = (low+high)/2;

  mergeSort(arr, low, mid);
  mergeSort(arr, mid+1, high);

  merge(arr, low, high);
}

int main()
{
  int size;

  printf("Enter the size of array: ");
  scanf("%d", &size);

  int arr[size];

  read(arr, size);
  mergeSort(arr, 0, size-1);
  display(arr, size);
}
