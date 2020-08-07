//
//  main.cpp
//  100. 相同的树
//
//  Created by 董深育 on 2020/8/7.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*>mystack;
        stack<TreeNode*>mystack1;
        if(p!=NULL&&q!=NULL&&p->val==q->val){
            mystack.push(p);
            mystack1.push(q);
        }else{
            return false;
        }

        while(!mystack.empty()||!mystack1.empty()){
            if(p==NULL&&q==NULL){
                return true;
            }
            TreeNode*temp=mystack.top();
            TreeNode*q1=mystack1.top();
            mystack.pop();
            mystack1.pop();
            if(temp->val!=q1->val){
                return false;
            }
            if(temp->right!=NULL&&q1->right!=NULL){
                mystack.push(temp->right);
                mystack1.push(q1->right);
            }
            if((temp->right!=NULL&&q1->right==NULL)||(temp->right==NULL&&q1->right!=NULL)){
                return false;
            }
            if(temp->left!=NULL&&q1->left!=NULL){
                mystack.push(temp->left);
                mystack1.push(q1->left);
            }
            if((temp->left!=NULL&&q1->left==NULL)||(temp->left==NULL&&q1->left!=NULL)){
                return false;
            }

        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
