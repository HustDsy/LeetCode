//
//  main.cpp
//  654. 最大二叉树
//
//  Created by 董深育 on 2020/8/18.
//  Copyright © 2020 董深育. All rights reserved.
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
    int getmax(int begin,int end,vector<int>nums){
        
        int max_i=begin;
        for(int i=begin;i<end;i++){
            if(nums[max_i]<nums[i]){
                max_i=i;
            }
        }
        return max_i;
    }
    TreeNode*buildTree(int begin,int end,vector<int>nums){
        if(begin==end){
            return NULL;
        }
        int max=getmax(begin, end, nums);
        TreeNode*root=new TreeNode(nums[max]);
        root->left=buildTree(begin, max, nums);
        root->right=buildTree(max+1, end, nums);
        return root;
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=(int)nums.size();
        if(n==0){
            return NULL;
        }
        return buildTree(0, n, nums);
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int>aa={3,2,1,6,0,5};
    Solution s;
    s.buildTree(0, 5, aa);
    return 0;
}
