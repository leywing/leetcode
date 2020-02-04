//
//  138_copy_list_with_random_pointer.cpp
//  test
//
//  Created by ley on 2020/2/1.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"


class Node {
public:
 int val;
 Node* next;
 Node* random;
 
 Node(int _val) {
     val = _val;
     next = NULL;
     random = NULL;
 }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        if(head==nullptr) return nullptr;
        Node* ley_head=new Node(head->val);
        Node* tmp=ley_head;
        Node* t_head=head;
        map[head]=ley_head;
        while(t_head->next!=nullptr){
            t_head=t_head->next;
            tmp->next=new Node(t_head->val);
            tmp=tmp->next;
            map[t_head]=tmp;
        }
        
        tmp=ley_head;
        t_head=head;
        tmp->random=map[t_head->random];
        while(t_head->next!=nullptr){
            t_head=t_head->next;
            tmp=tmp->next;
            tmp->random=map[t_head->random];
        }
        
        
        return ley_head;
    }
};
