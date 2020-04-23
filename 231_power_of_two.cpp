//
//  231_power_of_two.cpp
//  test
//
//  Created by ley on 2020/4/24.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        while(n%2==0){
            n=n/2;
        }
        if(n==1) return true;
        return false;
    }
};
