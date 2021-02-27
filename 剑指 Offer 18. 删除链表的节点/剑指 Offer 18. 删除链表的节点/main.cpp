//
//  main.cpp
//  剑指 Offer 18. 删除链表的节点
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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*pre=dummy;
        ListNode*next=head;
        while(next!=nullptr){
            //删除next
            if(next->val==val){
                pre->next=pre->next->next;
                break;
            }
        }
        return dummy->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
