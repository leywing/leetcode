//
//  343_ Integer Break.cpp
//  test
//
//  Created by ley on 2020/6/11.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int integerBreak(int n) {
        // n   dp[n-1]
        //dp[0]=1;
        //dp[1]=1;
        return help_get_dp(n);
    }
private:
    int dp[58]={0};
    //so dp[0] never use.   dp[1] 2 =1;
    int help_get_dp(int n){
        if(n==0){
            cout<<"error"<<endl;
            return -1;
        }
        if(n==1 || n==2) return 1;
        if(dp[n-1]!=0) return dp[n-1];
        int maxans=1;
        for(int i=1;i<=n/2;i++){
            // i  with n-i
            int t1=max(i,help_get_dp(i));
            int t2=max(n-i,help_get_dp(n-i));
            maxans=max(maxans,t1*t2);
        }
        dp[n-1]=maxans;
        return maxans;
    }
};
