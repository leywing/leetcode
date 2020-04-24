//
//  237_delete_node_in_a_linked_list.cpp
//  test
//
//  Created by ley on 2020/4/24.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* tmp=node->next;
        while(tmp->next!=nullptr){
            node->val=tmp->val;
            node=node->next;
            tmp=tmp->next;
        }
        node->next=nullptr;
    }
};
