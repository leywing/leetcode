//
//  092_reverse_linked_list_II.cpp
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i=1;
        if(m==n) return head;
        ListNode* before_start;
        ListNode* tmp=head;
        
        if(m==1){
            ListNode* new_tmp=tmp;
            while(i<n){
                if(i==m){
                    new_tmp=tmp;
                    tmp=tmp->next;
                    i++;
                    continue;
                }
                ListNode* tmptmp=tmp->next;
                tmp->next=new_tmp;
                new_tmp=tmp;
                tmp=tmptmp;
                i++;
            }
            head->next=tmp->next;
            tmp->next=new_tmp;
            return tmp;
            ///????
        }else{
            while(i<m){
                if(i==m-1) before_start=tmp;
                tmp=tmp->next;
                i++;
            }
            
            ListNode* start=tmp;
            ListNode* new_tmp=tmp;
            while(i<n){
                if(i==m){
                    tmp=tmp->next;
                    i++;
                    continue;
                }
                ListNode* tmptmp=tmp->next;
                tmp->next=new_tmp;
                new_tmp=tmp;
                tmp=tmptmp;
                i++;
            }
            
            start->next=tmp->next;
            tmp->next=new_tmp;
            before_start->next=tmp;
            
            return head;
        }
    }
};
