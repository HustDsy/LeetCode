//
//  main.cpp
//  剑指 Offer 34. 二叉树中和为某一值的路径
//
//  Created by dsy on 2021/3/1.
//
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int>trace;
    vector<vector<int>>res;
    void dfs(TreeNode* root, int sum){
        if(sum==root->val&&root->left==nullptr&&root->right==nullptr){
            trace.push_back(root->val);
            res.push_back(trace);
            trace.pop_back();
            return;
        }
        trace.push_back(root->val);
        if(root->left) dfs(root->left,sum-root->val);
        if(root->right)dfs(root->right,sum-root->val);
        trace.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return {};
        dfs(root,sum);
        return res;
    }
};
