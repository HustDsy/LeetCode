//
//  main.cpp
//  116. 填充每个节点的下一个右侧节点指针
//
//  Created by 董深育 on 2020/10/15.
//


#include <iostream>
#include<queue>
using namespace std;




class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>nodes;
        if(root==NULL)return root;
        Node*top=root;
        nodes.push(top);
        while(!nodes.empty()){
            int size=(int)nodes.size();
            Node*pre=NULL;
            while(size>0){
                top=nodes.front();
                nodes.pop();
                if(pre){
                    pre->next=top;
                }
                pre=top;
                size--;
                if(top->left) nodes.push(top->left);
                if(top->right) nodes.push(top->right);
    
            }
        }
        return root;
    }
};

int main(int argc, const char * argv[]) {
    Node*root=new Node(1);
    Node*root1=new Node(2);
    Node*root2=new Node(3);
    root->left=root1;
    root->right=root2;
    Solution s;
    s.connect(root);
    return 0;
}
