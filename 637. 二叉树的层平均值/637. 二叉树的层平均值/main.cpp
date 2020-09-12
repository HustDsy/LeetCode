;
//
//  main.cpp
//  637. 二叉树的层平均值
//
//  Created by 董深育 on 2020/9/12.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int val):val(val),left(NULL),right(NULL){}
};

class Solution{
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<double>ret;
        queue<TreeNode*>myqueue;
        myqueue.push(root);
        while(!myqueue.empty()){
            int size=(int)myqueue.size();
            int cnt=size;
            double sum=0;
            while(size>0){
                TreeNode*front=myqueue.front();
                myqueue.pop();
                sum+=front->val;
                if(front->left){
                    myqueue.push(front->left);
                }
                if(front->right){
                    myqueue.push(front->right);
                }
                size--;
            }
            ret.push_back(sum/cnt);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
