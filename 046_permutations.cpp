//
//  046_permutations.cpp
//  test
//
//  Created by ley on 2019/12/5.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        per2(0,nums,ans);
        
        return ans;
    }
    
    void per2(int spot,vector<int>& nums,vector<vector<int>>& ans){
        if(spot>=nums.size()-1){
            //i found that nums.size()-1 is enough
            ans.push_back(nums);
            return;
        }
        
        for(int i=spot;i<nums.size();i++){
            swap(nums[spot], nums[i]);
            per2(spot+1,nums,ans);
            swap(nums[spot], nums[i]);
        }
        
    }
    //the next not use &nums,so don't need the second swap,can fast 33%
    
//    void per2(int spot,vector<int> nums,vector<vector<int>>& ans){
//        if(spot>=nums.size()-1){
//            //i found that nums.size()-1 is enough
//            ans.push_back(nums);
//            return;
//        }
//
//        for(int i=spot;i<nums.size();i++){
//            swap(nums[spot], nums[i]);
//            per2(spot+1,nums,ans);
//            //swap(nums[spot], nums[i]);
//        }
//
//    }
};
