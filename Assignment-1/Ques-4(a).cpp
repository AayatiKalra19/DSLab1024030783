#include <iostream>
using namespace std;
void reverse(int arr[],int n) {
    for (int i=0,j=n-1;i<n/2;i++,j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in the array: ";
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    reverse(arr,n);
    for (int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
} 