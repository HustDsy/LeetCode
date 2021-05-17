//
//  main.cpp
//  993. 二叉树的堂兄弟节点
//
//  Created by dsy on 2021/5/17.
//

#include <iostream>
#include<queue>
using namespace std;

struct TreeNode{
    TreeNode*left;
    TreeNode*right;
    int val;
    TreeNode(int val):val(val),left(nullptr),right(nullptr){}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        if(!root) return false;
        TreeNode*p1(nullptr);
        TreeNode*p2(nullptr);
        q.push(root);
        while(!q.empty()&&!p1&&!p2){
            int size=q.size();
            while(size--){
                TreeNode*cur=q.front();
                q.pop();
                if(cur->left){
                    q.push(cur->left);
                    if(cur->left->val==x){
                        p1=cur;
                    }
                     if(cur->left->val==y){
                        p2=cur;
                    }
                }
                if(cur->right){
                    q.push(cur->right);
                    if(cur->right->val==x){
                        p1=cur;
                    }
                     if(cur->right->val==y){
                        p2=cur;
                    }
                }
            }
        
        }
        return p1&&p2&&p1!=p2;
     }
};

int main(int argc, const char * argv[]) {
    Solution s;
    TreeNode *root=new TreeNode(1);
 
    TreeNode *root1=new TreeNode(2);
    TreeNode *root2=new TreeNode(3);
    root->left=root1;
    root->right=root2;
    TreeNode *root3=new TreeNode(4);
    TreeNode *root4=new TreeNode(5);
    root1->right=root3;
    root2->right=root4;
    s.isCousins(root, 5, 4);
    return 0;
}
