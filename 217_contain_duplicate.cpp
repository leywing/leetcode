//
//  217_contain_duplicate.cpp
//  test
//
//  Created by ley on 2020/4/7.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto a:nums){
            map[a]++;
            if(map[a]>=2) return true;
        }
        return false;
    }
};
