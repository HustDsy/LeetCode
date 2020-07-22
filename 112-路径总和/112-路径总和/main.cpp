//
//  main.cpp
//  112-路径总和
//
//  Created by 董深育 on 2020/7/22.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
public:
    //递归
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return false;
        };
        if(root->left==NULL&&root->right==NULL){
            return sum==root->val;
        }
        return hasPathSum(root->left, sum-root->val)||hasPathSum(root->right, sum-root->val);
    }
    //非递归
    bool hasPathSum2(TreeNode* root, int sum) {
        queue<TreeNode*>nodes;
        queue<int>values;
        if(root==NULL){
            return false;
        }
        nodes.push(root);
        values.push(sum);
        while(!nodes.empty()){
            TreeNode*front=nodes.front();
            int num=front->val;
            int val=values.front();
            nodes.pop();
            values.pop();
            //如果该节点是叶节点的话，直接比较
            if(front->left==NULL&&front->right==NULL){
                if(val==num){
                    return true;
                }
            }
            if(front->left!=NULL){
                nodes.push(front->left);
                values.push(val-num);
            }
            if(front->right!=NULL){
                nodes.push(front->right);
                values.push(val-num);
            }
        }
        return false;
    }

};


int main(int argc, const char * argv[]) {
    TreeNode*head=new TreeNode(-2);
    TreeNode*right=new TreeNode(-3);
    head->right=right;
    Solution s;
    s.hasPathSum2(head, -2);
    return 0;
}
