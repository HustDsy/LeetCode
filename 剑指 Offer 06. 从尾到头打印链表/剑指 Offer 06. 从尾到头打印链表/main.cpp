//
//  main.cpp
//  剑指 Offer 06. 从尾到头打印链表
//
//  Created by dsy on 2021/2/25.
//

#include <iostream>
#include<vector>
#include<stack>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int>res;
        stack<int>s;
        ListNode*p=head;
        while(p!=nullptr){
            s.push(p->val);
            p=p->next;
        }
        while(!s.empty()){
            res.emplace_back(s.top());
            s.pop();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
