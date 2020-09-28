//
//  main.cpp
//  117. 填充每个节点的下一个右侧节点指针 II
//
//  Created by 董深育 on 2020/9/28.
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
        if(root==NULL) return NULL;
        queue<Node*>nodes;
        nodes.push(root);
        while(!nodes.empty()){
            //读取这一层的数据
            int size=(int)nodes.size();
            Node*next=NULL;
            while(size>0){
                Node*top=nodes.front();
                nodes.pop();
                top->next=next;
                if(top->right!=NULL) nodes.push(top->right);
                if(top->left!=NULL) nodes.push(top->left);
                next=top;
                size--;
            }
        }
        return root;
    }
};

int main(int argc, const char * argv[]) {
    Node*l1=new Node(1);
    Node*l2=new Node(2);
    Node*l3=new Node(3);
    Node*l4=new Node(4);
    Node*l5=new Node(5);
    Node*l6=new Node(7);
    l1->left=l2;
    l1->right=l3;
    l2->left=l4;
    l2->right=l5;
    l3->right=l6;
    Solution s;
    s.connect(l1);
    return 0;
}
