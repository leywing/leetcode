//
//  167_two_sum_II_the_input_array_is_sorted.cpp
//  test
//
//  Created by ley on 2020/2/29.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // left+right   < left++      > right --
        vector<int> ans;
        int left=0;
        int n=numbers.size();
        int right=n-1;
        while(left<right){
            if(numbers[left]+numbers[right]==target){
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }else if(numbers[left]+numbers[right]<target){
                left++;
            }else{
                //numbers[left]+numbers[right]>target
                right--;
            }
        }
        return ans;
    }
};
