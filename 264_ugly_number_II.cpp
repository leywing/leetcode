//
//  264_ugly_number_II.cpp
//  test
//
//  Created by ley on 2020/4/28.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
//from the discussion
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==0) return -1;
        vector<int> ug(n);
        ug[0]=1;
        if(n==1) return 1;
        int t2=0,t3=0,t5=0;
        for(int i=1;i<n;i++){
            ug[i]=min(ug[t2]*2,min(ug[t3]*3,ug[t5]*5));
            if(ug[i]==ug[t2]*2) t2++;
            if(ug[i]==ug[t3]*3) t3++;
            if(ug[i]==ug[t5]*5) t5++;
        }
        return ug[n-1];
    }
    
};
