//
//  232_number_of_digit_one.cpp
//  test
//
//  Created by ley on 2020/4/24.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//from this discussion
//so amazing      i am such a idot
class Solution {
public:
    int countDigitOne(int n) {
//        int countDigitOne(int n) {
//            int ones = 0;
//            for (long long m = 1; m <= n; m *= 10) {
//                int a = n/m, b = n%m;
//                ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
//            }
//            return ones;
//        }
        //  11    m1 a11 b1    19/10*1+1*(1+1)=3
        //  17    m1 a17 b17  +(17+8)/10*1+0= 2         m10 a1 b7   9/10*10+1*8=8    10
        // 125    m1 a125 b125    (125+8)/10*1=133       m10  a12  b5  (12+8)/10*10=20   m100 a1 b25 (1+8)/10*100=0     153
        
        //traverse each digit of n, if n=3401512
        //for m=100, split n into a=34015 and b=12
        //if a%10==1, #1=a/10*m+(b+1);
        //if a%10==0, #2=a/10*m;
        //if a%10>1; #3=a/10*m+m;
        //In general, #4=(a+8)/10*m+(a % 10 == 1)*(b + 1).
        //For general expression above:
        //if a%10>1, then (a+8)/10=a/10+1, #4=#3
        //if a%10==0, (a+8)/10=a/10, (a % 10 == 1)=false, #4=#2
        //if a%10==1, (a+8)/10=a/10, (a % 10 == 1)=true, #4=#1
        //This is how "(a+8)/10*m+(a % 10 == 1)*(b + 1)" covers all three conditions.
        int ones=0;
        for(long long m=1;m<=n;m*=10){
            int a=n/m,b=n%m;
            ones+=(a+8)/10*m+(a%10==1)*(b+1);
            //前面的表示。 比如。 3401512。m=100     a=34015  那么也就有。 3401个100（都以1xx),若5=1，则多 b+1个（因为100），若5==0，则不多。
        }
        return ones;
        
    }
};
