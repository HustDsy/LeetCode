#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode*left, *right;
    TreeNode():val(0), right(nullptr), left(nullptr) {}
    TreeNode(int x): val(x), right(nullptr), left(nullptr) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) {
            return root;
        } else if (root->val < val) {
            return searchBST(root->right, val);
        } else {
            return searchBST(root->left, val);
        }
    }
};