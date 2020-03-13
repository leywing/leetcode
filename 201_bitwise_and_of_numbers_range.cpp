//
//  201_bitwise_and_of_numbers_range.cpp
//  test
//
//  Created by ley on 2020/3/13.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==0) return 0;
        int moven=1;
        while(m!=n){
            m>>=1;
            n>>=1;
            moven<<=1;
        }
        m=m*moven;
        return m;
    }
};
