//
//  main.cpp
//  99. 恢复二叉搜索树
//
//  Created by 董深育 on 2020/8/8.
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        bool firstsmall=true;//第一次出现后一个数比前一个数小
        TreeNode*cur=root;
        TreeNode*pre=NULL;
        TreeNode*max=NULL;
        TreeNode*min=NULL;
        if(root==NULL){
            return;
        }
        stack<TreeNode*>mystack;
        while(cur!=NULL||!mystack.empty()){
            while(cur!=NULL){
                mystack.push(cur);
                cur=cur->left;
            }
            cur=mystack.top();
            mystack.pop();
            if(pre!=NULL&&cur->val<pre->val&&firstsmall){
                firstsmall=false;
                max=pre;
            }
            if(max!=NULL&&cur->val<pre->val&&pre!=NULL){
                min=cur;
            }
            pre=cur;
            cur=cur->right;
        }
        int temp=min->val;
        min->val=max->val;
        max->val=temp;
    
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
