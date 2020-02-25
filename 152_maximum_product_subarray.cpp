//
//  152_maximum_product_subarray.cpp
//  test
//
//  Created by ley on 2020/2/17.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    
    //the ans is from the discussion    others'    super brilliant
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        for(int i=1,imax=nums[0],imin=nums[0];i<n;i++){
            if(nums[i]<0){
                swap(imax, imin);
            }
            
            imax=max(nums[i],nums[i]*imax);
            imin=min(nums[i],nums[i]*imin);
                
            ans=max(ans,imax);

        }
        
        return ans;
        
    }
};
