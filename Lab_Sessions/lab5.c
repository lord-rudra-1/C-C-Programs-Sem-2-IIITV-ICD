#include <stdio.h>
#include<stdlib.h>

void quicksort(int *arr, int f, int e);
int partition(int *arr,int l,int r);
void display(int *arr);

int main()
{
    int arr[10]={0 ,7 ,9 ,5 ,4 ,8 ,2 ,1 ,3 ,6};
    
    display(arr);

    quicksort(arr, 0, 9);
    
    printf("\nAfter Performing QuickSort :\n");
    display(arr);

    return 0;
}

void quicksort(int *arr,int l,int r)
{
  if(l<r)
  {
    int piv=partition(arr,l,r);

    quicksort(arr,l,piv-1);
    quicksort(arr,piv+1,r);
  }
}

int partition(int *arr,int l,int r)
{
  int pe= l + rand() % (r-l+1);
  
  int temp;
  
  temp=*(arr+pe);
  *(arr+pe)=*(arr+l);
  *(arr+l)=temp;
   
  int pivot=*(arr+l);
  int i=l;
   
  for(int j=l+1;j<=r;j++)
  {
    if(*(arr+j)<pivot)
    {
      i++;
      temp=*(arr+i);
      *(arr+i)=*(arr+j);
      *(arr+j)=temp;
    }
  }
  temp=*(arr+i);
  *(arr+i)=*(arr+l);
  *(arr+l)=temp;
  return i;
}

void display(int *arr)
{
	printf("\nArray is :\t");
	for (int i = 0; i < 10; i++)
        printf("%d\t", *(arr+i));
    printf("\n");
}
