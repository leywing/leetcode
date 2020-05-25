//
//  300_Longest Increasing Subsequence.cpp
//  test
//
//  Created by ley on 2020/5/25.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        if(len==0) return 0;
        vector<int> vec;
        //int vec_size=1;
        vec.push_back(nums[0]);
        
        for(int i=1;i<len;i++){
            if(nums[i]>vec.back()){
                vec.push_back(nums[i]);
            }else if(nums[i]<vec.back()){
                len2(vec,nums[i]);
            }else{
                // == do nothing
            }
        }
        
        return vec.size();
        
    }
private:
    void len2(vector<int>& vec,const int& num){
        int up=vec.size()-1;  //  vec[up] > num
        //二分查找
        int low=0;
        if(vec[0]>=num){
            vec[0]=num;
            return;
        }   //vec[low] < num
        int mid;
        while(up-low>1){
            mid=(up-low)/2+low;
            if(vec[mid]>=num){
                up = mid;
            }else{
                low = mid;
            }
        }
        
        vec[up]=num;
    }
};

//这个我做过
//先写个蠢的O(n^2)
//再写O(nlogn)的
//class Solution {
//public:
//    //this one pass O(n^2)
//    int lengthOfLIS(vector<int>& nums) {
//        int len=nums.size();
//        vector<int> vec(len,1);
//        int max=1;
//        if(len==0) return 0;
//        for(int i=0;i<len;i++){
//            for(int j=0;j<i;j++){
//                if(nums[i]>nums[j]){
//                    vec[i]=vec[i]>=(vec[j]+1)?vec[i]:vec[j]+1;
//                    max=max>=vec[i]?max:vec[i];
//                }
//            }
//        }
//        return max;
//    }
//};
