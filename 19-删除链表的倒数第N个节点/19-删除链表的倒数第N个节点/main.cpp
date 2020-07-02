//
//  main.cpp
//  19-删除链表的倒数第N个节点
//
//  Created by 董深育 on 2020/7/2.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x){
        val=x;
        next=NULL;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //创建一个虚拟头结点
        ListNode*virtualHead=new ListNode(0);
        virtualHead->next=head;
        ListNode*temp=virtualHead;
        //倒数第n个节点 也就是正数第size-n+1个节点
        int size=0;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        //加了个虚拟节点，所以目标节点也得加1
        int target=size-n+1;
        temp=virtualHead;
        //找到被删除的节点的前一个节点
        for(int i=0;i<target-2;i++){
            temp=temp->next;
        }
        ListNode*del=temp->next;
        temp->next=del->next;
        return virtualHead->next;
    }
     
};

int main(int argc, const char * argv[]) {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next=&b;
    b.next=&c;
    c.next=&d;
    d.next=&e;
    Solution s;
    ListNode*res=s.removeNthFromEnd(&a, 2);
    return 0;
}
