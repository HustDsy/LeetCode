//
//  main.cpp
//  面试题 02.01-移除重复节点
//
//  Created by 董深育 on 2020/7/28.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        int a[20000]={0};
        int hash=200001;
        if(head==NULL){
            return NULL;
        }
        ListNode*ret=new ListNode(head->val);
        a[head->val%hash]+=1;
        if(head->next==NULL){
            return ret;
        }
        ListNode*temp;
        temp=ret;
        head=head->next;
        while(head!=NULL){
            int val=head->val;
            int hashKey=val%hash;
            //第一次出现的话
            if(a[hashKey]==0){
                ListNode*node=new ListNode(val);
                temp->next=node;
                temp=temp->next;
            }
            a[hashKey]+=1;
            head=head->next;
        }
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    ListNode*node1=new ListNode(1);
    ListNode*node2=new ListNode(2);
    ListNode*node3=new ListNode(3);
    ListNode*node4=new ListNode(3);
    ListNode*node5=new ListNode(2);
    ListNode*node6=new ListNode(1);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    Solution s;
    ListNode*ret=s.removeDuplicateNodes(node1);
    return 0;
}
