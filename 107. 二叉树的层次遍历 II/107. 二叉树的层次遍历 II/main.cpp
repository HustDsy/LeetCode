//
//  main.cpp
//  107. 二叉树的层次遍历 II
//
//  Created by 董深育 on 2020/9/6.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int val):val(val),left(NULL),right(NULL){}
};

class Solution{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    
        vector<vector<int>>ret;
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>myqueue;
        myqueue.push(root);
        while(!myqueue.empty()){
            vector<int>curLevel;
            int size=(int)myqueue.size();
            while(size>0){
                TreeNode*top=myqueue.front();
                myqueue.pop();
                curLevel.push_back(top->val);
                if(top->left!=NULL){
                    myqueue.push(top->left);
                }
                if(top->right!=nullptr){
                    myqueue.push(top->right);
                }
                size--;
            }
            ret.insert(ret.begin(), curLevel);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    TreeNode a(3);
   
    TreeNode b(9);
    TreeNode c(10);
    a.left=&b;
       a.right=&c;
    TreeNode d(15);
    TreeNode e(17);
    c.left=&d;
    c.right=&e;
    s.levelOrderBottom(&a);
    return 0;
}
