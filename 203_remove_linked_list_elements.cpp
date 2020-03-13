//
//  203_remove_linked_list_elements.cpp
//  test
//
//  Created by ley on 2020/3/13.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* tmphead=head;
        while(head!=nullptr&&head->val==val){
            head=head->next;
        }
        tmphead=head;
        ListNode* tail=head;
        if(head!=nullptr) head=head->next;
        while(head!=nullptr){
            if(head->val!=val){
                tail->next=head;
                tail=head;
                head=head->next;
            }else{
                head=head->next;
            }
        }
        if(tail!=nullptr) tail->next=nullptr;
        return tmphead;
        
        
    }
};
