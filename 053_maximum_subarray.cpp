//
//  053_maximum_subarray.cpp
//  test
//
//  Created by ley on 2019/12/8.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp_sum=0;
        int min=0;
        
        int ans=0x80000000;
        
        for(int i=0;i<nums.size();i++){
            temp_sum+=nums[i];
            if(temp_sum-min>ans) ans=temp_sum-min;
            min=min<temp_sum?min:temp_sum;
        }
        
        return ans;
    }
};
        
        
        
