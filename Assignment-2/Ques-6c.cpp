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
void multiply(int a[100][3], int b[100][3],int prod[100][3]) {
    if (a[0][1] != b[0][0]) {
        cout<<"Multiplication not possible";
        prod[0][2]=0;
        return;
    }
    int bt[100][3];
    transpose(b,bt);
    prod[0][0] = a[0][0];
    prod[0][1] = b[0][1];
    prod[0][2] = 0;
    int k=1;
    for (int i=0;i<a[0][0];i++) {
        for (int j=0;j<b[0][1];j++) {
            int sum = 0;
            for (int x=1;x<=a[0][2];x++) {
                if (a[x][0] == i) {
                    for (int y=1;y<=bt[0][2];y++) {
                        if(bt[y][0]== j && bt[y][1] == a[x][1]) {
                            sum += a[x][2] * bt[y][2];
                        }
                    }
                }
            }
            if (sum != 0) {
                prod[k][0] = i;
                prod[k][1] = j;
                prod[k][2] = sum;
                k++;
        }
    }
    prod[0][2] = k - 1;
    }
}
int main() {
    int a[100][3],b[100][3],prod[100][3];
    cout << "Enter rows, cols and number of non-zero elements of Matrix A: ";
    cin >> a[0][0] >> a[0][1] >> a[0][2];
    cout << "Enter (row col value) for each non-zero element: "<<endl;
    for (int i = 1; i <= a[0][2]; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    cout << "Enter rows, cols and number of non-zero elements of Matrix B: ";
    cin >> b[0][0] >> b[0][1] >> b[0][2];
    cout << "Enter (row col value) for each non-zero element: "<<endl;
    for (int i = 1; i <= b[0][2]; i++) {
        cin >> b[i][0] >> b[i][1] >> b[i][2];
    }
    display(a);
    display(b);
    multiply(a, b, prod);
    cout << "Multiplication of A and B:"<<endl;
    display(prod);
}