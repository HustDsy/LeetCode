//
//  main.cpp
//  24. 两两交换链表中的节点
//
//  Created by 董深育 on 2020/8/17.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
using namespace std;





struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    //递归
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode*next=head->next;
        head->next=swapPairs(next->next);
        next->next=head;
        return next;
    }
    //迭代
    ListNode* swapPairs_iterator(ListNode* head) {
         if(head==NULL||head->next==NULL){
             return head;
         }
        //记录返回的头结点
        ListNode*dummy=new ListNode(-1);
        
        ListNode*pre=dummy;
        dummy->next=head;
        while(head&&head->next){
            ListNode*firstNode=head;
            ListNode*second=head->next;
        
            
            pre->next=second;
            firstNode->next=second->next;
            second->next=firstNode;
            
            pre=firstNode;
            head=firstNode->next;
        }
        return dummy->next;
     }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
