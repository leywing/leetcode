//
//  122_best_time_to_buy_and_sell_stock_II.cpp
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
        int total_profit=0;
        for(int i=0;i<n;i++){
            if(i==0) continue;
            else if(prices[i]>prices[i-1]){
                total_profit+=prices[i]-prices[i-1];
            }else{
                continue;
            }
        }
        return total_profit;
    }
};
