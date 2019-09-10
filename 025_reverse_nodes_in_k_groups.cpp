//
//  025_reverse_nodes_in_k_groups.cpp
//  test
//
//  Created by ley on 2019/9/8.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
   
        if(head==nullptr||head->next==nullptr) return head;
        if(k==1) return head;
        
        ListNode* tmp;
        
        tmp=head;
        for(int i=0;i<k;i++){
            if(tmp==nullptr){
    
                return head;
            }else{
                tmp=tmp->next;
            }
        }
        
        ListNode* tmp_head=head;
        
        ListNode* tmp2=head;
        ListNode* tmp3=head->next;
        ListNode* tmp4=tmp3->next;
        for(int i=1;i<k;i++){
            tmp4=tmp3->next;
            tmp3->next=tmp2;
            tmp2=tmp3;
            tmp3=tmp4;
        }
        tmp_head->next=tmp3;
        if(tmp3!=nullptr){
            tmp_head->next=reverseKGroup(tmp3, k);
        }
        
        return  tmp2;
    }
};
