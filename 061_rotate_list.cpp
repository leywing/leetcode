//
//  061_rotate_list.cpp
//  test
//
//  Created by ley on 2019/12/11.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return head;
        ListNode* tmp=head;
        int n=1;
        while(tmp->next!=nullptr){
            n++;
            tmp=tmp->next;
        }
        //tmp  now = tail
        if(n==1) return head;
        
        int z=k%n;
        if(z==0) return head;
        int zzz=n-z;
        tmp->next=head;
        //tail
        
        ListNode* ley=head;
        for(int i=1;i<zzz;i++){
            //n-z-1
            ley=ley->next;
        }
        
        head=ley->next;
        ley->next=nullptr;
        
        return head;
    }
};
