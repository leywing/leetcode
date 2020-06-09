//
//  334_ Increasing Triplet Subsequence.cpp
//  test
//
//  Created by ley on 2020/6/10.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len=nums.size();
        int ley[2]={INT_MAX,INT_MAX};
        
        for(int i=0;i<len;i++){
            if(nums[i]<=ley[0]){
                ley[0]=nums[i];
            }else{
                //nums[i]>ley[0]
                if(nums[i]>ley[1]){
                    return true;
                }else{
                    //nums[i]<=ley[1]
                    ley[1]=nums[i];
                }
            }
        }
        return false;
        
        
    }
};
