#include <iostream>
using namespace std;
void create(int arr[],int n) {
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
}
void display(int arr[],int n) {
    for (int i=0;i<n;i++) {
        cout<<arr[i];
    }
}
void insert(int arr[],int n) {
    int val,pos;
    cout<<"Enter value to be inserted: ";
    cin>>val;
    cout<<"Enter position: ";
    cin>>pos;
    for (int i=n-1;i>=pos;i--) {
        arr[i+1] = arr[i];
    }
    arr[pos] = val;
    n++;
}
void deleteElement(int arr[], int &n) {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    if (pos < 0 || pos >= n) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}
void search(int arr[],int n) {
    int val;
    cout<<"Enter value: ";
    cin>>val;
    int flag=0;
    for (int i=0;i<n;i++) {
        if (arr[i]==val) {
            flag = 1;
            break;
        }
    }
    if (flag==0) {
        cout<<"Element not present";
    }
    else {
        cout<<"Element is present";
    }
}
int main() {
    int n=0;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    int num;
    cout<<"Enter choice: ";
    cin>>num;
    do{
        cout<<"Enter choice: ";
        cin>>num;
        switch(num) {
            case 1:
                create(arr,n);
                break;
            case 2:
                display(arr,n);
                break;
            case 3: 
                insert(arr,n);
                break;
            case 4:
                deleteElement(arr,n);
                break;
            case 5:
                search(arr,n);
                break;
            case 6:
                cout<<"Exit";
        }
    }
    while (num!=6);
    return 0;
} 
void reverse(int arr[],int n) {
    for (int i=0,j=n-1;i<n/2;i++,j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}