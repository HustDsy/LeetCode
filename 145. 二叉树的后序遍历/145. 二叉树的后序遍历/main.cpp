//
//  main.cpp
//  145. 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ret.push_back(root->val);
        return ret;
    }
    //后续遍历
    vector<int> postorderTraversal_iteration(TreeNode* root) {
        vector<int>myRet;
        if(root==NULL){
            return {};
        }
        stack<TreeNode*>nodes;
        nodes.push(root);
        TreeNode*pre=NULL;
        while(!nodes.empty()){
            TreeNode*cur=nodes.top();
            if((cur->left==NULL&&cur->right==NULL)||(pre!=NULL&&(pre==cur->left||pre==cur->right))){
                myRet.push_back(cur->val);
                pre=cur;
                nodes.pop();
            }else{
                if(cur->right!=NULL){
                    nodes.push(cur->right);
                }
                if(cur->left!=NULL){
                    nodes.push(cur->left);
                }
                
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
