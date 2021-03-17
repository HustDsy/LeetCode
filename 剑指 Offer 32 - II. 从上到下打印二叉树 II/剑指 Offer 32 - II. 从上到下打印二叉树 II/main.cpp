//
//  main.cpp
//  剑指 Offer 32 - II. 从上到下打印二叉树 II
//
//  Created by dsy on 2021/3/1.
//

#include <iostream>
#include<queue>
using namespace std;

struct TreeNode{
    TreeNode*left;
    TreeNode*right;
    int val;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>q;
        if(!root) return {};
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int s=size;
            vector<int>temp;
            while(size){
                TreeNode*top=q.front();
                q.pop();
                //true的话从后向前存放数据 第一个遍历的数据放到容器尾部
                temp.emplace_back(top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                size--;
            }
            res.emplace_back(temp);
        }
        return  res;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
