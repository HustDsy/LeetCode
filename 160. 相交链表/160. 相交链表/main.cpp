//
//  main.cpp
//  160. 相交链表
//
//  Created by dsy on 2021/6/4.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*p=headA;
        ListNode*q=headB;
        //if(p==nullptr||q==nullptr) return nullptr;
        while(p!=q){
            p=p==nullptr?headB:p->next;
            q=q==nullptr?headA:q->next;
        }
        return p;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
