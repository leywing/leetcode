//
//  035_search_insert_position.cpp
//  test
//
//  Created by ley on 2019/10/22.
//  Copyright © 2019 ley. All rights reserved.
//

#include "leetcode.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        
        int i=0,j=n-1;
        if(nums[j]<target) return j+1;
        
        int mid=(i+j)/2;
        while(i<j){
            mid=(i+j)/2;
            if(nums[mid]<target){
                i=mid+1;
            }else if(nums[mid]==target){
                return mid;
            }else{
                //nums[mid]>target
                j=mid;
            }
        }
        
        
        
        return i;
    }
};
