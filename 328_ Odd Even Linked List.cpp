//
//  328_ Odd Even Linked List.cpp
//  test
//
//  Created by ley on 2020/6/6.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        
        ListNode* tmp_odd=odd;
        ListNode* tmp_even=even;
        
        head=head->next->next;
        while(head!=nullptr && head->next!=nullptr){
            ListNode* t1=head;
            ListNode* t2=head->next;
            head=head->next->next;
            
            tmp_odd->next=t1;
            tmp_odd=t1;
            
            tmp_even->next=t2;
            tmp_even=t2;
        }
        
        if(head!=nullptr){
            tmp_odd->next=head;
            tmp_odd=head;
        }
        
        
        tmp_odd->next=even;
        tmp_even->next=nullptr;
        return odd;
    }
};
