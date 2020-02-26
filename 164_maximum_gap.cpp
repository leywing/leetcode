//
//  164_maximum_gap.cpp
//  test
//
//  Created by ley on 2020/2/25.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        int amin=nums[0],amax=nums[0];
        for(int i=1;i<n;i++){
            amin=amin<nums[i]?amin:nums[i];
            amax=amax>nums[i]?amax:nums[i];
        }
        if(amax==amin) return 0;
        //find the min and the max
        //the gap will bigger than       gap>=(max-min)/(n-1) or >=1
        //so need   bucket  (max-min)/gap= n-1      need plus one?
        int gap=max((amax-amin)/(n-1),1);
        int kn=(amax-amin)/gap+1;   //need plus one???? yes  because amin will be in 0 bucket, while amax will be in kn bucket    so 0-kn  need kn+1
        vector<int> bucket_max(kn,INT_MIN);
        vector<int> bucket_min(kn,INT_MAX);
        
        for(int i=0;i<n;i++){
            int k=(nums[i]-amin)/gap;
            bucket_max[k]=bucket_max[k]>nums[i]?bucket_max[k]:nums[i];
            bucket_min[k]=bucket_min[k]<nums[i]?bucket_min[k]:nums[i];
        }
        
        int ans=gap;
        int i=0;
        int j;
        while(i<kn){
            j=i+1;
            while(j<kn&&bucket_min[j]==INT_MAX&&bucket_max[j]==INT_MIN){
                j++;
            }
            if(j==kn) break;
            if(bucket_min[j]-bucket_max[i]>ans){
                ans=bucket_min[j]-bucket_max[i];
            }
            i=j;
        }
        return ans;
        
        
    }
};
