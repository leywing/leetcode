//
//  234_palindrome_linked_list.cpp
//  test
//
//  Created by ley on 2020/4/24.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//see the discussion   it use reverse to achieve O(1) space.
//it you need to the same link-list,just reverse it again
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //O(n)时间简单，你直接用数组存，用数组验证就好了。但是它要求。O（1） space??????
        //或者用堆，找到  通过 runner walker找到中间点，然后 head push    后面的。pop。  但是还是没法O(1)
        if(head==nullptr||head->next==nullptr) return true;
        if(head->next->next==nullptr){
            if(head->next->val==head->val){
                return true;
            }else{
                return false;
            }
        }
        ListNode* walker=head;
        ListNode* runner=head;
        ListNode* rev=nullptr;
        while(runner->next!=nullptr&&runner->next->next!=nullptr){
            //walker=walker->next;                //1 2 3 4 5
            runner=runner->next->next;          //1 3 5 7 9      if(runner->next==nullptr) 奇数，walker是中。   否则，偶数
            ListNode* tmp=rev;
            rev=walker;
            walker=walker->next;
            rev->next=tmp;
        }
        if(runner->next==nullptr){
            walker=walker->next;
        }else{
            //runner->next==nullptr
            //rev 1  walker 2  runner 3     4
            ListNode* tmp=rev;
            rev=walker;
            walker=walker->next;
            rev->next=tmp;
        }
        
        while(walker!=nullptr){
            if(rev->val==walker->val){
                rev=rev->next;
                walker=walker->next;
            }else{
                return false;
            }
        }
        return true;
        
        
    }
};
