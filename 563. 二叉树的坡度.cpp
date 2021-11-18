#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int res;
    unordered_map<TreeNode *, int> m;
    // 计算每个节点的左右子树的和，包括自己
    int dfs(TreeNode *cur) {
        if (cur == nullptr) {
            return 0;
        }
        int left = dfs(cur->left);
        int right = dfs(cur->right);
        m[cur] = left + right + cur->val;
        return m[cur];
    }
    void cal(TreeNode *root) {
        if (!root) {
            return;
        }
        res += abs(m[root->left] - m[root->right]);
        cal(root->left);
        cal(root->right);
    }
    int findTilt(TreeNode *root) {
        res = 0;
        m[nullptr] = 0;
        dfs(root);
        cal(root);
        return res;
    }
};