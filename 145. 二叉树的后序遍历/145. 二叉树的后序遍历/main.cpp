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
    //迭代
    vector<int> postorderTraversal_iterartion(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int>myRet;
        stack<TreeNode*>nodes;
        nodes.push(root);
        TreeNode*temp=root;
        while(!nodes.empty()||temp!=NULL){
            if(temp!=NULL){
                nodes.push(temp->right);
                nodes.push(temp);
                nodes.push(temp->left);
            }else{
                
                
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
