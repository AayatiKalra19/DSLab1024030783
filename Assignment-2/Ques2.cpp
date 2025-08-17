#include <iostream>
using namespace std;
void bubble_sort(int arr[],int n) {
    for (int i=0;i<n-1;i++) {
        int swap = 0;
        for (int j=0;j<n-i-1;j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap = 1;
            }
        }
        if (swap == 0) {
            break;
        }
    }
}
int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    bubble_sort(arr,n);
    for (int j=0;j<n;j++) {
        cout<<arr[j]<<" ";
    }
}