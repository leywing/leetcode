//
//  041_first_missing_positive.cpp
//  test
//
//  Created by ley on 2019/12/3.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int nums_size=nums.size();
        for(int i=0;i<nums_size;i++){
            if(nums[i]<=0) nums[i]=-1;
        }
        int n=0;
        bool flag=0;
        while(1){
            n++;
            for(int i=0;i<nums_size;i++){
                nums[i]=nums[i]-1;
                if(nums[i]==0){
                    flag=true;
                }
            }
            if(flag==false) break;
            else flag=false;
        }
        
        return n;
    }
};
