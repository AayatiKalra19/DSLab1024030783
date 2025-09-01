#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int arr[(n * (n + 1)) / 2];
    cout << "Enter elements of array: ";
    for (int i = 0; i < (n * (n + 1)) / 2; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                int index = (i * (i + 1)) / 2 + j;
                cout << arr[index] << " ";
            } else {
                int index = (j * (j + 1)) / 2 + i;
                cout << arr[index] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
