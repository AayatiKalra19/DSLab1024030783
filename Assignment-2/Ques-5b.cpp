#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[3*n-2];
    for (int i=0;i<3*n-2;i++) {
        cin>>arr[i];
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i-j==1) {
                cout<<arr[i-1]<<" ";
            }
            else if(i-j==0) {
                cout<<arr[n+i-1]<<" ";
            }
            else if(j-i==1) {
                cout<<arr[2*n-1+i]<<" ";
            }
            else {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}