//
//  128_longest_consecutive_sequence.cpp
//  test
//
//  Created by ley on 2020/1/8.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());
        
        int ans=0;
        if(nums.size()==0) return ans;
        while (set.size()!=0) {
            int tmp_int=*set.begin();
            int i=1;
            while(set.count(tmp_int+i)){
                set.erase(tmp_int+i);
                i++;
            }
            int j=1;
            while(set.count(tmp_int-j)){
                set.erase(tmp_int-j);
                j++;
            }
            if(i+j-1>ans) ans=i+j-1;
            
            set.erase(tmp_int);
        }
        
        return ans;
        
    }
};
