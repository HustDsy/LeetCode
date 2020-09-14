//
//  main.cpp
//  94. 二叉树的中序遍历
//
//  Created by 董深育 on 2020/9/14.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<stack>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
    
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        stack<TreeNode*>mystack;
        vector<int>ret;
        TreeNode*cur=root;
        while(cur!=NULL||!mystack.empty()){
            while(cur!=NULL){
                mystack.push(cur);
                cur=cur->left;
            }
            cur=mystack.top();
            ret.emplace_back(cur->val);
            mystack.pop();
            cur=cur->right;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
