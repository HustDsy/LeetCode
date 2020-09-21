//
//  main.cpp
//  538. 把二叉搜索树转换为累加树
//
//  Created by 董深育 on 2020/9/21.
//

#include <iostream>
#include<stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int val):val(val),left(NULL),right(NULL){}
};

class Solution {
public:
    //对于左节点，等于所有节点之和，对于右节点 等于本身，对于根，右边的树
    //中序遍历是由到大，现在反过来
    int num=0;
    TreeNode* convertBST(TreeNode* root) {
        if(root!=NULL){
            convertBST(root->right);
            root->val=root->val+num;
            num=root->val;
            convertBST(root->left);
            return root;
        }
        return NULL;
    }
    //非递归写法
    TreeNode* convertBST_(TreeNode* root) {
        if(root!=NULL){
            int num=0;
            TreeNode*cur=root;
            stack<TreeNode*>nodes;
            while(!nodes.empty()||cur!=NULL){
                while(cur!=NULL){
                    nodes.push(cur);
                    cur=cur->right;
                }
                cur=nodes.top();
                nodes.pop();
                cur->val=cur->val+num;
                num=cur->val;
                cur=cur->left;
            }
            
            return root;
        }
        return NULL;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
