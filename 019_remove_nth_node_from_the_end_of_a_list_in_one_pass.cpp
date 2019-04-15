//
//  019_remove_nth_node_from_the_end_of_a_list_in_one_pass.cpp
//  test
//
//  Created by ley on 2019/4/15.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace  std;

struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* n1;ListNode* n2;
        ListNode* temp=head;
        n2=temp;
        for(int i=0;i<n+1;i++){
            n2=temp;
            if(temp==nullptr) {
                head=head->next;
                return head;
            }
            temp=temp->next;
        }
        cout<<n2->val<<" ";
        n1=head;
        while(n2->next!=nullptr){
            n1=n1->next;
            n2=n2->next;
        }
        cout<<n1->val<<" ";
        temp=n1->next;
        n1->next=n1->next->next;
        delete temp;     //new的空间，c++要自己删的，除非是共享指针的（那些，王博说的，还没纳入官方）
        return head;
    }
};


int main(){
    ListNode* a=new ListNode(1);
    ListNode* head=a;
    a->next=new ListNode(2);
    a=a->next;
    a->next=new ListNode(3);
    a=a->next;
    a->next=new ListNode(4);
    a=a->next;
    a->next=new ListNode(5);
    a=head;
    while(a!=nullptr){
        cout<<a->val<<"->";
        a=a->next;
    }
    Solution aba;
    aba.removeNthFromEnd(head, 2);
    a=head;
    while(a!=nullptr){
        cout<<a->val<<"->";
         a=a->next;
    }

    return 0;
        
}
