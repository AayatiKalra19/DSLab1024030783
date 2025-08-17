#include <iostream>
using namespace std;
int main() {
    int a,b,m,n;
    cout<<"Enter number of rows for 1st matrix: ";
    cin>>a;
    cout<<"Enter number of columns for 1st matrix: ";
    cin>>b;
    cout<<"Enter number of rows for 2nd matrix: ";
    cin>>m;
    cout<<"Enter number of columns for 2nd matrix: ";
    cin>>n;
    int arr1[a][b];
    int arr2[m][n];
    int res[a][n];
    if (b==m) {
        for (int i=0;i<a;i++) {
        for (int j=0;j<b;j++) {
            cin>>arr1[i][j];
        }
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>arr2[i][j];
        }
    }
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = 0;
                for (int k = 0; k < b; k++) {
                    res[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
    }
    else {
        cout<<"Matrix Multiplication is not possible";
    }
    cout << "Resultant matrix:\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}