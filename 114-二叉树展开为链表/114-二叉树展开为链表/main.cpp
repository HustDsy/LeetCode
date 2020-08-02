//
//  main.cpp
//  114-二叉树展开为链表
//
//  Created by 董深育 on 2020/8/2.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<stack>
#include<vector>
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

    void flatten(TreeNode* root) {
        vector<TreeNode*>val;
        stack<TreeNode*>mystack;
        TreeNode*temp=root;
        while(temp!=NULL||!mystack.empty()){
            while(temp!=NULL){
                val.push_back(temp);
                mystack.push(temp);
                temp=temp->left;
            }
            temp=mystack.top();
            mystack.pop();
            temp=temp->right;
        }
        /*
         mtstack.push(temp);
         while(!mystack.empty){
         TreeNode*kk=mystack.top();
         mystack.pop();
         if(kk->right！=NULL){
         mysatck.push(kk->right);
         }
         if(kk->left！=NULL){
         mysatck.push(kk->left);
         }
         }
         */
        int size = val.size();
        for (int i = 1; i < size; i++) {
            auto prev = val.at(i - 1), curr = val.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
