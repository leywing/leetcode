//
//  349_ Intersection of Two Arrays.cpp
//  test
//
//  Created by ley on 2020/6/12.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> u_map;
        vector<int> ans;
        for(auto a:nums1){
            u_map[a]=true;
        }
        
        int len2=nums2.size();
        for(int i=0;i<len2 && !u_map.empty();i++){
            if(u_map.find(nums2[i])!=u_map.end()){
                u_map.erase(nums2[i]);
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};
