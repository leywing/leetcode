//
//  209_minimum_size_subarray_sum.cpp
//  test
//
//  Created by ley on 2020/3/24.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int head=0,tail=0;
        //s>0, nums[i]>0
        int n=nums.size();
        int sum=0;
        int ans=INT_MAX;
        while(head<n){
            sum+=nums[head];
            while(sum>=s&&tail<=head){
                int tmp=head-tail+1;
                ans=ans<tmp?ans:tmp;
                sum-=nums[tail];
                tail++;
            }
            head++;
        }
        
        if(ans==INT_MAX) return 0;
        return ans;
    }
};
