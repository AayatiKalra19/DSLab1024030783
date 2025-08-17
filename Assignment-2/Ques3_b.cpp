#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n-1];
    for (int i=0;i<n-2;i++) {
        cin>>arr[i];
    }
    int low= 0;
    int high = n-2;
    int missing_val = n+1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout<<"Missing number= "<<low + 1;
}
