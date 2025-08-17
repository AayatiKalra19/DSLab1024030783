#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int cnt = 0;
    for (int i=0;i<n;i++) {
        int flag = 1;
        for (int j=0;j<i;j++) {
            if (arr[i]==arr[j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            cnt = cnt + 1;
        }
    }
    cout<<"Number of distinct elements: "<<cnt;
}