//
//  main.cpp
//  剑指 Offer 27. 二叉树的镜像
//
//  Created by dsy on 2021/2/26.
//

#include <iostream>
using  namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode*left=mirrorTree(root->left);
        TreeNode*right=mirrorTree(root->right);
        root->right=left;
        root->left=right;
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
