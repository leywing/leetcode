//
//  162_find_peak_element.cpp
//  test
//
//  Created by ley on 2020/2/25.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        else if(n==2){
            if(nums[0]>nums[1]) return 0;
            else return 1;
        }
        
        //二分法
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        
        int lf=0;
        int rg=n-1;
        int mid;
        while(rg-lf>=2){
            mid=lf+(rg-lf)/2;
            if(nums[mid]<nums[mid-1]){
                rg=mid-1;
            }else if(nums[mid]<nums[mid+1]){
                lf=mid+1;
            }else{
                return mid;
            }
        }
       
        mid=(nums[lf]>nums[rg])?lf:rg;
        return mid;
        
        
    }
};
