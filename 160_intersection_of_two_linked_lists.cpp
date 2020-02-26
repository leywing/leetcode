//
//  160_intersection_of_two_linked_lists.cpp
//  test
//
//  Created by ley on 2020/2/25.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmp1=headA;
        ListNode* tmp2=headB;
        while(tmp1!=tmp2){
            tmp1=tmp1?tmp1->next:headB;
            tmp2=tmp2?tmp2->next:headA;
        }
        
        return tmp1;
    }
};
