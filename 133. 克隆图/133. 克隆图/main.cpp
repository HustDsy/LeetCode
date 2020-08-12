//
//  main.cpp
//  133. 克隆图
//
//  Created by 董深育 on 2020/8/12.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        unordered_map<Node*, Node*> visited;
        //广度优先遍历
        queue<Node*>myqueue;
        visited[node]=new Node(node->val);
        myqueue.push(node);
        while(!myqueue.empty()){
            Node*temp=myqueue.front();
            myqueue.pop();
            for(Node*kk:temp->neighbors){
                if(visited.find(kk)==visited.end()){
                    myqueue.push(kk);
                    visited[kk]=new Node(kk->val);
                }
                visited[temp]->neighbors.push_back(visited[kk]);
            }
        }
        return visited[node];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
