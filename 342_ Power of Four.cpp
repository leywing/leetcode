//
//  342_ Power of Four.cpp
//  test
//
//  Created by ley on 2020/6/11.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
//class Solution {
//public:
//    bool isPowerOfFour(int num) {
//        if(num==0) return false;
//        if(num==1) return true;
//        int tmp=num%4;
//        if(tmp!=0) return false;
//        return isPowerOfFour(num/4);
//    }
//};
class Solution {
public:
    bool isPowerOfFour(int num) {
        return fmod(log10(num)/log10(4),1)==0;
    }
};
