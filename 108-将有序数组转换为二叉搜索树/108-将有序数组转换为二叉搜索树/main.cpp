//
//  main.cpp
//  108-将有序数组转换为二叉搜索树
//
//  Created by 董深育 on 2020/7/3.
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

//二叉搜索树的中序遍历就是一个升序数组
class Solution {
public:
    TreeNode*dfs(int left,int right,vector<int>&nums){
        if(left>right){
            return nullptr;
        }
        int mid=(left+right)/2;
        TreeNode*node=new TreeNode(nums[mid]);
       
        node->left=dfs(left,mid-1,nums);
        node->right=dfs(mid+1,right,nums);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(0,nums.size()-1,nums);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
