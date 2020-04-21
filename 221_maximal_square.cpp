//
//  221_maximal_square.cpp
//  test
//
//  Created by ley on 2020/4/20.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        int row=matrix.size();
        if(row==0) return 0;
        int col=matrix[0].size();
        if(col==0) return 0;
        
        vector<vector<int>> dp(2,vector<int>(col,0));
        
        //当然还可以只用一行
        //  首先根据 maxtrix[0]   对dp初始化
        //  int tmp=dp[j];
        //  dp[j]=min_of_two(dp[j],dp[j-1])+1;
        //  dp[j]=min_of_two(dp[j],tmp])+1;
        
        //当然，也可以
        //int tmp2=dp[j]
        //dp[j]=min_of_three(dp[j],dp[j-1],tmp)+1;
        //tmp=tmp2;
        
        //等同于。 dp[i][j]=min_of_three(dp[i-1][j],dp[i-1][j-1],dp[i][j-1)+1
        
        int before=0;
        for(int i=0;i<row;i++){
            if(i==0){
                for(int j=0;j<col;j++){
                    if(matrix[i][j]=='0'){
                        dp[0][j]=0;
                    }else{
                        dp[0][j]=1;
                        ans=ans>1?ans:1;
                    }
                }
                
            }else{
                int tmp;
                if(before==0) tmp=1;
                else tmp=0;
                
                for(int j=0;j<col;j++){
                    if(j==0){
                        if(matrix[i][j]=='0'){
                            dp[tmp][j]=0;
                        }else{
                            dp[tmp][j]=1;
                            ans=ans>1?ans:1;
                        }
                    }else{
                        if(matrix[i][j]=='0'){
                            dp[tmp][j]=0;
                        }else{
                            dp[tmp][j]=min_of_three(dp[before][j], dp[before][j-1], dp[tmp][j-1])+1;
                            ans=ans>dp[tmp][j]?ans:dp[tmp][j];
                        }
                    }
                }
                before=tmp;
            }
        }
        
        return ans*ans;
    }
private:
    int min_of_three(int a,int b,int c){
        int ans=a<b?a:b;
        ans=ans<c?ans:c;
        return ans;
    }
};





//class Solution {
//public:
//    int maximalSquare(vector<vector<char>>& matrix) {
//        //肯定是个 DP 问题，那就来想想 怎么DP，先别着急看discussion
//        //遍历的方法想到了，但是太慢了：
//        //              1.i，j点出发，x向右，y向下，是否都为1，是的话(存下当前x,y)（x向下，y向右，一路检验，直到遇见，遇见时，update max）
//        //              2.然后回到存的x，y,(再重复上述操作）
//        //              3.不符合时，j+1（满了时，i+1)
//        //缺点，这样太慢了，一个点很可能被检验多次
//
//        //要想办法，让每次走一步，这个点就记录下该记录的信息
//        // 记录 rectangle?   [1,1]         [1,2]         [1,3]
//        //            [1,1] [2,1]/[1,2]   [2,2]/[3,1]   [2,3]/[4,1]         竖/横。当前ractangle
//        //            [0,0] [3,1]/[1,1]
//
//        //  I see the discussion
//        // I am so stupid ..........square is so special         just need   dp[i][j]=min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]+1)
//        int ans=0;
//        int row=matrix.size();
//        if(row==0) return 0;
//        int col=matrix[0].size();
//        if(col==0) return 0;
//
//        vector<vector<int>> dp(row,vector<int>(col,0));
//        for(int i=0;i<row;i++){
//            for(int j=0;j<col;j++){
//                if(i==0||j==0){
//                    if(matrix[i][j]=='0'){
//                        dp[i][j]=0;
//                    }else{
//                        dp[i][j]=1;
//                        ans=ans>1?ans:1;
//                    }
//                }else{
//                    if(matrix[i][j]=='0'){
//                        dp[i][j]=0;
//                    }else{
//                        dp[i][j]=min_of_three(dp[i-1][j], dp[i-1][j-1], dp[i][j-1])+1;
//                        ans=ans>dp[i][j]?ans:dp[i][j];
//                    }
//                }
//            }
//        }
//
//        return ans*ans;
//    }
//private:
//    int min_of_three(int a,int b,int c){
//        int ans=a<b?a:b;
//        ans=ans<c?ans:c;
//        return ans;
//    }
//};
