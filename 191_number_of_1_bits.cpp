//
//  191_number_of_1_bits.cpp
//  test
//
//  Created by ley on 2020/3/3.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n!=0){
            if(n&1) ans++;
            n=n>>1;
        }
        return ans;
    }
};
