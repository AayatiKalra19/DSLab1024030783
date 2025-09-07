#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
bool canBeSorted(vector <int> A,vector<int> &B) {
    int n = A.size();
    stack <int> s;
    vector<int> Sorted_A = A;
    sort(Sorted_A.begin(),Sorted_A.end());
    int j=0;
    for (int i=0;i<n;i++) {
        s.push(A[i]);
        while (!s.empty() && s.top() == Sorted_A[j]) {
            B.push_back(s.top());
            s.pop();
            j++;
        }
    }
    return (s.empty() && j==n);
}
int main() {
    vector <int> A={3,1,2};
    vector <int> B;
    if(canBeSorted(A,B)) {
        cout<<"Yes"<<endl;
        for (int x: B) {
            cout<<x<<" ";
        }
    }
    else {
        cout<<"No";
    }
}
