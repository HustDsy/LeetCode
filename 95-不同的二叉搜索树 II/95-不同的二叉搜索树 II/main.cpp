//
//  main.cpp
//  95-不同的二叉搜索树 II
//
//  Created by 董深育 on 2020/7/21.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
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
    vector<TreeNode*>dfs(int left,int right){
        vector<TreeNode*>ret;
        //如国左边大于右边，那么它树只能是nullptr
        if(left>right){
            ret.push_back(nullptr);
            return ret;
        }
        for(int i=left;i<=right;i++){
            //所有左子树的情况
            vector<TreeNode*>leftNodes=dfs(left,i-1);
            //所有右子树的情况
            vector<TreeNode*>rightNodes=dfs(i+1,right);
            //当根节点为i的时候，所有的情况等于左子树的种类乘右子树的情形
            for(TreeNode*leftNode:leftNodes){
                for(TreeNode*rightNode:rightNodes){
                    //为每一种情况新建树
                    TreeNode*head=new TreeNode(i);
                    head->left=leftNode;
                    head->right=rightNode;
                    ret.push_back(head);
                }
            }
            
        }
        
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n) return dfs(1, n);
        else return vector<TreeNode *>{};
    }
        
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<TreeNode*>ret=s.generateTrees(2);
    return 0;
}
