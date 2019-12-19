//
//  082_remove_duplicates_from_sorted_list_II.cpp
//  test
//
//  Created by ley on 2019/12/17.
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
        ListNode* new_head=nullptr;
        if(head==nullptr) return head;
        ListNode* new_tmp=nullptr;
        
        ListNode* tmp=head;
        int delete_flag=0;
        int delete_value;
        
        int find_head=0;
        while(1){
            
            //find head
            if(find_head==0){
                if(delete_flag==0){
                    if(tmp->next==nullptr){
                        new_head=tmp;
                        new_tmp=tmp;
                        break;
                    }else if(tmp->next->val==tmp->val){
                        delete_flag=1;
                        delete_value=tmp->val;
                    }else{
                        new_head=tmp;
                        new_tmp=tmp;
                        find_head=1;
                    }
                }else{
                    //delete_flag==1
                    if(tmp->next==nullptr) break;
                    else if(tmp->next->val!=delete_value){
                        delete_flag=0;
                    }
                }
            }else{
                //remove duplicate
                if(delete_flag==0){
                    if(tmp->next==nullptr){
                        new_tmp->next=tmp;
                        new_tmp=tmp;
                        break;
                    }else if(tmp->next->val==tmp->val){
                        delete_flag=1;
                        delete_value=tmp->val;
                    }else{
                        new_tmp->next=tmp;
                        new_tmp=tmp;
                    }
                }else{
                    //delete_flag==1
                    if(tmp->next==nullptr){
                        new_tmp->next=nullptr;
                        break;
                    }else if(tmp->next->val!=delete_value){
                        delete_flag=0;
                    }
                }
                
            }
            
            tmp=tmp->next;
            
        }
        if(new_tmp!=nullptr) new_tmp->next=nullptr;

        return new_head;
        
    }
};
