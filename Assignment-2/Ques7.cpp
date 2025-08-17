#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int cnt = 0;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (i<j && arr[i]>arr[j]) {
                cnt++;
            }
        }
    }
    cout<<"Number of inversions= "<<cnt;
    return 0;
}