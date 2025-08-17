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
    int k;
    cout<<"Enter k: ";
    cin>>k;
    int cnt=0;
    for (int i=0;i<n;i++) {
        int diff = 0;
        for (int j=i+1;j<n;j++) {
            diff = arr[i] - arr[j];
        
        if (diff<0) diff *= -1;
        if (i<j && diff == k) {
            cnt++;
        }
        }
    }
    cout<<"Number of pairs: "<<cnt;
    return 0;
}