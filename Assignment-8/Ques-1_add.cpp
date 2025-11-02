#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this -> data = d;
        this -> left= NULL;
        this -> right= NULL;
    }
};
int sumLeft(Node* root) {
    int sum = 0;
    if (root == NULL) {
        return 0;
    }
    if (root -> left != NULL) {
        if (root -> left -> left == NULL && root -> left-> right == NULL) {
            sum = sum + root -> left -> data;
        }
        else {
            sum = sum + sumLeft(root -> left);
        }
        sum = sum + sumLeft(root -> right);
        return sum;
    }
}
int main() {
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    cout << "Sum of left leaves: " << sumLeft(root);
}