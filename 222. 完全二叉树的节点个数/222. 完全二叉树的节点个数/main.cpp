//
//  main.cpp
//  222. 完全二叉树的节点个数
//
//  Created by 董深育 on 2020/11/24.
//

#include <iostream>
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
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int cnt=0;
        queue<TreeNode*>nodes;
        nodes.push(root);
        while(nodes.empty()){
            int size=nodes.size();
            cnt+=size;
            while(size>0){
                TreeNode*top=nodes.front();
                nodes.pop();
                if(top->left!=NULL){
                    nodes.push(top->left);
                }
                if(top->right!=NULL){
                    nodes.push(top->right);
                }
                size--;
            }
            
        }
        return cnt;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
