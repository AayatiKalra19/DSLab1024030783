#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextGreaterElement(int arr[],int n) {
    stack <int> s;
    vector<int> res(n);
    for (int i=n-1;i>=0;i--) {
        while (!s.empty() && s.top()<=arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            res[i] = -1;
        }
        else {
            res[i] = s.top();
        }
        s.push(arr[i]);
    }
    return res;
}
int main() {
    int arr[5] = {2,5,3,4,1};
    vector<int> result = nextGreaterElement(arr,5);
    for (int i=0;i<5;i++) {
        cout<<result[i]<<" ";
    }
} 