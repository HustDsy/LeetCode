//
//  main.cpp
//  Morris遍历
//
//  Created by 董深育 on 2020/9/24.
//

#include <iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
    //中序遍历
    //中序遍历需要将最左边的节点先输出
    vector<int>mindle_traversal(TreeNode*root){
        vector<int>ret;
        if(root==NULL)return ret;
        TreeNode*cur=root;
        TreeNode*pre=NULL;
        while(!cur){
            //当cur的左子树为空的话，输出当前节点，并且让它指向右节点
            if(!cur->left){
                ret.emplace_back(cur->val);
                cur=cur->right;
                continue;//懒得写else
            }
            //当这个节点的左子树不为空的话，找到它的前驱节点.
            pre=cur->left;
            while(pre->right!=NULL&&pre->right!=cur){
                pre=pre->right;
            }
            //如果找到了前驱节点的话，让它指向当前的root，这个举个例子吧比如树(层序遍历1 2 3 4 5)中序遍历(4 2 5 1 3)
            //1的前驱结点就是5
            if(pre->right==NULL){
                pre->right=cur;
                cur=cur->left;
            }else{
                //将当前cur的值输出来。并且切断pre和它之间的联系
                //此时的pre满足 pre->right=cur
                ret.push_back(cur->val);
                pre->right=NULL;
                cur=cur->right;
            }
        }
        return ret;
        
    }
    //前序遍历
    vector<int>preorder_traversal(TreeNode*root){
        vector<int>ret;
        if(root==NULL)return ret;
        TreeNode*cur=root;
        TreeNode*pre=NULL;
        while(!cur){
            //当cur的左子树为空的话，输出当前节点，并且让它指向右节点
            if(!cur->left){
                ret.emplace_back(cur->val);
                cur=cur->right;
                continue;//懒得写else
            }
            //当这个节点的左子树不为空的话，找到它的前驱节点.
            pre=cur->left;
            while(pre->right!=NULL&&pre->right!=cur){
                pre=pre->right;
            }
            //如果找到了前驱节点的话，让它指向当前的root，这个举个例子吧比如树(层序遍历1 2 3 4 5)中序遍历(4 2 5 1 3)
            //1的前驱结点就是5
            //前序遍历需要先输出一遍cur
            if(pre->right==NULL){
                ret.push_back(cur->val); //更改一下输出顺序就行
                pre->right=cur;
                cur=cur->left;
            }else{
                //将当前cur的值输出来。并且切断pre和它之间的联系
                pre->right=NULL;
                cur=cur->right;
            }
        }
        return ret;
    }
    //后序遍历
    void reverse(TreeNode *from, TreeNode *to) // reverse the tree nodes 'from' -> 'to'.
    {
        if (from == to)
            return;
        TreeNode *x = from, *y = from->right, *z;
        while (true)
        {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
            if (x == to)
                break;
        }
    }

    void printReverse(TreeNode* from, TreeNode *to) // print the reversed tree nodes 'from' -> 'to'.
    {
        reverse(from, to);

        TreeNode *p = to;
        while (true)
        {
            printf("%d ", p->val);
            if (p == from)
                break;
            p = p->right;
        }

        reverse(to, from);
    }

    void postorderMorrisTraversal(TreeNode *root) {
        TreeNode dump(0);
        dump.left = root;
        TreeNode *cur = &dump, *prev = NULL;
        while (cur)
        {
            if (cur->left == NULL)
            {
                cur = cur->right;
            }
            else
            {
                prev = cur->left;
                while (prev->right != NULL && prev->right != cur)
                    prev = prev->right;

                if (prev->right == NULL)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    printReverse(cur->left, prev);  // call print
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
