//
//  main.cpp
//  104-二叉树的最大深度
//
//  Created by 董深育 on 2020/7/28.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    //递归解答
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ret=1;
        ret+=max(maxDepth(root->left),maxDepth(root->right));
        return ret;
    }
    //广度优先搜索
    int maxDepth_BFS(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*>myqueue;
        myqueue.push(root);
        int ret=0;
        while(!myqueue.empty()){
            int size=(int)myqueue.size();
            while(size>0){
                TreeNode*node=myqueue.front();
                myqueue.pop();
                if(node->left!=NULL){
                    myqueue.push(node->left);
                }
                if(node->right){
                    myqueue.push(node->right);
                }
                size--;
            }
            ret+=1;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
