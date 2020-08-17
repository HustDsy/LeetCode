//
//  main.cpp
//  110. 平衡二叉树
//
//  Created by 董深育 on 2020/8/17.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    //最大深度
    int getHigh(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        return max(getHigh(root->left),getHigh(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return abs(getHigh(root->left)-getHigh(root->right))<=1&&isBalanced(root->left)&&isBalanced(root->right);
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    TreeNode*root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);
    cout<<s.isBalanced(root);
    return 0;
}
