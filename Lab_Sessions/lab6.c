#include<stdio.h>

void build_maxheap(int A[], int n);
void max_heapify(int A[], int i, int n);
void heap_sort(int A[], int n);
void display(int * ptr);

int main() {
    int arr[] = {7, 6, 3, 2, 0, 1, 4, 5, 9, 8};
    display(arr);

    heap_sort(arr, 10);
    display(arr);

    return 0;
}

void build_maxheap(int A[], int n) {
    for (int i = (n / 2); i >= 0; i--) {
        max_heapify(A, i, n);
    }
}

void max_heapify(int A[], int i, int n) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && A[largest] < A[l])
        largest = l;
    if (r < n && A[largest] < A[r])
        largest = r;

    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        max_heapify(A, largest, n);
    }
}

void heap_sort(int A[], int n) 
{
    build_maxheap(A, n);

    for (int i = n - 1; i >= 0; i--) {
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        max_heapify(A, 0, i);
    }
}

void display(int * ptr) {
    printf("\nArray is :\t");
    for (int i = 0; i < 10; i++)
        printf("%d\t", *(ptr + i));
    printf("\n");
}
