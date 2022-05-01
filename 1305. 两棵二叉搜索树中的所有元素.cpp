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
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> res;
        TreeNode *p = root1, *q = root2;
        stack<TreeNode *> s1, s2;
        while (p) {
            s1.push(p);
            p = p->left;
        }
        while (q) {
            s2.push(q);
            q = q->left;
        }
        while (!s1.empty() || !s2.empty() || p || q) {
            p = s1.empty() ? nullptr : s1.top();
            q = s2.empty() ? nullptr : s2.top();
            if (p && q) {
                if (p->val < q->val) {
                    res.push_back(p->val);
                    s1.pop();
                    p = p->right;
                    while (p) {
                        s1.push(p);
                        p = p->left;
                    }
                } else if (p->val > q->val) {
                    res.push_back(q->val);
                    s2.pop();
                    q = q->right;
                    while (q) {
                        s2.push(q);
                        q = q->left;
                    }
                } else {
                    res.push_back(p->val);
                    res.push_back(q->val);
                    s1.pop();
                    s2.pop();
                    p = p->right;
                    q = q->right;
                    while (p) {
                        s1.push(p);
                        p = p->left;
                    }
                    while (q) {
                        s2.push(q);
                        q = q->left;
                    }
                }
            } else if (p && !q) {
                res.push_back(p->val);
                s1.pop();
                p = p->right;
                while (p) {
                    s1.push(p);
                    p = p->left;
                }
            } else if (!p && q) {
                res.push_back(q->val);
                s2.pop();
                q = q->right;
                while (q) {
                    s2.push(q);
                    q = q->left;
                }
            }
        }
        return res;
    }
};