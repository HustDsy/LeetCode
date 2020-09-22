//
//  main.cpp
//  968. 监控二叉树
//
//  Created by 董深育 on 2020/9/22.
//

#include <iostream>
using namespace std;
  
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
   
    int result=0;
       //0:可被观测但无监控，上一层节点为1
          //1：不可被观测到，上一层节点为2
          //2：有摄像机，上一层节点为0
       int dfs(TreeNode*root){
           if(root==NULL){
               return 0;
           }
           int leftStatus = dfs(root->left),rightStatus = dfs(root->right);
           if(leftStatus==1||rightStatus==1){
               result++;
               return 2;
           }else if(leftStatus==2||rightStatus==2){
               return 0;
           }else{
               return 1;
           }
       }
       int minCameraCover(TreeNode* root) {
           if(dfs(root)==1){
               result++;
           }
           return result;
       }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
