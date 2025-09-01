#include <iostream>
using namespace std;
void display(int mat[100][3]) {
    int n = mat[0][2];
    cout<<"Row col val"<<endl;
    for (int i=1;i<=n;i++) {
        cout<<mat[i][0]<<" "<<mat[i][1]<<" "<<mat[i][2]<<endl;
    }
}
void transpose(int mat[100][3],int result[100][3]) {
    int rows= mat[0][0],cols = mat[0][1],n=mat[0][2];
    result[0][0] = cols;
    result[0][1] = rows;
    result[0][2] = n;
    int k = 1;
    for (int i=0;i<cols;i++) {
        for (int j=1;j<=n;j++) {
            if (mat[j][1]==i) {
                result[k][0] = mat[j][1];
                result[k][1] = mat[j][0];
                result[k][2] = mat[j][2];
                k++;
            }
        }
    }
}
int main() {
    int a[100][3];
    int t[100][3];
    cout << "Enter rows, cols and number of non-zero elements of Matrix A: ";
    cin >> a[0][0] >> a[0][1] >> a[0][2];
    cout << "Enter (row col value) for each non-zero element:\n";
    for (int i = 1; i <= a[0][2]; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    transpose(a,t);
    cout<<"Transpose of Matrix A: "<<endl;
    display(t);
}