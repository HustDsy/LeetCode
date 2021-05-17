//
//  main.cpp
//  1038. 把二叉搜索树转换为累加树
//
//  Created by dsy on 2021/5/12.
//

#include <iostream>
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
    int pre=0;
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return nullptr;
        bstToGst(root->right);
        pre+=root->val;
        root->val=pre;
        bstToGst(root->left);
        return root;
       
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
