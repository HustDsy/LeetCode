//
//  main.cpp
//  404. 左叶子之和
//
//  Created by 董深育 on 2020/9/19.
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        stack<TreeNode*>nodes;
        nodes.push(root);
        int ret=0;
        //根 左叶子 右叶子,左叶子接下来的节点肯定是根节点
        //前序遍历
        TreeNode*pre=NULL;
        while(!nodes.empty()){
            TreeNode*top=nodes.top();
            nodes.pop();
            //判断是不是左叶子,如果是左右叶子的话那么肯定有个根节点
            if(top->left==NULL&&top->right==NULL&&pre!=NULL&&pre->left==top){
                ret+=top->val;
            }
            if(top->right!=NULL){
                nodes.push(top->right);
            }
            if(top->left!=NULL){
                nodes.push(top->left);
            }
            pre=top;
        }
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    TreeNode*l1=new TreeNode(3);
    TreeNode*l2=new TreeNode(9);
    TreeNode*l3=new TreeNode(20);
    TreeNode*l4=new TreeNode(15);
    TreeNode*l5=new TreeNode(7);
    l1->left=l2;
    l1->right=l3;
    l3->left=l4;
    l3->right=l5;
    Solution s;
    s.sumOfLeftLeaves(l1);
    return 0;
}
