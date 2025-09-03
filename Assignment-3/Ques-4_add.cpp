#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector <int> dailyTemperature(int temp[],int n) {
    vector <int> ans(n,0);
    stack <int> s;
    for (int i=0;i<n;i++) {
        while (!s.empty() && temp[i] > temp[s.top()]) {
            int prevIndex = s.top();
            s.pop();
            ans[prevIndex] = i - prevIndex;
        }
        s.push(i);
    }
    return ans;
}
int main() {
    int arr[] = {73,74,75,69,76,72};
    vector <int> result = dailyTemperature(arr,6);
    for (int i=0;i<6;i++) {
        cout<<result[i]<<" ";
    }
}