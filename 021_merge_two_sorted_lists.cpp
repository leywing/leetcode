//
//  021_merge_two_sorted_lists.cpp
//  test
//
//  Created by ley on 2019/4/15.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <list>
#include <iostream>
using namespace  std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans;
        if(l1==nullptr) return l2;
        else if(l2==nullptr) return l1;
        else{
        if(l1->val<=l2->val){
            ans=l1;
            if(l1->next==nullptr) {ans->next=l2; return ans;}
            else l1=l1->next;
        }else{
            ans=l2;
            if(l2->next==nullptr) {ans->next=l1; return ans;}
            else l2=l2->next;
        }
          ListNode* temp=ans;
        while(l1!=nullptr&&l2!=nullptr){
            if(l1->val<=l2->val){
                temp->next=l1;
                temp=temp->next;
                if(l1->next==nullptr) {temp->next=l2; return ans;}
                else l1=l1->next;
            }else{
                temp->next=l2;
                temp=temp->next;
                if(l2->next==nullptr) {temp->next=l1; return ans;}
                else l2=l2->next;
            }
        }//似乎结束了？
        }
        return ans;
        
    }
};


int main(){
    cout<<endl<<endl;
    ListNode r(5);
    cout<<r.val<<endl;
    
    return 0;
}
