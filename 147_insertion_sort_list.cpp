//
//  147_insertion_sort_list.cpp
//  test
//
//  Created by ley on 2020/2/9.
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
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        int n=1;
        ListNode* walker=head->next;
        head->next=nullptr;
        while(walker!=nullptr){
            ListNode* tmp=head;
            ListNode* lastone=head;
            ListNode* lnext=walker->next;
            bool flag=false;
            for(int i=0;i<n;i++){
                if(tmp->val<walker->val){
                    if(i!=0){
                        lastone=tmp;
                    }
                    tmp=tmp->next;
                }else{
                    if(i==0){
                        walker->next=head;
                        head=walker;
                        n++;
                        walker=lnext;
                        flag=true; //means found
                        break;
                    }else{
                        lastone->next=walker;
                        walker->next=tmp;
                        n++;
                        walker=lnext;
                        flag=true;  //means found
                        break;
                    }
                }
            }
            
            if(!flag){
                walker->next=nullptr;
                lastone->next=walker;
                walker=lnext;
                n++;
            }
        }
        
        return head;
    }
};
