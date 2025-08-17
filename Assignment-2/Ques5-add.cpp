#include <iostream>
using namespace std;

void duplicateTwos(int arr[], int n) {
    int countTwos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) {
            countTwos++;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        int newIndex = i + countTwos; 
        if (newIndex < n) {
            arr[newIndex] = arr[i];
        }
        if (arr[i] == 2) {
            countTwos--;  
            newIndex = i + countTwos;
            if (newIndex < n) {
                arr[newIndex] = 2;
            }
        }
    }
}

int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    duplicateTwos(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
