//
//  main.cpp
//  105.从前序与中序遍历序列构造二叉树
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
    //inorder 中序遍历 9,3,15,20,7]
    //preorder 前序遍历 [3,9,20,15,7]
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder) {
        if(inorder.empty()) return NULL;
        TreeNode*root=new TreeNode(preorder.front());
        int n=(int)distance(inorder.begin(),find(inorder.begin(),inorder.end(),preorder.front()));
        vector<int>inorder_left(inorder.begin(),inorder.begin()+n);//n个数
        vector<int>inorder_right(inorder.begin()+n+1,inorder.end());
        vector<int> preorder_left(preorder.begin()+1,preorder.begin()+1+n);//n个数
        vector<int> preorder_right(preorder.begin()+n+1,preorder.end());//
        root->left=buildTree(preorder_left,inorder_left);
        root->right=buildTree(preorder_right,inorder_right);
        return root;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> inorder={9,3,15,20,7};
    vector<int> postorder={3,9,20,15,7};
    s.buildTree(postorder,inorder );
    return 0;
}
