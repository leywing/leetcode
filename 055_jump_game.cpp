//
//  055_jump_game.cpp
//  test
//
//  Created by ley on 2019/12/10.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==0||n==1) return 1;
        vector<int> a(n,0);
        
        a[0]=1;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                if(nums[i]+i>=n-1) return 1;
                else{
                    if(i-1>=0&&a[i-1]==1&&nums[i-1]>nums[i]) continue;
                    if(nums[i]==0) continue;
                    for(int j=1;j<=nums[i];j++){
                        a[i+j]=1;
                    }
                }
            }else{
                //!!!!
                return false;
            }
            
        }
        return false;
        
    }
};
