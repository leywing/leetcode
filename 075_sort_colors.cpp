//
//  075_sort_colors.cpp
//  test
//
//  Created by ley on 2019/12/15.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if(n==1||n==0) return ;
        int i0=0;
        int i1=0;
        int flag_1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i0]=0;
                i0++;
                if(flag_1==1){
                    nums[i1]=1;
                    i1++;
                }else{
                    i1=i0;
                }
            }else if(nums[i]==1){
                if(flag_1==0){
                    nums[i1]=1;
                    i1++;
                    flag_1=1;
                }else{
                    nums[i1]=1;
                    i1++;
                }
            }
            if(i>i1-1){
            nums[i]=2;
            }
        }
    }
};
