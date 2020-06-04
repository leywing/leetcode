//
//  326_ Power of Three.cpp
//  test
//
//  Created by ley on 2020/6/4.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        if(n==1) return true;
        if(n%3==0){
            return isPowerOfThree(n/3);
        }else{
            return false;
        }
    }
};

//others' solution
//   return fmod(log10(n)/log10(3),1)==0;
