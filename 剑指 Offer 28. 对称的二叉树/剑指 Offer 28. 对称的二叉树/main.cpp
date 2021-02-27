//
//  main.cpp
//  剑指 Offer 28. 对称的二叉树
//
//  Created by dsy on 2021/2/26.
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
    bool dfs(TreeNode*left,TreeNode*right){
        if(!left&&!right) return true;
        if(!left||!right) return false;
        if(left->val!=right->val) return false;
        return dfs(left->left,right->right)&&dfs(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dfs(root->left,root->right);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
