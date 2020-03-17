//
//  206_reverse_linked_list.cpp
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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* tmplast=head;
        head=head->next;
        tmplast->next=nullptr;
        while(head!=nullptr){
            ListNode* nextone=head->next;
            head->next=tmplast;
            tmplast=head;
            head=nextone;
        }
        return tmplast;
        
    }
};
