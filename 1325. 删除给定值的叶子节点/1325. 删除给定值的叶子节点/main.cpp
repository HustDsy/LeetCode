//
//  main.cpp
//  1325. 删除给定值的叶子节点
//
//  Created by dsy on 2021/5/12.
//

#include <iostream>
using namespace std;


 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
public:
    bool end;
    void dfs(TreeNode* root, int target,TreeNode*pre,int flag){
        if(!root) return;
        if(root->right){
            dfs(root->right,target,root,0);
        }
        if(root->left){
            dfs(root->left,target,root,1);
        }
        if(root->val==target&&root->left==nullptr&&root->right==nullptr){
            if(flag==1){
                pre->left=nullptr;
                delete pre->left;
            }else if(flag==0){
                pre->right=nullptr;
                delete pre->right;
            }else{
                root=nullptr;
                delete root;
                end=true;
            }
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return root;
        //排除root为叶节点
        if(!root->left&&!root->right&&root->val==target) return nullptr;
        end=false;
        dfs(root,target,nullptr,-1);
        return end?nullptr:root;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(1);
    root->right=new TreeNode(1);
    s.removeLeafNodes(root, 1);
    return 0;
}
