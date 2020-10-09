//
//  main.cpp
//  141. 环形链表
//
//  Created by 董深育 on 2020/10/9.
//

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //为空的时候默认有环
        if (head==NULL) return false;
        ListNode*top=head;
        int flag=pow(10, 5)+1;
        while(top!=nullptr){
            if(top->val==flag) return true;
            top->val=flag;
            top=top->next;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
