//
//  066_plus_one.cpp
//  test
//
//  Created by ley on 2019/12/12.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size=digits.size();
        
        int jinwei=0;
        for(int i=size-1;i>=0;i--){
            int tmp;
            if(i==size-1) tmp=digits[i]+1+jinwei;
            else tmp=digits[i]+jinwei;
            
            if(tmp<=9){
                digits[i]=tmp;
                return digits;
            }else{
                jinwei=1;
                tmp=tmp%10;
                digits[i]=tmp;
                if(i-1<0){
                    digits.insert(digits.begin(), 1);
                    return digits;
                }
            }
            
        }
        
        return digits;
        
    }
};
