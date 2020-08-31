//
//  372_ Super Pow.cpp
//  test
//
//  Created by ley on 2020/7/15.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"


//others' solution
//One knowledge: ab % k = (a%k)(b%k)%k
//Since the power here is an array, we'd better handle it digit by digit.
//One observation:
//a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (a^123456 % k)^10 % k * (a^7 % k) % k
//Looks complicated? Let me put it other way:
//Suppose f(a, b) calculates a^b % k; Then translate above formula to using f :
//f(a,1234567) = f(a, 1234560) * f(a, 7) % k = f(f(a, 123456),10) * f(a,7)%k;

//amazing
class Solution {
public:
    
    int superPow(int a, vector<int>& b) {
        //calculate a^b mod 1337
        if(b.empty()) return 1;
        int last_bit=b.back();
        b.pop_back();
        return sup2(superPow(a, b), 10)*sup2(a, last_bit) % base;
    }
private:
    const int base=1337;
    int sup2(int a,int k){
        // 0<=k<=10
        //return a^k % 1337
        // a*a----*a  % 1337
        a= a%base;
        int result=1;
        for(int i=0;i<k;i++){
            result=(result*a)%base;
            //result and a will always < base
            // so num1*num2 % base = (num1%base*num2%base)%base
        }
        return result;
    }
};
