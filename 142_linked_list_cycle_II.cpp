//
//  142_linked_list_cycle_II.cpp
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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr) return nullptr;
        ListNode* walker=head;
        ListNode* runner=head;
        bool flag=false;
        while(runner->next!=nullptr&&runner->next->next!=nullptr){
            walker=walker->next;
            runner=runner->next->next;
            if(walker==runner){
                flag=true;
                break;
            }
        }
        if(!flag){
            return nullptr;
        }
        
        if(head==walker){
            return head;
        }
        while(head!=walker){
            head=head->next;
            walker=walker->next;
        }
        return walker;
    }
};
//class Solution {
//public:
//    ListNode *detectCycle(ListNode *head) {
//        unordered_set<ListNode*> set;
//        if(head==nullptr) return nullptr;
//        set.insert(head);
//        while(head->next!=nullptr){
//            head=head->next;
//            if(set.find(head)!=set.end()){
//                return head;
//            }else{
//                set.insert(head);
//            }
//        }
//
//        return nullptr;
//    }
//};
