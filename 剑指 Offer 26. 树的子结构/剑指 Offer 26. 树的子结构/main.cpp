//
//  main.cpp
//  剑指 Offer 26. 树的子结构
//
//  Created by dsy on 2021/2/26.
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
    bool dfs(TreeNode*A,TreeNode*B){
        if(!B) return true;
        if(!A) return false;
        if(B->val!=A->val){
            return false;
        }
        return dfs(A->left,B->left)&&dfs(A->right,B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A||!B) return  false;
        bool res=false;
        if(A->val==B->val) res=dfs(A,B);
        if(!res) res=isSubStructure(A->left, B);
        if(!res) res=isSubStructure(A->right, B);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
