//
//  main.cpp
//  337. 打家劫舍 III
//
//  Created by 董深育 on 2020/8/3.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<map>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    map<TreeNode*,int>mymap;
    int rob(TreeNode* root) {
        if(root==NULL){
                  return 0;
              }
        if(mymap.count(root)){
            return mymap.at(root);
        }
      
        //抢这个点的话
        int do_it = root->val
        + (root->left == NULL ?
           0 : rob(root->left->left) + rob(root->left->right))
        + (root->right == NULL ?
           0 : rob(root->right->left) + rob(root->right->right));
        
        int not_do_it=rob(root->left)+rob(root->right);
        int ret=max(do_it,not_do_it);
        mymap.insert(pair<TreeNode*,int>(root,ret));
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
