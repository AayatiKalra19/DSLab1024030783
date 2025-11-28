#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

vector<TreeNode*> build(int start, int end) {
    vector<TreeNode*> trees;

    if (start > end) {
        trees.push_back(NULL);
        return trees;
    }

    for (int root = start; root <= end; root++) {
        vector<TreeNode*> leftTrees  = build(start, root - 1);
        vector<TreeNode*> rightTrees = build(root + 1, end);

        for (auto L : leftTrees) {
            for (auto R : rightTrees) {
                TreeNode* node = new TreeNode(root);
                node->left = L;
                node->right = R;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return build(1, n);
}

void printPreorder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int n = 3;
    vector<TreeNode*> ans = generateTrees(n);

    cout << "Total Trees = " << ans.size() << "\n";
    int i = 1;
    for (auto t : ans) {
        cout << "Tree " << i++ << ": ";
        printPreorder(t);
        cout << "\n";
    }

    return 0;
}

