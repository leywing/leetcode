//
//  371_ Sum of Two Integers.cpp
//  test
//
//  Created by ley on 2020/7/15.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int getSum(int a, int b) {
        return b==0?a: getSum(a^b,(unsigned int)(a&b)<<1);
        //a^b  means one have 1 one have 0
        // a&b  means 需要进位，所以左移1
    }
};
