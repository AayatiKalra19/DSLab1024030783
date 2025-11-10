#include <iostream>
#include <climits>
using namespace std;
void maxHeapify(int arr[],int i,int HeapSize) {
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;
        int largest = i;
        if (leftIndex <= HeapSize && arr[leftIndex] > arr[largest]) {
            largest = leftIndex;
        }
        if (rightIndex <= HeapSize && arr[rightIndex] > arr[largest]) {
            largest = rightIndex;
        }
        if (largest != i) {
            swap(arr[largest],arr[i]);
            maxHeapify(arr,largest,HeapSize);
        }
}
int maximum(int arr[]) {
    return arr[1];
} 
int heapMax(int arr[],int n) {
    if (n<1) {
        cout<<"Heap underflow"<<endl;
        return 1;
    }
    int max = arr[1];
    arr[1] = arr[n];
    n--;
    maxHeapify(arr,1,n);
    return max;
}
void heapIncreaseKey(int arr[],int i,int key) {
    if (key < arr[i]) {
        cout<<"The new key is smaller than the current key"<<endl;
        return;
    }
    arr[i] = key;
    while (i>1 && arr[i/2] < arr[i]) {
        swap(arr[i/2],arr[i]);
        i = i/2;
    }
}
void maxHeapInsert(int arr[], int &heapSize, int key) {

    heapSize = heapSize + 1;   
    arr[heapSize] = INT_MIN;

    heapIncreaseKey(arr, heapSize, key); 
}