//
//  main.cpp
//  82. 删除排序链表中的重复元素 II
//
//  Created by dsy on 2021/3/25.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode*dummy=new ListNode(101);
        dummy->next=head;
        ListNode*pre=dummy;
        ListNode*prepre=dummy;
        ListNode*cur=head;
        //这里cur是当前节点
        //pre是cur之前的节点
        //prepre是pre之前的节点
        while(cur){
            //如果pre->val==cur->val 都得删除
            if(pre->val==cur->val){
                while(cur&&pre->val==cur->val){
                    cur=cur->next;
                }
                prepre->next=cur;
                pre=prepre;
            }else{
                prepre=pre;
                pre=cur;
                cur=cur->next;
            }
        }
        return dummy->next;
    }
};
