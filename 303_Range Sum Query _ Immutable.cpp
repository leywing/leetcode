//
//  303_Range Sum Query _ Immutable.cpp
//  test
//
//  Created by ley on 2020/5/26.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class NumArray {
public:
    NumArray(vector<int>& nums) {
        sum.push_back(0);
        int len=nums.size();
        long tmp_sum=0;
        for(int i=0;i<len;i++){
            tmp_sum+=nums[i];
            sum.push_back(tmp_sum);
        }
    }
    
    int sumRange(int i, int j) {
        int tmp=sum[j+1]-sum[i];
        return tmp;
    }
private:
    vector<long> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
