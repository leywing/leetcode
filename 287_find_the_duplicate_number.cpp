//
//  287_find_the_duplicate_number.cpp
//  test
//
//  Created by ley on 2020/5/21.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
//others
//see the discussion and get the answer
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=0,slow=0;
        while(true){
            fast=nums[nums[fast]];
            slow=nums[slow];
            
            //see as a link-list
            //find the cycle (using fast and slow)  because the same number will point to nums[same] so cycle
            if(fast==slow){
                fast=0;
                while(nums[fast]!=nums[slow]){
                    //A=2B
                    //A-B=c
                    //A=a+b+nc
                    //B=a+b+(n-1)c
                    ///so c=a+b so slow need c-b=a step to the rukou,   0 need a step to the rukou
                    fast=nums[fast];
                    slow=nums[slow];
                }
                return nums[slow];
            }
        }
    }
};



//too slow   O(n^2)
//class Solution {
//public:
//    int findDuplicate(vector<int>& nums) {
//        int len=nums.size();
//        for(int i=0;i<len;i++){
//            for(int j=i+1;j<len;j++){
//                if(nums[i]==nums[j]){
//                    return nums[i];
//                }
//            }
//        }
//        return -1;
//    }
//};
