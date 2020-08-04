//
//  main.cpp
//  144. 二叉树的前序遍历
//
//  Created by 董深育 on 2020/8/4.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //递归
    vector<int>ret;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        ret.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ret;
    }
    //迭代
    vector<int> preorderTraversal_iteration(TreeNode* root) {
        vector<int>myRet;
        if(root==NULL){
            return {};
        }
        stack<TreeNode*>nodes;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode*temp=nodes.top();
            nodes.pop();
            myRet.push_back(temp->val);
            if(temp->right!=NULL){
                nodes.push(temp->right);
            }
            if(temp->left!=NULL){
                nodes.push(temp->left);
            }
            
        }
        return myRet;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
