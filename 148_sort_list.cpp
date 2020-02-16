//
//  148_sort_list.cpp
//  test
//
//  Created by ley on 2020/2/12.
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
    ListNode* sortList(ListNode* head) {
        //用分治
        return spilt2(head);
    }
    
    ListNode* spilt2(ListNode* head){
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* walker=head;
        ListNode* runner=head;
        while(runner->next!=nullptr&&runner->next->next!=nullptr){
            walker=walker->next;
            runner=runner->next->next;
        }
       
        runner=walker->next;
        //cout<<walker->val<<"  walker"<<endl;
        //cout<<runner->val<<"  runner"<<endl;
        walker->next=nullptr;
        walker=spilt2(head);
        runner=spilt2(runner);
        return merge2(walker,runner);
        
        
        
        
    }
    ListNode* merge2(ListNode* l1,ListNode* l2){
        if(l1==nullptr) return l2;
        else if(l2==nullptr) return l1;
        else{
            ListNode* head;
            ListNode* ans;
            if(l1->val<l2->val){
                ans=l1;
                l1=l1->next;
            }else{
                ans=l2;
                l2=l2->next;
            }
            
            head=ans;
            
            while(l1!=nullptr&&l2!=nullptr){
                if(l1->val<l2->val){
                    ans->next=l1;
                    ans=l1;
                    l1=l1->next;
                }else{
                    ans->next=l2;
                    ans=l2;
                    l2=l2->next;
                }
            }
            
            if(l1!=nullptr){
                ans->next=l1;
            }else if(l2!=nullptr){
                ans->next=l2;
            }
            
            return head;
        }
    }
};
