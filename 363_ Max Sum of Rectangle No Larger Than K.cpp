//
//  363_ Max Sum of Rectangle No Larger Than K.cpp
//  test
//
//  Created by ley on 2020/6/30.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//O (col*col*row)
//other's solution
//amazing...........   因为这道题。。没耐心看解释。。几星期没写代码。。。。无语了，太懒了自己

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()) return 0;
        int row=matrix.size();
        int col=matrix[0].size();
        
        int ans=INT_MIN;
        for(int l=0;l<col;l++){
            vector<int> sums(row,0);    //     sum of row
            for(int r=l;r<col;r++){
                for(int i=0;i<row;i++){
                    sums[i] += matrix[i][r];
                }
                
                set<int> accuSet;
                accuSet.insert(0);
                int curSum=0,curMax=INT_MIN;
                for(int sum:sums){
                    curSum+=sum;
                    auto it=accuSet.lower_bound(curSum-k);      //lower_bound ???
                    //  cum[j]-cum[i]<=k  -->    cum[j]-k <= cum[i]
                    
                    // 这里应该使用lower_bound，因为lower_bound是返回大于等于，而upper_bound只能返回第一个大于的
                    if(it!=accuSet.end())
                        curMax=max(curSum-*it,curMax);
                    accuSet.insert(curSum);
                }
                
                ans=max(ans,curMax);
            }
        }
        return ans;
        
        
    }
};





//找出一个 subarray sum最大，但是小于 K
//int max_subarray_not_large_than_k(vector<int> row,int k){
//    //  cum[j]-cum[i]<k  -->    cum[j]-k < cum[i]
//    set<int> cumset;
//    cumset.insert(0);
//    int best=0,cum=0;
//
//    int len=row.size();
//    for(int i=0;i<len;i++){
//        cum+=row[i];
//        auto iter=cumset.upper_bound(cum-k);    //find the cum[i] > cum[j]-k
//        if(iter!=cumset.end())
//            best=max(best, cum-*iter);
//
//        cumset.insert(cum);
//    }
//
//    return best;
//}

//找出一个 subarray sum最大
//这是kadane算法。    我当时写这道easy题，是找出  记录前面minSum,然后 Sum减去 此前的minSum,   跟 ans比
//int kadane(vector<int> row){
//    int len=row.size();
//    if(len==0) return 0;
//
//    int sum=0;
//    int maxSum=INT_MIN;
//
//    for(int i=0;i<len;i++){
//        sum=sum+row[i];
//        sum=sum>0?sum:0;
//        maxSum=max(sum,maxSum);
//    }
//    return maxSum;
//}


//pass 26/27   the last one  not pass because TLM
//...this solution is O(n^4) too slow
//by myself
//class Solution {
//public:
//    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
//        int row=matrix.size();
//        if(row==0) return 0;
//        int col=matrix[0].size();
//        if(col==0) return 0;
//
//        vector<vector<int>> sum(row,vector<int>(col,0));
//        int ans=INT_MIN;
//        for(int i=0;i<row;i++){
//            int tmp=0;
//            for(int j=0;j<col;j++){
//                tmp+=matrix[i][j];
//                if(i==0 && j==0){
//                    sum[i][j]=matrix[0][0];
//                }else if(i==0){
//                    sum[0][j]=sum[0][j-1]+matrix[0][j];
//                }else if(j==0){
//                    sum[i][0]=sum[i-1][0]+matrix[i][0];
//                }else{
//                    sum[i][j]=sum[i-1][j]+tmp;
//                }
//            }
//        }
//
//        //n ^4 ????? impossible
//        for(int a=0;a<row;a++){
//            for(int b=0;b<col;b++){
//                for(int i=0;i<=a;i++){
//                    for(int j=0;j<=b;j++){
//                        int tmp=helper(i, j, a, b, sum);
//                        if(tmp>ans && tmp<=k){
//                            ans=tmp;
//                            if(tmp==k) return k;
//                        }
//                    }
//                }
//            }
//        }
//        return ans;
//
//
//
//    }
//private:
//    int helper(int i,int j,int a,int b,vector<vector<int>>& sum){
//        //if(a==i || j==b) return INT_MIN;
//
//        //   sum[a][b]-sum[a][j-1]-sum[i-1][b]+sum[i-1][j-1]
//        if(i==0 && j==0){
//            return sum[a][b];
//        }else if(i==0){
//            return sum[a][b]-sum[a][j-1];
//        }else if(j==0){
//            return sum[a][b]-sum[i-1][b];
//        }else{
//            return sum[a][b]-sum[a][j-1]-sum[i-1][b]+sum[i-1][j-1];
//        }
//
//    }
//};
