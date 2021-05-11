//
//  main.cpp
//  872. 叶子相似的树
//
//  Created by dsy on 2021/5/10.
//

#include <iostream>
#include<vector>
using  namespace std;


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
    void dfs(TreeNode* root1,vector<int>&v){
        if(root1->left==nullptr&& root1->right==nullptr){
            v.emplace_back(root1->val);
        }
        if(root1->left){
            dfs(root1->left,v);
        }
         if(root1->right){
            dfs(root1->right,v);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        vector<int>v2;
         if(root1){
            dfs(root1,v1);
        }
         if(root2){
            dfs(root2,v2);
        }
        return v1==v2;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
