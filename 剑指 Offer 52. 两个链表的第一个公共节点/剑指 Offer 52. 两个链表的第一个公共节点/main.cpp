//
//  main.cpp
//  剑指 Offer 52. 两个链表的第一个公共节点
//
//  Created by dsy on 2021/3/2.
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
        while(p!=q){
            p=p?p->next:headB;
            q=q?q->next:headA;
        }
        return p;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
