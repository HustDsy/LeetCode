//
//  main.cpp
//  129. 求根到叶子节点数字之和
//
//  Created by 董深育 on 2020/10/29.
//

#include <iostream>
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
    vector<int>traces;
    void dfs(TreeNode*root,int trace){
        trace=trace*10+root->val;
        if(root->left==NULL&&root->right==NULL){
            traces.emplace_back(trace);
            return;
        }
        dfs(root->left,trace);
        dfs(root->right,trace);
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        dfs(root,0);
        for(const auto&it:traces){
            ans+=it;
        }
        return ans;
    }
    
};

int main(int argc, const char * argv[]) {

    return 0;
}
