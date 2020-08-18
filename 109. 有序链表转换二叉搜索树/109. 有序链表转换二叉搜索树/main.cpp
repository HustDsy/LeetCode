//
//  main.cpp
//  109. 有序链表转换二叉搜索树
//
//  Created by 董深育 on 2020/8/18.
//  Copyright © 2020 董深育. All rights reserved.
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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return new TreeNode(head->val);
        }
        //找到中点
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            dummy=dummy->next;
            slow=slow->next;
            fast=fast->next->next;
        }
        dummy->next=nullptr;
        TreeNode*root=new TreeNode(slow->val);
        root->right=sortedListToBST(slow->next);
        root->left=sortedListToBST(head);
        return root;
        
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
