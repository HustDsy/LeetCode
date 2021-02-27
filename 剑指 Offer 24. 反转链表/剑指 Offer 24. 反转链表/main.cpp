//
//  main.cpp
//  剑指 Offer 24. 反转链表
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
//    ListNode* reverseList(ListNode* head) {
//        if(!head||!head->next) return head;
//        ListNode*back=reverseList(head->next);
//        head->next->next=head;
//        head->next=NULL;
//        return back;
//    }
    
    ListNode* reverseList(ListNode* head) {
          ListNode* prev = nullptr;
          ListNode* curr = head;
          while (curr) {
              ListNode* next = curr->next;
              curr->next = prev;
              prev = curr;
              curr = next;
          }
          return prev;
      }


};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
