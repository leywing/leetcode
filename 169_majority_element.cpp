//
//  169_majority_element.cpp
//  test
//
//  Created by ley on 2020/2/29.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ley_map;
        int n=nums.size();
        int tmp=n/2+1;
        for(int i=0;i<n;i++){
            ley_map[nums[i]]++;
            if(ley_map[nums[i]]>=tmp){
                return nums[i];
            }
        }
        return -1;
    }
};

// others answer  from discussion    excellent!!!!!
//public class Solution {
//    public int majorityElement(int[] num) {
//
//        int major=num[0], count = 1;
//        for(int i=1; i<num.length;i++){
//            if(count==0){
//                count++;
//                major=num[i];
//            }else if(major==num[i]){
//                count++;
//            }else count--;
//
//        }
//        return major;
//    }
//}
