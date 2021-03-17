//
//  main.cpp
//  剑指 Offer 32 - III. 从上到下打印二叉树 III
//
//  Created by dsy on 2021/3/1.
//

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>q;
        if(!root) return {};
        q.push(root);
        bool cur=true;
        while(!q.empty()){
            int size=q.size();
            int s=size;
            vector<int>temp;
            temp.resize(size);
            while(size){
                TreeNode*top=q.front();
                q.pop();
                //true的话从后向前存放数据 第一个遍历的数据放到容器尾部
                int index=!cur?size-1:s-size;
                temp[index]=top->val;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                size--;
            }
            cur=!cur;
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
