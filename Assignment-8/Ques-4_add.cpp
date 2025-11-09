#include <iostream>
#include <vector>
using namespace std;
int maxNo(int a, int b) {
    if(a > b) return a;
    else return b;
}
class Node {
    public:
    int data;
    Node* left, *right;
        Node(int val) {
            data = val;
            right = left = nullptr;
        }
};
void pushingElements(Node* root, int level, vector<int>& ans) {
            if(!root) return;
    
            if(level == ans.size()) ans.push_back(root->data);

            pushingElements(root->right, level + 1, ans);
            pushingElements(root->left, level + 1, ans);
        }

vector<int> rightSideView(Node* root) {
    vector<int> ans;
    pushingElements(root, 0, ans);
    return ans;
}