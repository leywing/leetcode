//
//  136_single_number.cpp
//  test
//
//  Created by ley on 2020/1/31.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //no extra memory ....这个我想不到
        //线性时间简单，用个map就完了
        unordered_map<int, int> map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        
        for(auto it=map.begin();it!=map.end();it++){
            if(it->second==1){
                return it->first;
            }
        }
        
        return -1;
    }
};

//wow others using XOR

//int singleNumber(int A[], int n) {
//    int result = 0;
//    for (int i = 0; i<n; i++)
//    {
//        result ^=A[i];
//    }
//    return result;
//}
