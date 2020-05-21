//
//  283_move_zeroes.cpp
//  test
//
//  Created by ley on 2020/4/30.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()<=1) return;
        int i=0;
        int inot=0;
        int n=nums.size();
        while(inot<n){
            if(nums[inot]!=0){
                if(inot>i){
                nums[i]=nums[inot];
                nums[inot]=0;
                }
                inot++;
                i++;
            }else{
                inot++;
            }
        }
        
    }
};
