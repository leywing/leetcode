//
//  143_reorder_list.cpp
//  test
//
//  Created by ley on 2020/2/5.
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
    void reorderList(ListNode* head) {
        //find middle
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr) return;
        ListNode* walker=head;
        ListNode* runner=head;
        while(runner->next!=nullptr&&runner->next->next!=nullptr){
            walker=walker->next;
            runner=runner->next->next;
        }
        //若偶数的话，可能runner的下一个还有，比如。  1234。runner就只跑到3
        //但是无所谓也，此时walkere也还是中间，也就是2
        ListNode* head2=walker->next;
        walker->next=nullptr;
        // reverse the back
        runner=head2->next;
        head2->next=nullptr;
        while(runner!=nullptr){
            ListNode* tmp_p=runner->next;
            runner->next=head2;
            head2=runner;
            runner=tmp_p;
        }
        //merge
        walker=head->next;
        runner=head2->next;
        head->next=head2;
        head=head2;
        
        while(walker!=nullptr&&runner!=nullptr){
            head->next=walker;
            walker=walker->next;
            head=head->next;
            head->next=runner;
            runner=runner->next;
            head=head->next;
        }
        head->next=walker;
        
    }
    
};


//too much time and space
//class Solution {
//public:
//    void reorderList(ListNode* head) {
//        vector<ListNode*> v2;
//        if(head==nullptr) return;
//        v2.push_back(head);
//        while(head->next!=nullptr){
//            head=head->next;
//            v2.push_back(head);
//        }
//
//        int n=v2.size();
//        if(n==1||n==2) return ;
//        int i=0;
//        ListNode* front=v2[i];
//        ListNode* back=v2[n-i-1];
//        head=front;
//        head->next=back;
//        head=back;
//        i++;
//        while(i<n-i-1){
//            front=v2[i];
//            back=v2[n-i-1];
//            head->next=front;
//            head=front;
//            head->next=back;
//            head=back;
//            i++;
//        }
//        head->next=v2[i];
//        head->next->next=nullptr;
//    }
//};
