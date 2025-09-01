#include <iostream>
using namespace std;
void display(int mat[100][3]) {
    int n = mat[0][2];
    cout<<"Row col val"<<endl;
    for (int i=1;i<=n;i++) {
        cout<<mat[i][0]<<" "<<mat[i][1]<<" "<<mat[i][2]<<endl;
    }
}
void add(int a[100][3],int b[100][3],int sum[100][3] ) {
    if (a[0][0]!=b[0][0] || a[0][1]!=b[0][1]) {
        cout<<"Addition not possible ";
        sum[0][2] = 0;
        return;
    }
    sum[0][0] = a[0][0];
    sum[0][1] = a[0][1];
    int i=1,j=1,k=1;
    while (i<=a[0][2] && j<=b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1]<b[j][1])) {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2];
            i++;k++;
        }
        else if(b[j][0]<a[i][0] || (b[j][0] == a[i][0] && b[j][1]<a[i][1])) {
            sum[k][0] = b[j][0];
            sum[k][1] = b[j][1];
            sum[k][2] = b[j][2];
            j++;k++;
        }
        else {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2]+b[j][2];
            i++;k++;j++;
        }
        while (i <= a[0][2]) {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2];
        i++; k++;
    }
        while (j <= b[0][2]) {
            sum[k][0] = b[j][0];
            sum[k][1] = b[j][1];
            sum[k][2] = b[j][2];
            j++; k++;
        }
    }
    sum[0][2] = k-1;
}
int main() {
    int a[100][3],b[100][3],sum[100][3];
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
    add(a,b,sum);
    display(sum);
}