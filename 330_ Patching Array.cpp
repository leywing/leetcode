//
//  330_ Patching Array.cpp
//  test
//
//  Created by ley on 2020/6/7.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"


//i didn't come up with a solution
//others' solution from the discussion
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int size=nums.size();
        int needtopad=0;
        int t=0;
        long tmpmax=0;
        while(tmpmax<n){
            if(t<size && nums[t]<=tmpmax+1){
                tmpmax+=nums[t];
                t++;
            }else{
                needtopad++;
                tmpmax+=tmpmax+1;
            }
        }
        return needtopad;
    }
};
