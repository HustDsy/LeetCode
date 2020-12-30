//
//  main.cpp
//  147. 对链表进行插入排序
//
//  Created by dsy on 2020/12/24.
//

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
     ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
         ListNode*dummy=new ListNode(0);
         dummy->next=head;
         ListNode*target=head->next;//从第二个节点开始插入
         head->next=NULL;
     
         //for循环开始遍历
         while(target!=NULL){
             //需要插入在temp之前
             ListNode*pre=dummy;//比较的节点之前的节点
             ListNode*temp=dummy->next;//从head开始比较
             while(temp&&temp->val<target->val){
                 temp=temp->next;
                 pre=pre->next;
             }
             ListNode*p=target;
             target=target->next;
             pre->next=p;
             p->next=temp;
         }
         return dummy->next;
    }
};
int main(int argc, const char * argv[]) {
    ListNode*l=new ListNode(4);
    ListNode*l1=new ListNode(2);
    ListNode*l2=new ListNode(1);
    ListNode*l3=new ListNode(3);
    l->next=l1;
    l1->next=l2;
    l2->next=l3;
    Solution s;
    s.insertionSortList(l);
    return 0;
}
