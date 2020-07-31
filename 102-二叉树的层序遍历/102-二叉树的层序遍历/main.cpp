//
//  main.cpp
//  102-二叉树的层序遍历
//
//  Created by 董深育 on 2020/7/31.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>>ret;
        queue<TreeNode*>nodes;
        nodes.push(root);
        while(!nodes.empty()){
            int size=(int)nodes.size();
            vector<int>temp;
            while(size!=0){
                TreeNode*tempNode=nodes.front();
                nodes.pop();
                temp.push_back(tempNode->val);
                size--;
                if(tempNode->left!=NULL){
                    nodes.push(tempNode->left);
                }
                if(tempNode->right!=NULL){
                    nodes.push(tempNode->right);
                }
            }
            ret.push_back(temp);
        }
        return ret;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
