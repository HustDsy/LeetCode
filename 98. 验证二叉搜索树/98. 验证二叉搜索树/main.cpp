//
//  main.cpp
//  98. 验证二叉搜索树
//
//  Created by dsy on 2021/5/13.
//

#include <iostream>
using namespace std;



struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int  pre=INT_MIN;
    bool first=false;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!isValidBST(root->left)) return false;
        if(root->val<=pre&&first) return false;
        first=true;
        pre=root->val;
        if(!isValidBST(root->right)) return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
