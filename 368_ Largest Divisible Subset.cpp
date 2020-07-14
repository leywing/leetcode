//
//  368_ Largest Divisible Subset.cpp
//  test
//
//  Created by ley on 2020/7/15.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//others' DP solution
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less<int>());
        int len=nums.size();
        if(len==0){
            return vector<int>();
        }
        int max_size=0,index=-1;
        vector<int> count(len,1);
        vector<int> pre(len,-1);
        for(int i=0;i<len;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(1+count[j]>count[i]){
                        count[i]=1+count[j];
                        pre[i]=j;
                    }
                }
            }
            if(count[i]>max_size){
                max_size=count[i];
                index=i;
            }
        }
        
        vector<int> ans;
        while(index!=-1){
            ans.insert(ans.begin(), nums[index]);
            index=pre[index];
        }
        return ans;
    }
};

//好吧，看了别人的答案，别人是。O(n^2)
//我这 O(2^n) 确实不行。。。
//这个我自己写的。。。超时了。。。。我以为我的够简便了。
//先sort。竟然还操时。。。。。。这。。。。。
//class Solution {
//public:
//    vector<int> largestDivisibleSubset(vector<int>& nums) {
//        sort(nums.begin(), nums.end(), less<int>());
//
//        ans.clear();
//        max_size=0;
//        int len = nums.size();
//        vector<int> tmp;
//        lar2(nums, tmp, 0, len);
//
//        return ans;
//    }
//
//private:
//    void lar2(vector<int>& nums,vector<int>& tmp,int i,int& len){
//        if(len-i+tmp.size()<max_size) return;
//        if(i==len){
//            //the end
//            if(tmp.size()>max_size){
//                ans=tmp;
//                max_size=tmp.size();
//            }
//            return;
//        }
//
//        if(tmp.empty()){
//            //put
//            tmp.push_back(nums[i]);
//            lar2(nums, tmp, i+1, len);
//            tmp.pop_back();
//            //not put
//            lar2(nums, tmp, i+1, len);
//        }else{
//            //not empty
//            if(nums[i]%tmp.back()==0){
//                //put
//                tmp.push_back(nums[i]);
//                lar2(nums, tmp, i+1, len);
//                tmp.pop_back();
//                //not put
//                lar2(nums, tmp, i+1, len);
//            }else{
//                //not put
//                lar2(nums, tmp, i+1, len);
//            }
//        }
//    }
//
//    vector<int> ans;
//    int max_size;
//};
