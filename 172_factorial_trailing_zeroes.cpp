//
//  172_factorial_trailing_zeroes.cpp
//  test
//
//  Created by ley on 2020/2/29.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int trailingZeroes(int n) {
        int tmp=n%10;
        int tmp2=n/10;
        int ans=tmp2*2;
        if(tmp>=5){
            ans++;
        }
        
        int tmp_i=25;
        while(n>=tmp_i){
            int tmp3=n/tmp_i;
            ans+=tmp3;
            
            if(INT_MAX/5>tmp_i){
                tmp_i*=5;
            }else{
                break;
            }
        }
        
        return ans;
    }
};
