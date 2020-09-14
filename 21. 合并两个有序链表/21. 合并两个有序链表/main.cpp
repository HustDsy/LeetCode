//
//  main.cpp
//  21. 合并两个有序链表
//
//  Created by 董深育 on 2020/9/14.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode():val(0),next(NULL){}
    ListNode(int x):val(x),next(NULL){}
    ListNode(int x,ListNode*next):val(x),next(next){}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*p=l1;
        ListNode*q=l2;
        ListNode*k=new ListNode(0);
        ListNode*r=k;
        while(p!=NULL||q!=NULL){
            if(p==NULL&&q!=NULL){
                r->next=q;
                q=NULL;
            }else if(p!=NULL&&q==NULL){
                r->next=p;
                p=NULL;
            }else{
                if(p->val<q->val){
                    r->next=new ListNode(p->val);
                    r=r->next;
                    p=p->next;
                }else if(p->val>q->val){
                    r->next=new ListNode(q->val);
                    r=r->next;
                    q=q->next;
                }else{
                    r->next=new ListNode(p->val);
                    r->next->next=new ListNode(q->val);
                    r=r->next->next;
                    q=q->next;
                    p=p->next;
                }
            }
            
        }
        
        return k->next;
    }
    //递归
     ListNode* mergeTwoLists_(ListNode* l1, ListNode* l2) {
         if(l1==NULL) return l2;
         if(l2==NULL) return l1;
         if(l1->val<l2->val){
             l1->next=mergeTwoLists_(l1->next, l2);
             return l1;
         }else{
             l2->next=mergeTwoLists_(l1, l2->next);
             return l2;
         }
     }
    
};
int main(int argc, const char * argv[]) {
     ListNode*l1=new ListNode(1);
    l1->next=new ListNode(2);
     l1->next->next=new ListNode(4);
    ListNode*l2=new ListNode(1);
    l2->next=new ListNode(3);
    Solution s;
    s.mergeTwoLists(l1, l2);
    return 0;
}
