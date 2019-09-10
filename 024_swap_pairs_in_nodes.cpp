//
//  024_swap_pairs_in_nodes.cpp
//  test
//
//  Created by ley on 2019/9/8.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* tmp_head;
        ListNode* tmp2;
        tmp_head=head;
        
        if (head==nullptr) {
            return head;
        }
        
        if(head->next!=nullptr){
        tmp2=head->next;
        tmp_head->next=tmp2->next;
        tmp2->next=tmp_head;
        }else{
            return head;
        }
        
        if(tmp_head->next!=nullptr) {
            tmp_head->next=swapPairs(tmp_head->next);
        }else{
            return tmp2;
        }
        
        return tmp2;
        
    }
};
