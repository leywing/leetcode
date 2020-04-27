//
//  268_missing_number.cpp
//  test
//
//  Created by ley on 2020/4/28.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long total=0;
        for(int i=0;i<=nums.size();i++){
            total+=i;
        }
        for(auto& a:nums){
            total=total-a;
        }
        return int(total);
    }
};
