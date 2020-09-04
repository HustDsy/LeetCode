//
//  main.cpp
//  257. 二叉树的所有路径
//
//  Created by 董深育 on 2020/9/4.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<string>ret;
    void dfs(TreeNode* root,string trace){
        if(root->left==NULL&&root->right==NULL){
            trace+="->";
            trace+=root->val;
            ret.emplace_back(trace);
            return;
        }
        if(root->left!=NULL){
            string kk=trace==""?to_string(root->val):trace+"->"+to_string(root->val);
            dfs(root->left,kk);
        }
        if(root->right!=NULL){
            string kk=trace==""?to_string(root->val):trace+"->"+to_string(root->val);
            dfs(root->right,kk);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        dfs(root,"");
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
