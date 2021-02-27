//
//  main.cpp
//  剑指 Offer 22. 链表中倒数第k个节点
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode*p=head;
        ListNode*q=head;
        int cnt=1;
        while(q!=nullptr){
            q=q->next;
            if(cnt>=k&&q){
                p=p->next;
            }
            cnt++;
        }
        return  p;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
