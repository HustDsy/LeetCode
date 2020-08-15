//
//  main.cpp
//  589. N叉树的前序遍历
//
//  Created by 董深育 on 2020/8/15.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<stack>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int>ret;
    //递归
    vector<int> preorder(Node* root) {
        if(root==nullptr){
            return {};
        }
        ret.push_back(root->val);
        for(int i=0;i<root->children.size();i++){
            preorder(root->children[i]);
        }
        return ret;
    }
    //迭代
    vector<int> preorder_it(Node* root) {
        if(root==NULL){
            return {};
        }
        vector<int>myret;
        stack<Node*>mystack;
        mystack.push(root);
        while(!mystack.empty()){
            Node*top=mystack.top();
            mystack.pop();
            myret.push_back(top->val);
            for(int i=top->children.size()-1;i>=0;i--){
                mystack.push(top->children[i]);
            }
            
        }
        return myret;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
