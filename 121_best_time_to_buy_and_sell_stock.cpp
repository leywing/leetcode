//
//  121_best_time_to_buy_and_sell_stock.cpp
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
        int n1=prices.size();
        if(n1==0) return 0;
        int min=INT_MAX;
        int profit=0;
        for(int i=0;i<n1;i++){
            if(prices[i]>min){
                profit=prices[i]-min>profit?(prices[i]-min):profit;
            }else{
                //prices[i]<=min
                min=prices[i];
            }
        }
        return profit;
    }
};
