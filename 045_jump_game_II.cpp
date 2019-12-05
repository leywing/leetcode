//
//  045_jump_game_II.cpp
//  test
//
//  Created by ley on 2019/12/5.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        //super easy DP
        int size=nums.size();
        vector<int> a;
        for(int i=0;i<size;i++){
            a.push_back(i);
        }
        for(int i=0;i<size;i++){
            int t=nums[i];
            if(i-1>=0&&nums[i-1]>nums[i]){
                continue;
            }
            for(int j=1;j<=t;j++){
                if((i+j)<size){
                    if(a[i]+1<a[i+j]) a[i+j]=a[i]+1;
                }
            }
        }
        
        return a[size-1];
    }
};
