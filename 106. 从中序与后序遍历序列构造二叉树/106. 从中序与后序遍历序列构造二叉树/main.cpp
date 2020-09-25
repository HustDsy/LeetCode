//
//  main.cpp
//  106. 从中序与后序遍历序列构造二叉树
//
//  Created by 董深育 on 2020/9/25.
//

#include <iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int val):val(val),left(NULL),right(NULL){}
};


class Solution {
public:
    //inorder 中序遍历
    //postorder 后序遍历
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty()) return NULL;
        TreeNode*root=new TreeNode(postorder.back());
        int n=(int)distance(inorder.begin(),find(inorder.begin(),inorder.end(),postorder.back()));
        vector<int>inorder_left(inorder.begin(),inorder.begin()+n);
        vector<int>inorder_right(inorder.begin()+n+1,inorder.end());
        vector<int> postorder_left(postorder.begin(),postorder.begin()+n);
        vector<int> postorder_right(postorder.begin()+n,postorder.end()-1);
        root->left=buildTree(inorder_left,postorder_left );
        root->right=buildTree(inorder_right, postorder_right);
        return root;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> inorder={9,3,15,20,7};
    vector<int> postorder={9,15,7,20,3};
    s.buildTree(inorder,postorder );
    return 0;
}
