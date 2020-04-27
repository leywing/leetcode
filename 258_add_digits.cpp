//
//  258_add_digits.cpp
//  test
//
//  Created by ley on 2020/4/28.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int addDigits(int num) {
        while(num>=10){
            int next=0;
            while(num>=10){
                next+=num%10;
                num=num/10;
            }
            next+=num;
            num=next;
        }
        return num;
    }
};
