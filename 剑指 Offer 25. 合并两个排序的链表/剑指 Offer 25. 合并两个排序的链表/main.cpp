//
//  main.cpp
//  剑指 Offer 25. 合并两个排序的链表
//
//  Created by dsy on 2021/2/26.
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
//    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//        if(!l1) return l2;
//        if(!l2) return l1;
//        if(l1->val<l2->val){
//            l1->next=mergeTwoLists(l1->next,l2);
//            return l1;
//        }else{
//             l2->next=mergeTwoLists(l1,l2->next);
//            return l2;
//        }
//    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode*l3=new ListNode(0);
        ListNode*l4=l3;
        if(!l1) return l2;
        if(!l2) return l1;
        while(l1&&l2){
            int x=l1->val;
            int y=l2->val;
            if(x==y){
                l4->next=new ListNode(x);
                l4->next->next=new ListNode(x);
                l4=l4->next->next;
                l1=l1->next;
                l2=l2->next;
            }else if(x<y){
                l4->next=new ListNode(x);
                l4=l4->next;
                l1=l1->next;
            }else{
                l4->next=new ListNode(y);
                l4=l4->next;
                l2=l2->next;
            }
        }
        ListNode*q=l1?l1:l2;
        l4->next=q;
        return l3->next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode*l1=new ListNode(1);
    l1->next=new ListNode(2);
    l1->next->next=new ListNode(4);
    ListNode*l2=new ListNode(1);
    l2->next=new ListNode(3);
    l2->next->next=new ListNode(4);
    Solution s;
    s.mergeTwoLists(l1, l2);
    return 0;
}
