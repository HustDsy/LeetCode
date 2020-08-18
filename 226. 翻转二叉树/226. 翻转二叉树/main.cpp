//
//  main.cpp
//  226. 翻转二叉树
//
//  Created by 董深育 on 2020/8/18.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<queue>
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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        TreeNode*temp=root->left;
        root->left=root->right;
        root->right=temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    //迭代
    TreeNode*invertTree_iterator(TreeNode*root){
        if(root==NULL){
            return nullptr;
        }
        queue<TreeNode*>myqueue;
        myqueue.push(root);
        while(!myqueue.empty()){
            TreeNode*top=myqueue.front();
            myqueue.pop();
            TreeNode*left=top->left;
            TreeNode*right=top->right;
            top->left=right;
            top->right=left;
            if(left!=NULL){
                myqueue.push(left);
            }
            if(right!=nullptr){
                myqueue.push(right);
            }
        }
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
