//
//  main.cpp
//  590. N叉树的后序遍历
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
    //递归
    vector<int>ret;
    vector<int> postorder(Node* root) {
        if(root==NULL){
            return {};
        }
        for(int i=0;i<root->children.size();i++){
            postorder(root->children[i]);
        }
        ret.push_back(root->val);
        return ret;
    }
    //迭代
    vector<int> postorder_it(Node* root) {
        if(root==NULL){
            return {};
        }
        stack<Node*>mystack;
        vector<int>myret;
        Node*pre=NULL;
        mystack.push(root);
        while(!mystack.empty()){
            Node*top=mystack.top();
            int size=(int)top->children.size();
            if(size==0||(pre!=NULL&&find(top->children.begin(), top->children.end(), pre)!=top->children.end())){
                myret.push_back(top->val);
                pre=top;
                mystack.pop();
            }else{
                for(int i=size-1;i>=0;i--){
                    mystack.push(top->children[i]);
                }
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
