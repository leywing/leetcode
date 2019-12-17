//
//  080_remove_duplicates_from_sorted_array.cpp
//  test
//
//  Created by ley on 2019/12/17.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        int i=0;
        int flag=INT_MAX;
        int flag2=0;
        while(i<nums.size()){
            if(flag==nums[i]){
                if(flag2==1){
                    nums.erase(nums.begin()+i);
                    continue;
                }else{
                    //flag2=0;
                    flag2=1;
                    i++;
                }
            }else{
                flag=nums[i];
                flag2=0;
                i++;
            }
        }
        
        return nums.size();
        
    }
};
