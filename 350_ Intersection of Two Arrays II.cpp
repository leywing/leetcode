//
//  350_ Intersection of Two Arrays II.cpp
//  test
//
//  Created by ley on 2020/6/12.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> u_map;
        for(const auto& a:nums1){
            u_map[a]++;
        }
        
        vector<int> ans;
        for(const auto& b:nums2){
            if(u_map.find(b)!=u_map.end()){
                if(u_map[b]>0){
                    ans.push_back(b);
                    u_map[b]--;
                }
            }
        }
        return ans;
    }
};
