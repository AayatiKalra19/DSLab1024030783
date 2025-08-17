// Binary Search
#include <iostream>
using namespace std;
int binary_search(int arr[],int n, int st, int end) {
    int val;
    cout<<"Enter value to search: ";
    cin>>val;
    while (st<=end) {
        int mid = st+ (end-st)/2;
        if (arr[mid] == val) {
            cout<<"Element is present at index"<<endl;
            return mid;
        }
        else {
            if (val>arr[mid]) {
                st = st+1;
            }
            else {
                end = end-1;
            }
        }
    }
    cout<<"Element is not present"<<endl;
    return -1;
}
int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in the array "<<endl;
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int res = binary_search(arr,n,0,n-1);
    cout<<"Element found at index: "<<res;
}