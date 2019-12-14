//
//  070_climbing_stairs.cpp
//  test
//
//  Created by ley on 2019/12/13.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int climbStairs(int n) {
        int i1=1;
        int i2=2;
        int tempi=0;
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 3;
        for(int i=3;i<=n;i++){
            tempi=i1+i2;
            i1=i2;
            i2=tempi;
        }
        
        return tempi;
    }
};
//看别人是用的压栈的方法
//如下，0ms
//class Solution {
//public:
//    int climbStairs(int n) {
//        vector<int> aa;
//        aa.push_back(1);
//        aa.push_back(2);
//        if(n==1) return 1;
//        if(n==2) return 2;
//        for(int i=3;i<=n;i++){
//            int tmp=aa[i-2]+aa[i-3];
//            aa.push_back(tmp);
//        }
//
//        return aa[n-1];
//    }
//};


