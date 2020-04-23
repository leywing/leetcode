//
//  228_summary_ranges.cpp
//  test
//
//  Created by ley on 2020/4/23.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int nums_len=nums.size();
        if(nums_len==0) return ans;
        string tmp;
        int past;
        bool flag=false;
        for(int i=0;i<nums_len;i++){
            if(i==0){
                tmp=to_string(nums[i]);
                past=nums[i];
            }else{
                if(!flag){
                    if(nums[i-1]!=INT_MAX && nums[i]==nums[i-1]+1){
                        flag=true;
                        tmp=tmp+"->";
                    }else{
                        ans.push_back(tmp);
                        tmp=to_string(nums[i]);
                    }
                }else{
                    //flag=true
                    if(nums[i-1]!=INT_MAX && nums[i]==nums[i-1]+1){
                        continue;
                    }else{
                        tmp=tmp+to_string(nums[i-1]);
                        ans.push_back(tmp);
                        tmp=to_string(nums[i]);
                        flag=false;
                    }
                }
            }
        }
        
        if(flag){
            tmp=tmp+to_string(nums[nums_len-1]);
        }
        ans.push_back(tmp);
        return ans;
    }
};
