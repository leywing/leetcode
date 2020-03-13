//
//  202_happy_number.cpp
//  test
//
//  Created by ley on 2020/3/13.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> leyset;
        while(n!=0&&n!=1){
            int next=0;
            if(leyset.find(n)!=leyset.end()) return false;
            leyset.insert(n);
            while(n>0){
                int tmp=n%10;
                n=n/10;    //while n>>=1 not ok??????
                //fool!!!!!a ho!!!!!!    2进制的世界，右移是除以2
                next=next+tmp*tmp;
            }
            n=next;
        }
        if(n==1) return true;
        return false;
    }
};
