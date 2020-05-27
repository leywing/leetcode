//
//  309_ Best Time to Buy and Sell Stock with Cooldown.cpp
//  test
//
//  Created by ley on 2020/5/28.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"


//others' solution
//from the discussion
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // buy[i]=max(rest[i-1]-price, buy[i-1])        now state is buy
        // sell[i]=max(buy[i-1]+price, sell[i-1])       now state is sell
        // rest[i]=max(sell[i-1], rest[i-1])            now state is rest
        
        //because rest[i]<=sell[i]  so  rest[i]=sell[i-1]
        // buy[i]=max(sell[i-2]-price, buy[i-1])
        // sell[i]=max(buy[i-1]+price, sell[i-1])
        
        int buy(INT_MIN),sell(0),prev_buy(0),prev_sell(0);
        for(auto a:prices){
            prev_buy=buy;                   //buy 是上一轮的 ，所以对于这一轮，是 prev_buy
            //buy=max(p2_sell-a,prev_buy);
            buy=max(prev_sell-a,buy);      //此时的 prev_sell 是上一轮的 prev_sell ,所以是 sell[i-2]
            //buy=prev_sell-a>=buy?prev_sell-a:buy;
            prev_sell=sell;                //sell 是上一轮的sell,所以是 prev_sell
            sell=max(prev_buy+a,sell);
            //sell=prev_buy+a>=sell?prev_buy+a:sell;
        }
        return sell;
    }
};
