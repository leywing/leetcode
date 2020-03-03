//
//  198_house_robber.cpp
//  test
//
//  Created by ley on 2020/3/3.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> ve(n+2,0);
        for(int i=2;i<n+2;i++){
            ve[i]=max(ve[i-1],ve[i-2]+nums[i-2]);
        }
        return ve[n+1];
    }
};

