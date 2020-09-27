//
//  main.cpp
//  113. 路径总和 II
//
//  Created by 董深育 on 2020/9/27.
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
    vector<int>path;
    vector<vector<int>>ret;
    void dfs(TreeNode*root,int sum){
        if(root->left==NULL&&root->right==NULL&&sum==root->val){
            path.emplace_back(root->val);
            ret.push_back(path);
            path.pop_back();
            return;
        }
        //没说全为负数
        //if(root->val>=sum) return;
        if(root->left!=NULL) {
            path.emplace_back(root->val);
            dfs(root->left,sum-root->val);
            path.pop_back();
        }
        if(root->right!=NULL) {
            path.emplace_back(root->val);
            dfs(root->right,sum-root->val);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL) return {};
        dfs(root,sum);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
