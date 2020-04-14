//
//  219_contain_duplicate_II.cpp
//  test
//
//  Created by ley on 2020/4/15.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len=nums.size();
        unordered_map<int, int> u_mp;
        for(int i=0;i<len;i++){
            if(u_mp.find(nums[i])!=u_mp.end()){
                //存在
                if(i-u_mp[nums[i]]<=k){
                    return true;
                }
                u_mp[nums[i]]=i;
            }else{
                u_mp[nums[i]]=i;
            }
        }
        return false;
    }
};
