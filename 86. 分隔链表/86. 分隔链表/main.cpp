//
//  main.cpp
//  86. 分隔链表
//
//  Created by dsy on 2021/1/4.
//

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(NULL) {}
};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* smallHead = small;
        ListNode* large = new ListNode(0);
        ListNode* largeHead = large;
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
