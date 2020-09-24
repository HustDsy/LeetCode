//
//  main.cpp
//  501. 二叉搜索树中的众数
//
//  Created by 董深育 on 2020/9/24.
//

#include <iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode{
    TreeNode*left;
    TreeNode*right;
    int val;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solutio{
public:
    vector<int>ret;
    vector<int> findMode(TreeNode* root){
        if(root==NULL)return {};
        //建议中序遍历
        vector<int>nums;
        stack<TreeNode*>nodes;
        TreeNode*top=root;
        while(!nodes.empty()||top!=NULL){
            while(top!=NULL){
                nodes.push(top);
                top=top->left;
            }
            top=nodes.top();
            nodes.pop();
            nums.push_back(top->val);
            top=top->right;
        }
        int curmax=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(i==0) count++;
            if(i>0&&nums[i]==nums[i-1]) count++;
            if(i>0&&nums[i]!=nums[i-1]) {
                if(curmax==count){
                    ret.push_back(nums[i-1]);
                }
                if(curmax<count){
                    curmax=count;
                    ret.clear();
                    ret.push_back(nums[i-1]);
                }
                count=1;
            }
        }
        //最后一个还没比较
        if(curmax==count){
            ret.push_back(nums.back());
        }
        if(curmax<count){
            ret.clear();
            ret.push_back(nums.back());
        }
        return ret;
    }
    
};

int main(int argc, const char * argv[]) {
    Solutio s;
    TreeNode*l1=new TreeNode(1);
    TreeNode*l2=new TreeNode(2);
    //TreeNode*l3=new TreeNode(2);
    l1->right=l2;
    //l2->left=l3;
    s.findMode(l1);
    return 0;
}
