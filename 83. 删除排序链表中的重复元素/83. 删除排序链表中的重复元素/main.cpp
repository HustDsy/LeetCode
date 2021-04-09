//
//  main.cpp
//  83. 删除排序链表中的重复元素
//
//  Created by dsy on 2021/3/26.
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
        ListNode*pre=nullptr;
        ListNode*cur=head;
        while(cur){
            if(pre&&cur&&pre->val==cur->val){
                while(pre&&cur&&pre->val==cur->val){
                    cur=cur->next;
                }
                pre->next=cur;
            }
            else{
                pre=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
