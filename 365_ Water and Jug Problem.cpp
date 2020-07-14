//
//  365_ Water and Jug Problem.cpp
//  test
//
//  Created by ley on 2020/7/15.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y < z) return false;
        if(x == 0 || y == 0) return (z==0 || x+y==z);
        return z%gcd(x,y)==0;
    }
    
    int gcd(int a,int b){
        //   辗转相除法
        //。 10。5。     15。12。  5.10
        while(b!=0){
            int tmp = b;
            b = a%b;
            a = tmp;
        }
        return a;
    }
};
