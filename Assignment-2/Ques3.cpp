#include <iostream>
using namespace std;
// Using linear time
int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n+1];
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int missing_val = n+1;
    for (int i=0;i<n;i++) {
        if (arr[i]!=i+1) {
            missing_val = i+1;
            break;
        }
    }
    cout<<"Missing element: "<<missing_val;
}