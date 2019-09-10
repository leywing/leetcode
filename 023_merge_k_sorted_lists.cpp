//
//  023_merge_k_sorted_lists.cpp
//  test
//
//  Created by ley on 2019/4/15.
//  Copyright © 2019年 ley. All rights reserved.
//

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size=lists.size();
        int i=0;
        int temp=0;
        int new_size=0;
        int flag=0;
        if(size==0) return nullptr;
        if(size==1) return lists[0];
        while(size>1){
            lists[temp]=mergeTwoLists(lists[i], lists[i+1]);
            temp++;
            i=i+2;
            size=size-2;
            if(size==0) {
                new_size=temp;
                flag=1;
            }else if(size==1){
                lists[temp]=lists[i];
                temp++;
                new_size=temp;
                flag=1;
            }
            
            if(flag==1){
                size=new_size;
                flag=0;
                i=0;
                temp=0;
            }
            
        }
        
        return lists[0];
    }
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
    return 0;
}


//别人家的代码，多简洁！！！！看看mergetwo的，要巧用递归，就可以少写很多代码了。
//ListNode *mergeKLists(vector<ListNode *> &lists) {
//    if(lists.empty()){
//        return nullptr;
//    }
//    while(lists.size() > 1){
//        lists.push_back(mergeTwoLists(lists[0], lists[1]));
//        lists.erase(lists.begin());
//        lists.erase(lists.begin());
//    }
//    return lists.front();
//}
//ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//    if(l1 == nullptr){
//        return l2;
//    }
//    if(l2 == nullptr){
//        return l1;
//    }
//    if(l1->val <= l2->val){
//        l1->next = mergeTwoLists(l1->next, l2);
//        return l1;
//    }
//    else{
//        l2->next = mergeTwoLists(l1, l2->next);
//        return l2;
//    }
//}


//优先队列的C++，实现！！！！
//首先重载下操作符，然后弹出头，留下头节点，再把头->next压回优先队列，如此往复。
//class Solution {
//    struct compare {
//        bool operator()(const ListNode* l, const ListNode* r) {
//            return l->val > r->val;
//        }
//    };
//
//public:
//    ListNode *mergeKLists(vector<ListNode *> &lists) {
//        priority_queue<ListNode *, vector<ListNode *>, compare> q;
//        for (auto l : lists) {
//            if (l) {
//                q.push(l);
//            }
//        }
//
//        if (q.empty()) {
//            return NULL;
//        }
//
//        ListNode* result = q.top();
//        q.pop();
//        if (result->next) {
//            q.push(result->next);
//        }
//
//        ListNode* tail = result;
//        while (!q.empty()) {
//            tail->next = q.top();
//            q.pop();
//            tail = tail->next;
//            if (tail->next) {
//                q.push(tail->next);
//            }
//        }
//
//        return result;
//    }
//};
