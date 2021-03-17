//
//  main.cpp
//  剑指 Offer 35. 复杂链表的复制
//
//  Created by dsy on 2021/3/1.
//

#include <iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*, Node*>n;
        Node*p=head;
        while(p){
            Node*temp=new Node(p->val);
            n[p]=temp;
            p=p->next;
        }
        p=head;
        while(p){
            n[p]->next=n[p->next];
            n[p]->random=n[p->random];
            p=p->next;
        }
        return  n[head];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
