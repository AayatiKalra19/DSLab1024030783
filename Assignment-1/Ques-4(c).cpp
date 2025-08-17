#include <iostream>
using namespace std;
int main() {
    int m,n;
    cout<<"Enter number of rows: ";
    cin>>m;
    cout<<"Enter number of columns: ";
    cin>>n;
    int arr[m][n];
    int arr2[n][m];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            arr2[i][j] = arr[j][i]; 
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout<<arr2[i][j];
        }
        cout<<endl;
    }
    return 0;
}