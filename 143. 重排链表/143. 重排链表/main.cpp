//
//  main.cpp
//  143. 重排链表
//
//  Created by 董深育 on 2020/10/20.
//

#include <iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        //将所有节点保存起来
        vector<ListNode*>nodes;
        ListNode*top=head;
        int len=0;
        while(top!=NULL){
            nodes.emplace_back(top);
            len++;
            top=top->next;
        }
        //双指针
        int i=0;
        int j=len-1;
        while(i<j){
            ListNode*first=nodes[i];
            ListNode*second=nodes[j];
            second->next=first->next==second?NULL:first->next;
            first->next=second;
            j--;
            i++;
        }
        if(i==j){
            ListNode*temp=nodes[i];
            temp->next=NULL;
        }
    }
};

int main(int argc, const char * argv[]) {
    ListNode*nod1=new ListNode(1);
    ListNode*nod2=new ListNode(2);
    ListNode*nod3=new ListNode(3);
    nod1->next=nod2;
    nod2->next=nod3;
    Solution s;
    s.reorderList(nod1);
    return 0;
}
