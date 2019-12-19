//
//  083_remove_dulicates_from_sorted_list.cpp
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* new_tmp=head;
        
        if(head==nullptr||head->next==nullptr) return head;
        
        int delete_flag=0;
        int delete_value;
        
        ListNode* tmp=head;
        
        while(1){
            if(delete_flag==0){
                if(tmp->next==nullptr){
                    break;
                }else if(tmp->next->val==tmp->val){
                    new_tmp=tmp;
                    delete_flag=1;
                    delete_value=tmp->val;
                }else{
                    //    !=
                    ;
                }
            }else{
                //delete_flag==1
                if(tmp->next==nullptr){
                    new_tmp->next=nullptr;
                    break;
                }else if(tmp->next->val!=delete_value){
                    delete_flag=0;
                    new_tmp->next=tmp->next;
                }else{
                    //   ==
                    ;
                }
            }
            
            tmp=tmp->next;
        }
        
        return head;
    }
};
