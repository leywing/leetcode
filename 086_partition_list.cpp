//
//  086_partition_list.cpp
//  test
//
//  Created by ley on 2019/12/18.
//  Copyright © 2019 ley. All rights reserved.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before=nullptr;
        ListNode* after=nullptr;
        ListNode* after_head=nullptr;
        ListNode* before_head=nullptr;
        
        if(head==nullptr) return head;
        
        ListNode* tmp=head;
        while(1){
            if(tmp->val<x){
                if(before==nullptr){
                    before_head=tmp;
                    before=tmp;
                }else{
                    before->next=tmp;
                    before=tmp;
                }
            }else{
                //  >=
                if(after==nullptr){
                    after_head=tmp;
                    after=tmp;
                }else{
                    after->next=tmp;
                    after=tmp;
                }
            }
            if(tmp->next==nullptr) break;
            tmp=tmp->next;
        }
        
        if(before==nullptr||after==nullptr) return head;
        else{
            before->next=after_head;
            after->next=nullptr;
            return before_head;
        }
        
    }
};
