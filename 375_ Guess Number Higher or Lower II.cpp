//
//  375_ Guess Number Higher or Lower II.cpp
//  test
//
//  Created by ley on 2020/9/1.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n,vector<int>(n,-1));
       //   x+dp[1,x-1]+dp[x+1,n]
        //n:  0-----n-1     1----n
        if(n==1){
            return 0;
        }else if(n==2){
            return 1;
        }
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            int tmp=max_one(helper(1,i-1,dp),helper(i+1,n,dp))+i;
            ans=ans<tmp?ans:tmp;
        }
        return ans;
    }
private:
    int helper(int start, int end, vector<vector<int>>& dp){
        if(start>=end){
            return 0;
        }else if(end-start==1){
            return start;
        }else{
            //end-start >=2
            if(dp[start-1][end-1]!=-1){
                return dp[start-1][end-1];
            }else{
                int ans=INT_MAX;
                for(int i=start;i<=end;i++){
                    int tmp=max_one(helper(start,i-1,dp),helper(i+1,end,dp))+i;
                    ans=ans<tmp?ans:tmp;
                }
                dp[start-1][end-1]=ans;
                //cout<<start<<" "<<end<<" : "<<ans<<endl;
                return ans;
            }
            
        }
    }
    
    int max_one(int a,int b){
        return a>b?a:b;
    }

};
