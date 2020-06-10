;//
//  main.cpp
//  2-两数相加
//
//  Created by 董深育 on 2020/6/10.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode*next;
    ListNode(int x){
        val=x;
        next=NULL;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*result=new ListNode(0);
        ListNode*p=l1;
        ListNode*q=l2;
        ListNode*r=result;
        int carryBit=0;
        while(p!=NULL||q!=NULL){
            int x=(p==nullptr)?0:p->val;
            int y=(q==nullptr)?0:q->val;
            int sum=x+y+carryBit;
            r->next=new ListNode(sum%10);
            carryBit=sum/10;
            r=r->next;
            if(p!=NULL){
                p=(p->next!=nullptr)?p->next:nullptr;
            }
            if(q!=NULL){
                q=(q->next!=nullptr)?q->next:nullptr;
            }
        }
        //最后一次的判断
        if(carryBit==1){
            r->next=new ListNode(carryBit);
        }
        return result->next;
    }
};
int main(){
    ListNode*l1=new ListNode(1);
    l1->next=new ListNode(9);
    ListNode*l2=new ListNode(0);
    Solution s;
    ListNode*l3=s.addTwoNumbers(l1, l2);
    int num=l3->val;
    int num1=l3->next->val;
    cout<<num<<" "<<num1<<endl;
    return 0;
}


