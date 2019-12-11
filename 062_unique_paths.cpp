//
//  062_unique_paths.cpp
//  test
//
//  Created by ley on 2019/12/11.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long up=1;
        long long down=1;
        if(m==1||n==1) return 1;
        m=m-1;
        n=n-1;
        
        int min=m>n?n:m;
        
        int count=m+n;
        
        for(int i=1;i<=min;i++){
            up=up*count;
            count--;
        }
        for(int j=1;j<=min;j++){
            down=down*j;
        }
        
        int ans;
        ans=up/down;
        
        return ans;
    }
};
