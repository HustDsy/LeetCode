//
//  main.cpp
//  328. 奇偶链表
//
//  Created by 董深育 on 2020/11/13.
//

#include <iostream>
using namespace std;




  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)return head;
        //p是奇数节点
        ListNode*p=head;
        //q是偶数结点
        ListNode*q=head->next;
        ListNode*top=q;
        while(q!=NULL&&q->next!=NULL){
            p->next=q->next;
            p=p->next;
            q->next=p->next;
            q=q->next;
        }
        p->next=top;
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
