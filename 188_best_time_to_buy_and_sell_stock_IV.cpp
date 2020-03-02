//
//  188_best_time_to_buy_and_sell_stock_IV.cpp
//  test
//
//  Created by ley on 2020/3/2.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    //other's DP   brilliant
    int maxProfit(int k, vector<int>& prices) {
        const int n=prices.size();
        if(k>n/2) return max2withnolimit(prices);
        if(k==0||n<2) return 0;
        
        vector<vector<int>> dp(k+1,vector<int>(n,0));
        
        
        for(int i=1;i<=k;i++){ //i times buy and sell
            int tmpmax=-prices[0]; //buy one
            for(int j=1;j<n;j++){  //till prices[j]
                dp[i][j]=max(dp[i][j-1],prices[j]+tmpmax);         //1.i times and do nothing  2.sell and use the i-1's knowledge
                tmpmax=max(tmpmax,dp[i-1][j-1]-prices[j]);
                //  t:0--j-1    max(prices[i]-prices[t]+dp[i-1][t-1])=prices[j]+  t:0--j-1 max(dp[i-1][j-1]-prices[t])
                //you will found that    i not change, the second will only change from j-1 to j ,so use the tmpmax to trace
            }
        }
        
        return dp[k][n-1];
        
    }
    
    int max2withnolimit(vector<int>& prices){
        int profit=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]) profit=profit+prices[i]-prices[i-1];
        }
        return profit;
    }
};
