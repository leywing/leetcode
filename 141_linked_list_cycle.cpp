//
//  141_linked_list_cycle.cpp
//  test
//
//  Created by ley on 2020/2/4.
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
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;
        ListNode* walker=head;
        ListNode* runner=head;
        while(runner->next!=nullptr&&runner->next->next!=nullptr){ //runner is fast so just check runner->next is enough ans necessary
            walker=walker->next;
            runner=runner->next->next;
            //if head->next point to himself this also found
            if(walker==runner) return true;
        }
        
        return false;
    }
};

//class Solution {
//public:
//    bool hasCycle(ListNode *head) {
//        //it ask use O(1) memory
//        //try to use the address     1 1 1 1 2    figure if there exit two complete same address
//        unordered_set<ListNode*> set;
//        if(head==nullptr) return false;
//        while(head->next!=nullptr){
//            head=head->next;
//            if(set.find(head)!=set.end()){
//                return true;
//            }else{
//                set.insert(head);
//            }
//        }
//        return false;
//    }
//};
