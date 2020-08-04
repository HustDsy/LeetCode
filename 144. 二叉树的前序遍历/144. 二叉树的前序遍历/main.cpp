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
    //迭代,后续遍历
    vector<int> preorderTraversal_iteration(TreeNode* root) {
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
    //中序遍历
    vector<int> midorderTraversal_iteration(TreeNode* root) {
        vector<int>myRet;
        if(root==NULL){
            return {};
        }
        stack<TreeNode*>mystack;
        TreeNode*cur=root;
        while(cur!=NULL||!mystack.empty()){
            while(cur!=NULL){
                mystack.push(cur);
                cur=cur->left;
            }
            cur=mystack.top();
            myRet.push_back(cur->val);
            cur=cur->right;
            mystack.pop();
            
        }
        return myRet;
    }

    
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode*node1=new TreeNode(1);
     TreeNode*node2=new TreeNode(2);
     TreeNode*node3=new TreeNode(3);
     TreeNode*node4=new TreeNode(4);
     TreeNode*node5=new TreeNode(5);
    node1->left=node2;
    node1->right=node3;
    node2->left=node4;
    node2->right=node5;
    Solution s;
    vector<int>ret=s.midorderTraversal_iteration(node1);
    
    
    return 0;
}
