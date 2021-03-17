//
//  main.cpp
//  剑指 Offer 55 - II. 平衡二叉树
//
//  Created by dsy on 2021/3/2.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

class Solution {
public:
    int dfs(TreeNode*root){
        if(!root) return 0;
        int left=dfs(root->left);
        if(left==-1) return -1;
        int right=dfs(root->right);
        if(right==-1) return -1;
        return abs(right-left)<2? max(left,right)+1:-1;

    }
    bool isBalanced(TreeNode* root) {
        return dfs(root)!=-1;

    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
