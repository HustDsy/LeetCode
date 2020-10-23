//
//  main.cpp
//  234. 回文链表
//
//  Created by 董深育 on 2020/10/23.
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
    bool isPalindrome(ListNode* head) {
        //利用双指针，让一个指针指向中间，一个指向结尾
        if(head==NULL)return true;
        ListNode*pre=NULL;
        ListNode*first=head;
        ListNode*second=head;
        while(second){
            //first=first->next;
            ListNode*temp=first->next;
            if(pre) {
                pre->next=temp;
                first->next=pre;
            }
            pre=first;
            first=temp;
            second=second->next==NULL?NULL:second->next->next;
        }
        
        second=pre;
        
        while(first){
            int fval=first->val;
            int sval=second->val;
            if(fval!=sval) return false;
            second=second->next;
            first=first->next;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    ListNode *head=new ListNode(1);
    ListNode *head1=new ListNode(2);
    ListNode *head2=new ListNode(2);
    ListNode *head3=new ListNode(1);
    head->next=head1;
    head1->next=head2;
   head2->next=head3;
    s.isPalindrome(head);
    return 0;
}
