//
//  main.cpp
//  701. 二叉搜索树中的插入操作
//
//  Created by 董深育 on 2020/9/30.
//

#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    
};


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode*top=root;
        while(root){
            //叶子节点的时候
            if(top->right==NULL&&top->left==NULL){
                if(top->val>val){
                    top->left=new TreeNode(val);
                    return root;
                }else{
                    top->right=new TreeNode(val);
                    return root;
                }
            }
            //直接相等了
            if(top->val==val){
                TreeNode*temp=top->left;
                top->left=new TreeNode(val);
                top->left->left=temp;
                return root;
            }else if(top->val<val){
                if(!top->right){
                    top->right=new TreeNode(val);
                    return root;
                }
                top=top->right;
                
            }else{
                if(!top->left){
                    top->left=new TreeNode(val);
                    return root;
                }
                top=top->left;
            }
        }
        return new TreeNode(val);
    }
    TreeNode* insertIntoBST_(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        TreeNode* pos = root;
        while (pos != nullptr) {
            if (val < pos->val) {
                if (pos->left == nullptr) {
                    pos->left = new TreeNode(val);
                    break;
                } else {
                    pos = pos->left;
                }
            } else {
                if (pos->right == nullptr) {
                    pos->right = new TreeNode(val);
                    break;
                } else {
                    pos = pos->right;
                }
            }
        }
        return root;
    }
    //递归
    TreeNode* insertIntoBST(TreeNode* root, int val) {
          if(root==NULL) return new TreeNode(val);
          if(root->val<=val){
              root->right=insertIntoBST(root->right,val);
          }
           if(root->val>val){
              root->left=insertIntoBST(root->left,val);
          }
          return root;
      }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
