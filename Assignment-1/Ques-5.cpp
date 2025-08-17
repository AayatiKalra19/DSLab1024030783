#include <iostream>
using namespace std;
int main() {
    int m,n;
    cout<<"Enter number of rows: ";
    cin>>m;
    cout<<"Enter number of columns: ";
    cin>>n;
    int arr[m][n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    for (int i=0;i<m;i++) {
        int row_sum = 0;
        for (int j=0;j<n;j++) {
            row_sum = row_sum + arr[i][j];
        }
        cout<<"Sum of elements in "<<i<<" row = ";
        cout<<row_sum<<endl;
    }
    for (int i=0;i<m;i++) {
        int col_sum = 0;
        for (int j=0;j<n;j++) {
            col_sum = col_sum + arr[j][i];
        }
        cout<<"Sum of elements in "<<i<<" column = ";
        cout<<col_sum<<endl;
    }
}