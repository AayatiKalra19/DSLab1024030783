#include <iostream>
using namespace std;

void maxHeapify(int A[], int i, int heapSize) {
    int left = 2 * i;  
    int right = 2 * i + 1;  
    int largest = i;

    if (left < heapSize && A[left] > A[largest])
        largest = left;

    if (right < heapSize && A[right] > A[largest])
        largest = right;
    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapify(A, largest, heapSize);
    }
}
void buildMaxHeap(int A[],int n) {
    for (int i = n/2; i>0;i--) {
        maxHeapify(A,i,n);
    }
}
void heapSort(int A[], int n) {
    buildMaxHeap(A, n);
    for (int i = n - 1; i >= 2; i--) {
        int temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        maxHeapify(A, 1, i);
    }
}