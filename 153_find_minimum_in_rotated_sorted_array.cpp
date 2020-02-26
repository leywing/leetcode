//
//  153_find_minimum_in_rotated_sorted_array.cpp
//  test
//
//  Created by ley on 2020/2/25.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        else if(n==2) return min(nums[0],nums[1]);
        
        if(nums[0]<nums[n-1]){
            return nums[0];
        }else if(nums[0]>nums[n-1]){
            //混乱排序。   457012
            int lf=0;
            int rg=n-1;
            int mid;
            while(rg-lf>=2){
                mid=lf+(rg-lf)/2;
                if(nums[mid]>=nums[lf]){
                    lf=mid;
                    continue;
                }else if(nums[mid]<=nums[rg]){
                    rg=mid;
                    continue;
                }else{
                    //nums[mid]<nums[lf]   nums[mid]>nums[rg]
                    cout<<"error"<<endl;
                }
            }
            
            return min(nums[lf],nums[rg]);
        }else{
            //nums[0]==nums[n-1]
            int ans=nums[0];
            for(int i=1;i<n;i++){
                ans=min(ans,nums[i]);
            }
            return ans;
        }
        
    }
};
