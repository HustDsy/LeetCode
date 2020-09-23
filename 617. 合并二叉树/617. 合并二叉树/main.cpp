//
//  main.cpp
//  617. 合并二叉树
//
//  Created by 董深育 on 2020/9/23.
//

#include <iostream>
#include<stack>
using namespace std;

struct TreeNode{
    TreeNode*left;
    TreeNode*right;
    int val;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL) return t2;
        if(t2==NULL) return t1;
        stack<TreeNode*>stack1;
        stack<TreeNode*>stack2;
        stack1.push(t1);
        stack2.push(t2);
        while(!stack1.empty()){
            TreeNode*top1=stack1.top();
            TreeNode*top2=stack2.top();
            stack1.pop();
            stack2.pop();
            top1->val+=top2->val;
            if(top1->left!=NULL){
                stack1.push(top1->left);
                if(top2->left==NULL){
                    stack2.push(new TreeNode(0));
                }else{
                    stack2.push(top2->left);
                }
            }
            if(top1->right!=NULL){
                stack1.push(top1->right);
                if(top2->right==NULL){
                    stack2.push(new TreeNode(0));
                }else{
                    stack2.push(top2->right);
                }
            }
            if(top1->left==NULL&&top2->left!=NULL){
                top1->left=new TreeNode(0);
                stack1.push(top1->left);
                stack2.push(top2->left);
            }
            if(top1->right==NULL&&top2->right!=NULL){
                top1->right=new TreeNode(0);
                stack1.push(top1->right);
                stack2.push(top2->right);
            }
        }
        return t1;
    }
    //递归求解
    TreeNode* mergeTree(TreeNode* t1, TreeNode* t2){
        if(t1==NULL) return t2;
        if(t2==NULL) return t1;
        TreeNode*merged=new TreeNode(t1->val+t2->val);
        merged->left=mergeTree(t1->left, t2->left);
        merged->right=mergeTree(t1->right, t2->right);
        return merged;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
