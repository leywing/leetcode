//
//  357_ Count Numbers with Unique Digits.cpp
//  test
//
//  Created by ley on 2020/6/30.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // n=0      0           1       A(0)=1
        // n=1      0-9         10      A(1)=9+ A(0)
        // n=2      0-99        10*9+1  A(2)=9*9+A(1)=91
        // n=3                          A(3)=9*9*8+A(2)
        if(A[10]==0){
            A[0]=1;
            A[1]=9+A[0];
            int y=9;
            int tmp_sum=9;
            for(int i=2;i<=10;i++){     //i2---y9   i10----y1
                tmp_sum=tmp_sum*y;
                A[i]=tmp_sum+A[i-1];
                y--;
            }
        }
        
        if(n>=10){
            return A[10];
        }else{
            return A[n];
        }
        
    }
private:
    int A[11]={0};
    
};
