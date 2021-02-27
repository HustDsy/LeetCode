//
//  main.cpp
//  剑指 Offer 54. 二叉搜索树的第k大节点
//
//  Created by dsy on 2021/2/26.
//

#include <iostream>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int res;
    int k;
    void dfs(TreeNode* root){
        if(root==NULL||k<0) return;
        dfs(root->right);
        if(--k==0){
            res=root->val;
            return;
        }
        dfs(root->left);
    }
    int kthLargest(TreeNode* root, int k) {
        res=-1;
        this->k=k;
        dfs(root);
        return res;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    TreeNode *root=new TreeNode(5);
    TreeNode *root1=new TreeNode(3);
    TreeNode *root2=new TreeNode(6);
    TreeNode *root3=new TreeNode(2);
    TreeNode *root4=new TreeNode(4);
    TreeNode *root5=new TreeNode(1);
    root->left=root1;
    root->right=root2;
    root1->left=root3;
    root1->right=root4;
    root3->left=root5;
    s.kthLargest(root, 3);

    return 0;
}



