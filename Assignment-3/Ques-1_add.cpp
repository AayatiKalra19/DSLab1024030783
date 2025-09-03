#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector <int> nextSmallerElement(vector<int>& arr) {
    stack <int> s;
    s.push(-1);
    int n = arr.size();
    vector <int> res(n);
    for (int i=n-1;i>=0;i--) {
        int curr = arr[i];
        while (s.top() >= curr) {
            s.pop();
        }    
        res[i] = s.top();
        s.push(curr);
    }
    return res;
}
int main() {
    vector <int> arr = {2,1,4,3};
    vector <int> result = nextSmallerElement(arr);
    for (int i=0;i<result.size();i++) {
        cout<<result[i]<<" ";
    }
}
