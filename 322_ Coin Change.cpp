//
//  322_ Coin Change.cpp
//  test
//
//  Created by ley on 2020/6/3.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//others' solution from the discusssion
//dp   always better!!!!!
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int mx=amount+1;
        vector<int> dp(mx,mx);
        dp[0]=0;
        int size=coins.size();
        for(int i=1;i<mx;i++){
            for(int j=0;j<size;j++){
                if(coins[j]<=i){
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        
        return dp[amount]==mx?-1:dp[amount];
    }
};

//超时了。。。。。说明这样没取巧的方法是绝对不行的。。。
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        sort(coins.begin(), coins.end());
//        return help(coins, amount, INT_MAX);
//    }
//private:
//    int help(vector<int>& coins,int amount,int maxk){
//        //coin num should be less than maxk
//        int size=coins.size();
//        if(amount==0) return 0;
//        if(maxk==0) return -1;
//
//        vector<int> needtopush;
//        for(int i=size-1;i>=0;i--){
//            if(coins[i]>amount){
//                needtopush.push_back(coins.back());
//                coins.pop_back();
//            }else if(coins[i]==amount){
//                while(!needtopush.empty()){
//                    coins.push_back(needtopush.back());
//                    needtopush.pop_back();
//                }
//                return 1;
//            }else{
//                break;
//            }
//        }
//
//        size=coins.size();
//        if(size==0){
//            while(!needtopush.empty()){
//                coins.push_back(needtopush.back());
//                needtopush.pop_back();
//            }
//            return -1;
//        }
//
//        int backone=coins.back();
//        int shang=amount/backone;
//
//        int coins_num=shang+1;
//        int min_ans=maxk;
//
//        coins.pop_back();
//        for(;shang>=0;shang--){
//            coins_num--;
//            if(coins_num>=maxk-1){
//                coins.push_back(backone);
//                while(!needtopush.empty()){
//                    coins.push_back(needtopush.back());
//                    needtopush.pop_back();
//                }
//                return -1;
//            }
//            int tmp=help(coins, amount-shang*backone, maxk-coins_num);
//            if(tmp!=-1){
//                min_ans=min(min_ans,tmp+coins_num);
//            }
//        }
//        coins.push_back(backone);
//        while(!needtopush.empty()){
//            coins.push_back(needtopush.back());
//            needtopush.pop_back();
//        }
//
//        if(min_ans==maxk){
//            return -1;
//        }else{
//            return min_ans;
//        }
//
//    }
//};
