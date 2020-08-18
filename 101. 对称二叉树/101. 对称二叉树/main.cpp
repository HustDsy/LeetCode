//
//  main.cpp
//  101. 对称二叉树
//
//  Created by 董深育 on 2020/8/18.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<queue>
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

    bool isTrue(TreeNode*p,TreeNode*q){
        if(p&&!q){
            return false;
        }
        if(q&&!p){
            return false;
        }
        if(!p&&!q){
            return true;
        }
        return p->val==q->val&&isTrue(p->left, q->right)&&isTrue(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isTrue(root, root);
    }
    
    bool isSymmetric_it(TreeNode*root){
        if(root==NULL){
            return true;
        }
        queue<TreeNode*>myqueue;
        myqueue.push(root);
        myqueue.push(root);
        while(!myqueue.empty()){
            TreeNode*u=myqueue.front();
            myqueue.pop();
            TreeNode*v=myqueue.front();
            myqueue.pop();
            if(u==NULL&&v==NULL){
                continue;
            }
            if((u!=NULL&&v==NULL)||(u==NULL&&v!=NULL)||(u->val!=v->val)){
                return false;
            }
            myqueue.push(u->left);
            myqueue.push(v->right);
            
            myqueue.push(u->right);
            myqueue.push(v->left);
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode*root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->right=new TreeNode(3);

    root->right=new TreeNode(2);
        root->right->left=new TreeNode(3);
    Solution s;
    s.isSymmetric(root);
    return 0;
}
