**1) Develop a Menu driven program to demonstrate the following operations of Arrays** 

**——MENU——-** 

**1.CREATE** 

**2. DISPLAY** 

**3. INSERT** 

**4. DELETE** 

**5. LINEAR SEARCH** 

**6. EXIT** 

\#include <iostream>

using namespace std;



void create(int arr\[], int n) {

&nbsp;   for (int i = 0; i < n; i++) {

&nbsp;       cin >> arr\[i];

&nbsp;   }

}



void display(int arr\[], int n) {

&nbsp;   for (int i = 0; i < n; i++) {

&nbsp;       cout << arr\[i] << " ";

&nbsp;   }

&nbsp;   cout << endl;

}



void insert(int arr\[], int \&n) {

&nbsp;   int val, pos;

&nbsp;   cout << "Enter value to be inserted: ";

&nbsp;   cin >> val;

&nbsp;   cout << "Enter position (0-based): ";

&nbsp;   cin >> pos;



&nbsp;   if (pos < 0 || pos > n) {

&nbsp;       cout << "Invalid position!" << endl;

&nbsp;       return;

&nbsp;   }



&nbsp;   for (int i = n - 1; i >= pos; i--) {

&nbsp;       arr\[i + 1] = arr\[i];

&nbsp;   }

&nbsp;   arr\[pos] = val;

&nbsp;   n++;

}



void deleteElement(int arr\[], int \&n) {

&nbsp;   int pos;

&nbsp;   cout << "Enter position to delete (0-based): ";

&nbsp;   cin >> pos;



&nbsp;   if (pos < 0 || pos >= n) {

&nbsp;       cout << "Invalid position!" << endl;

&nbsp;       return;

&nbsp;   }



&nbsp;   for (int i = pos; i < n - 1; i++) {

&nbsp;       arr\[i] = arr\[i + 1];

&nbsp;   }

&nbsp;   n--;

}



void search(int arr\[], int n) {

&nbsp;   int val;

&nbsp;   cout << "Enter value: ";

&nbsp;   cin >> val;

&nbsp;   bool found = false;



&nbsp;   for (int i = 0; i < n; i++) {

&nbsp;       if (arr\[i] == val) {

&nbsp;           found = true;

&nbsp;           break;

&nbsp;       }

&nbsp;   }



&nbsp;   if (found)

&nbsp;       cout << "Element is present" << endl;

&nbsp;   else

&nbsp;       cout << "Element not present" << endl;

}



int main() {

&nbsp;   int arr\[100]; // max size

&nbsp;   int n = 0, choice;



&nbsp;   cout << "Enter number of elements: ";

&nbsp;   cin >> n;



&nbsp;   do {

&nbsp;       cout << "\\n--- MENU ---\\n";

&nbsp;       cout << "1. CREATE\\n2. DISPLAY\\n3. INSERT\\n4. DELETE\\n5. LINEAR SEARCH\\n6. EXIT\\n";

&nbsp;       cout << "Enter choice: ";

&nbsp;       cin >> choice;



&nbsp;       switch (choice) {

&nbsp;       case 1:

&nbsp;           create(arr, n);

&nbsp;           break;

&nbsp;       case 2:

&nbsp;           display(arr, n);

&nbsp;           break;

&nbsp;       case 3:

&nbsp;           insert(arr, n);

&nbsp;           break;

&nbsp;       case 4:

&nbsp;           deleteElement(arr, n);

&nbsp;           break;

&nbsp;       case 5:

&nbsp;           search(arr, n);

&nbsp;           break;

&nbsp;       case 6:

&nbsp;           cout << "Exiting..." << endl;

&nbsp;           break;

&nbsp;       default:

&nbsp;           cout << "Invalid choice!" << endl;

&nbsp;       }

&nbsp;   } while (choice != 6);



&nbsp;   return 0;

}



**2) Design the logic to remove the duplicate elements from an Array and after the** 

**deletion the array should contain the unique elements.**

int main() {

&nbsp;   int n;

&nbsp;   cout<<"Enter size of array: ";

&nbsp;   cin>>n;

&nbsp;   int arr\[n];

&nbsp;   cout<<"Enter elements in the array"<<endl;

&nbsp;   for (int i=0;i<n;i++) {

&nbsp;       cin>> arr\[i];

&nbsp;   }

&nbsp;   for (int i=0;i<n;i++) {

&nbsp;       for (int j=i+1;j<n;j++) {

&nbsp;           if (arr\[i]==arr\[j]) {

&nbsp;               for (int k=j;k<n-1;k++) {

&nbsp;                   arr\[k] = arr\[k+1];

&nbsp;               }

&nbsp;               n--;

&nbsp;               j--;

&nbsp;           }

&nbsp;           

&nbsp;       }

&nbsp;   }

&nbsp;   for (int i=0;i<n;i++) {

&nbsp;       cout<<arr\[i];

&nbsp;   }

&nbsp;   return 0;

}

**3)** int main() {

&nbsp;   int i;

&nbsp;   int arr\[5] = {1};

&nbsp;   for (i = 0;i<5;i++) {

&nbsp;       cout<<arr\[i]<<" ";

&nbsp;   }

&nbsp;   return 0;

}

OUTPUT- 1 0 0 0 0

**4)Implement the logic to** 

**a. Reverse the elements of an array** 

**b. Find the matrix multiplication** 

**c. Find the Transpose of a Matrix**

// Find the reverse of an array

int main() {

&nbsp;   int n;

&nbsp;   cout<<"Enter size of array: ";

&nbsp;   cin>>n;

&nbsp;   int arr\[n];

&nbsp;   cout<<"Enter elements in the array: ";

&nbsp;   for (int i=0;i<n;i++) {

&nbsp;       cin>>arr\[i];

&nbsp;   }

&nbsp;   reverse(arr,n);

&nbsp;   for (int i=0;i<n;i++) {

&nbsp;       cout<<arr\[i]<<" ";

&nbsp;   }

&nbsp;   return 0;

} 

// Find the Transpose of a Matrix

int main() {

&nbsp;   int m,n;

&nbsp;   cout<<"Enter number of rows: ";

&nbsp;   cin>>m;

&nbsp;   cout<<"Enter number of columns: ";

&nbsp;   cin>>n;

&nbsp;   int arr\[m]\[n];

&nbsp;   int arr2\[n]\[m];

&nbsp;   for (int i=0;i<m;i++) {

&nbsp;       for (int j=0;j<n;j++) {

&nbsp;           cin>>arr\[i]\[j];

&nbsp;       }

&nbsp;   }

&nbsp;   for (int i=0;i<n;i++) {

&nbsp;       for (int j=0;j<m;j++) {

&nbsp;           arr2\[i]\[j] = arr\[j]\[i]; 

&nbsp;       }

&nbsp;   }

&nbsp;   for (int i=0;i<n;i++) {

&nbsp;       for (int j=0;j<m;j++) {

&nbsp;           cout<<arr2\[i]\[j];

&nbsp;       }

&nbsp;       cout<<endl;

&nbsp;   }

&nbsp;   return 0;

} 

// Find the matrix multiplication 

int main() {

&nbsp;   int a,b,m,n;

&nbsp;   cout<<"Enter number of rows for 1st matrix: ";

&nbsp;   cin>>a;

&nbsp;   cout<<"Enter number of columns for 1st matrix: ";

&nbsp;   cin>>b;

&nbsp;   cout<<"Enter number of rows for 2nd matrix: ";

&nbsp;   cin>>m;

&nbsp;   cout<<"Enter number of columns for 2nd matrix: ";

&nbsp;   cin>>n;

&nbsp;   int arr1\[a]\[b];

&nbsp;   int arr2\[m]\[n];

&nbsp;   int res\[a]\[n];

&nbsp;   if (b==m) {

&nbsp;       for (int i=0;i<a;i++) {

&nbsp;       for (int j=0;j<b;j++) {

&nbsp;           cin>>arr1\[i]\[j];

&nbsp;       }

&nbsp;   }

&nbsp;   for (int i=0;i<m;i++) {

&nbsp;       for (int j=0;j<n;j++) {

&nbsp;           cin>>arr2\[i]\[j];

&nbsp;       }

&nbsp;   }

&nbsp;       for (int i = 0; i < a; i++) {

&nbsp;           for (int j = 0; j < n; j++) {

&nbsp;               res\[i]\[j] = 0;

&nbsp;               for (int k = 0; k < b; k++) {

&nbsp;                   res\[i]\[j] += arr1\[i]\[k] \* arr2\[k]\[j];

&nbsp;               }

&nbsp;           }

&nbsp;       }

&nbsp;   }

&nbsp;   else {

&nbsp;       cout<<"Matrix Multiplication is not possible";

&nbsp;   }

&nbsp;   cout << "Resultant matrix:\\n";

&nbsp;   for (int i = 0; i < a; i++) {

&nbsp;       for (int j = 0; j < n; j++) {

&nbsp;           cout << res\[i]\[j] << " ";

&nbsp;       }

&nbsp;       cout << endl;

&nbsp;   }

&nbsp;   return 0;

} 

**5) Write a program to find sum of every row and every column in a two-dimensional** 

**array.** 

int main() {

&nbsp;   int m,n;

&nbsp;   cout<<"Enter number of rows: ";

&nbsp;   cin>>m;

&nbsp;   cout<<"Enter number of columns: ";

&nbsp;   cin>>n;

&nbsp;   int arr\[m]\[n];

&nbsp;   for (int i=0;i<m;i++) {

&nbsp;       for (int j=0;j<n;j++) {

&nbsp;           cin>>arr\[i]\[j];

&nbsp;       }

&nbsp;   }

&nbsp;   for (int i=0;i<m;i++) {

&nbsp;       int row\_sum = 0;

&nbsp;       for (int j=0;j<n;j++) {

&nbsp;           row\_sum = row\_sum + arr\[i]\[j];

&nbsp;       }

&nbsp;       cout<<"Sum of elements in "<<i<<" row = ";

&nbsp;       cout<<row\_sum<<endl;

&nbsp;   }

&nbsp;   for (int i=0;i<m;i++) {

&nbsp;       int col\_sum = 0;

&nbsp;       for (int j=0;j<n;j++) {

&nbsp;           col\_sum = col\_sum + arr\[j]\[i];

&nbsp;       }

&nbsp;       cout<<"Sum of elements in "<<i<<" column = ";

&nbsp;       cout<<col\_sum<<endl;

&nbsp;   }

}

