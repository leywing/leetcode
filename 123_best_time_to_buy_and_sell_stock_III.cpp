//
//  123_best_time_to_buy_and_sell_stock_III.cpp
//  test
//
//  Created by ley on 2019/12/29.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        vector<int> forward(n,0);
        //vector<int> backward(n,0);
        
        //forward
        int min=INT_MAX;
        int profit=0;
        for(int i=0;i<n;i++){
            if(prices[i]>min){
                profit=prices[i]-min>profit?(prices[i]-min):profit;
            }else{
                //prices[i]<=min
                min=prices[i];
            }
            forward[i]=profit;
            //means  0-i day can make the profit (include the i day)
            // the next work to calculate i+1----n-1day
        }
        
        int total_profit=profit;
        
        //backward
        int max=INT_MIN;
        int backfit=0; //hhahahaha
        for(int i=n-1;i>=0;i--){
            if(prices[i]<max){
                backfit=max-prices[i]>backfit?(max-prices[i]):backfit;
            }else{
                //prices[i]>=max
                max=prices[i];
            }
            //  i----n-1 day
            if(i!=0){
            total_profit=backfit+forward[i-1]>total_profit?(backfit+forward[i-1]):total_profit;
            }
        }
        
        return total_profit;
    
        
    }
};
