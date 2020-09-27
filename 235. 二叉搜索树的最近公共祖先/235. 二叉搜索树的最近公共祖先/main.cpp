//
//  main.cpp
//  235. 二叉搜索树的最近公共祖先
//
//  Created by 董深育 on 2020/9/27.
//

#include <iostream>
#include<vector>
using namespace std;

struct TreeNode{
    TreeNode*left;
    TreeNode*right;
    int val;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        //查找节点1
        TreeNode*top1=root;
        while(top1!=NULL){
            path1.push_back(top1);
            if(top1->val==p->val){
                break;
            }else if(top1->val>p->val){
                top1=top1->left;
            }else{
                top1=top1->right;
            }
        }
        top1=root;
        while(top1!=NULL){
            path2.push_back(top1);
            if(top1->val==q->val){
                break;
            }else if(top1->val>q->val){
                top1=top1->left;
            }else{
                top1=top1->right;
            }
        }
        int len=path1.size()>path2.size()?path2.size():path1.size();
        for(int i=0;i<len;i++){
            if(path1[i]->val!=path2[i]->val){
                return path1[i-1];
            }
        }
        return path1[len-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
