//
//  279_perfect_squares.cpp
//  test
//
//  Created by ley on 2020/4/28.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"


//怎么说呢。。。这个solution确实挺那个的。。。。。这样的DP想法我也想过。但是总觉得算一个n,你去建立dp[n]也太浪费
//他考虑的视角是。。。。你这测试集肯定要测很多个值。这样就不浪费了。。。。
//注意static的用法。 等同于全局变量。
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp{0};  //static 表示当前这个东西，即使函数返回，也会保留
        while(dp.size()<=n){
            int m=dp.size();
            int square=INT_MAX;
            for(int i=1;i*i<=m;i++){
                square=min(square,dp[m-i*i]+1);
            }
            dp.push_back(square);
        }
        return dp[n];
    }
};

//太慢了。。。。。。。。。得用DP
////要用递归
//class Solution {
//public:
//    int numSquares(int n) {
//        int min=INT_MAX-900;
//        num2(n, 0, min);
//        return min;
//    }
//private:
//    int num2(int n,int tmp_count,int& min){
//        if(n<=0) return -1;    //error
//        if(tmp_count>=min) return -1;
//        int i=1;
//        while(INT_MAX/i>=i && n>=i*i){
//            i++;
//        }
//        i--;
//        if(i==1){
//            tmp_count+=n;
//            min=min<tmp_count?min:tmp_count;
//            return n;
//        }
//
//        if(n==i*i){
//            tmp_count+=1;
//            min=min<tmp_count?min:tmp_count;
//            return 1;
//        }
//
//        int mintmp=INT_MAX-900;
//        for(int j=i;j>=1;j--){
//            int tt=n-j*j;
//            if(mp.find(tt)!=mp.end()){
//                int t7=tmp_count+mp[tt]+1;
//                mintmp=mintmp<mp[tt]+1?mintmp:mp[tt]+1;
//                min=min<t7?min:t7;
//                continue;
//            }
//            //cout<<tt<<" "<<tmp_count+1<<" "<<min<<endl;
//            int tp=num2(tt, tmp_count+1, min);
//            if(tp>0){
//                if(mp.find(tt)==mp.end()){
//                    mp[tt]=tp;
//                }else{
//                    mp[tt]=mp[tt]<tp?mp[tt]:tp;
//                }
//                mintmp=mintmp<mp[tt]+1?mintmp:mp[tt]+1;
//            }
//        }
//        return mintmp;
//    }
//    unordered_map<int, int> mp;
//};
