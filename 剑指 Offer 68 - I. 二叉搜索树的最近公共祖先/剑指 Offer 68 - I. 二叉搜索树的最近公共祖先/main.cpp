//
//  main.cpp
//  剑指 Offer 68 - I. 二叉搜索树的最近公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*ancestor=root;
        while(true){
            if(p->val<ancestor->val&&q->val<ancestor->val){
                ancestor=ancestor->left;
            }else  if(p->val>ancestor->val&&q->val>ancestor->val){
                ancestor=ancestor->right;
            }else{
                break;
            }
        }
        return ancestor;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
