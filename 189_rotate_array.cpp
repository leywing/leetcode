//
//  189_rotate_array.cpp
//  test
//
//  Created by ley on 2020/3/3.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //others reverse
        int n=nums.size();
        k=k%n;
        if(k==0||n<2) return;
        reverse(nums.begin(), nums.begin()-k+n);
        reverse(nums.begin()-k+n+1, nums.end());
        reverse(nums.begin(), nums.end());
        
        
        
        
//        int n=nums.size();
//        k=k%n;
//        for(int i=0;i<k;i++){
//            int tmp=nums.back();
//            nums.pop_back();
//            nums.insert(nums.begin(), tmp);
//        }
    }
};
