#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
void inorder(Node* root,vector <int>& arr) {
    if (root == NULL) {
        return;
    }
    inorder(root -> left,arr);
    arr.push_back(root -> data);
    inorder(root -> right,arr);
}
bool isBST(Node* root) {
    vector <int> arr;
    inorder(root,arr);
    for (int i = 0;i<arr.size()-1;i++) {
        if (arr[i]>= arr[i+1]) {
            return false;
        }
    }
    return true;
}