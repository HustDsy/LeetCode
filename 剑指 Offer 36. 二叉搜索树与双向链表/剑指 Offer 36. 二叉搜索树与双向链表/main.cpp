//
//  main.cpp
//  剑指 Offer 36. 二叉搜索树与双向链表
//
//  Created by dsy on 2021/3/1.
//

#include <iostream>
#include<stack>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        stack<Node*>s;
        Node*head=nullptr;
        Node*p=nullptr;
        Node*tail=nullptr;
        while(root||!s.empty()){
            while(root){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            tail=root;
            if(!head) {
                head=root;
                p=root;
                }else{
                    p->right=root;
                    root->left=p;
                    p=p->right;
                   
                }
            root=root->right;
        }
        head->left=tail;
        tail->right=head;
        return head;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    Node *root=new Node(4);
    Node *root1=new Node(2);
    Node *root2=new Node(5);
    Node *root3=new Node(1);
    Node *root4=new Node(3);
    root->left=root1;
    root->right=root2;
    root1->left=root3;
    root1->right=root4;
    
    s.treeToDoublyList(root);
    return 0;
}
