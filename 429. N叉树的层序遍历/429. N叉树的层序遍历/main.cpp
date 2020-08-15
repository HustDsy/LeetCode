//
//  main.cpp
//  429. N叉树的层序遍历
//
//  Created by 董深育 on 2020/8/15.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL){
            return {};
        }
        queue<Node*>myqueue;
        myqueue.push(root);
        vector<vector<int>>myret;
        vector<int>ret;
        int currsize=1;//本层size
        int nextsize=0;//下一层siz
        while(!myqueue.empty()){
            Node*temp=myqueue.front();
            myqueue.pop();
            if(currsize>0){
                ret.push_back(temp->val);
                nextsize+=temp->children.size();
                for(int i=0;i<temp->children.size();i++){
                    myqueue.push(temp->children[i]);
                }
                currsize--;
            }
            if(currsize==0){
                myret.push_back(ret);
                ret={};
                currsize=nextsize;
                nextsize=0;
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
