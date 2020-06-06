//
//  327_ Count of Range Sum.cpp
//  test
//
//  Created by ley on 2020/6/4.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
//看了discussion里别人的solution
//看了我好久。。。。才明白为啥O(nlogn),以及算法到底是怎么进行的

//重点 还是 sort   ,排序好的 能节省非常多。

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len=nums.size();
        vector<long> sum(len+1,0);
        for(int i=1;i<len+1;i++){
            sum[i]=sum[i-1]+nums[i-1];
        }
        int ans=cou2(sum,0,len+1,lower,upper);
        return ans;
    }
    
private:
    int cou2(vector<long>& sums,int start,int end,const int& lower,const int& upper){
        //will count and sort      start----end-1
        if(end-start<=1) return 0;  //就一个数
        int mid=start+(end-start)/2;
        int count=cou2(sums,start,mid,lower,upper)+cou2(sums, mid, end, lower, upper);
        
        int m=mid,n=mid,t=mid,cache_len=0;
        vector<long> cache(end-start,0);
        int s=0;
        for(int i=start;i<mid;i++){
            while(m<end && sums[m]-sums[i]<lower) m++;  //  m    >=lower
            while(n<end && sums[n]-sums[i]<=upper) n++;   // n     >upper
            count+=(n-m);                                                       // 这里的m,n真的巧妙呢.  因为。两个都是sort好的，所以，m,n递增，巧妙。
            
            while(t<end && sums[t]<sums[i]) cache[s++]=sums[t++];
            cache[s++]=sums[i];
            //cache_len=s;
        }
        
        for(int k=0;k<s;k++) sums[start+k]=cache[k];
    
        return count;
    }
};
