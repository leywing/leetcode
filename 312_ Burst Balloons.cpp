//
//  312_ Burst Balloons.cpp
//  test
//
//  Created by ley on 2020/5/29.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//others' solution
//from the discussion
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //  数字    可能性
        //   1        1      num[0]
        //   2        2      num[0]*num[1]+num[1]      num[0]*num[1]+num[0]
        //   3        3      ......
        //O(n!).........impossible...but have a try  becase n<=500
    
        //see it from the discussion
        int len=nums.size();
        vector<int> nn;
        nn.push_back(1);
        for(auto a:nums){
            nn.push_back(a);
        }
        nn.push_back(1);
        //  length   is   len+2
        int n=len+2;        // nn[0]----nn[n-1]
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int k=2;k<n;k++){        //k step     right-left=k    at least 2      1  3 mid is 2   bigest is  0----n-1 right-left=n-1
            for(int left=0;left<n-k;left++){
                int right=left+k;   //right=left+k<n-k+k  left<n
                for(int i=left+1;i<right;i++){
                    //   i  between left and right     ,that is why smallest k is 2
                    dp[left][right]=max(dp[left][right],nn[left]*nn[i]*nn[right]+dp[left][i]+dp[i][right]);
                }
            }
        }
        
        return dp[0][n-1];
    }
    
};
