//
//  137_single_number_II.cpp
//  test
//
//  Created by ley on 2020/1/31.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        unordered_map<int, int> map;
//        int n=nums.size();
//        for(int i=0;i<n;i++){
//            map[nums[i]]++;
//        }
//
//        for(int i=0;i<n;i++){
//            if(map[nums[i]]==1) return nums[i];
//        }
//
//        return -1;
//    }
//};

//others
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int first=0,second=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            first=(first^nums[i])&~second;
            second=(second^nums[i])&~first;
            //  00->10->01->00
            // first 010 0
            // second 0 010
        }
        
        return first;
    }
};


