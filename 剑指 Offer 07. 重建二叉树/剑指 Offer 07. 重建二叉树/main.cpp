//
//  main.cpp
//  剑指 Offer 07. 重建二叉树
//
//  Created by dsy on 2021/2/25.
//

#include <iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
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
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
