#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[(n*(n+1))/2];
    for (int i=0;i<(n*(n+1)/2);i++) {
        cin>>arr[i];
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i<=j) {
                int index = (i * (2 * n - i + 1)) / 2 + (j - i);
                cout << arr[index] << " ";
            }
            else {
                cout<<"0 ";
            }

        }
        cout<<endl;
    }
}