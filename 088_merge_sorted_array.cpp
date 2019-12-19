//
//  088_merge_sorted_array.cpp
//  test
//
//  Created by ley on 2019/12/18.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        for(int k=0;k<n;k++){
            nums1.erase(nums1.end()-1);
        }
        
        while(i<m&&j<n){
            if(nums1[i]<=nums2[j]){
                i++;
            }else{
                //nums1[i]>nums2[j]
                nums1.insert(nums1.begin()+i, nums2[j]);
                i++;
                m++;
                j++;
            }
        }
        
        if(j>=n) return ;
        else{
            //j<n
            for(;j<n;j++){
                nums1.insert(nums1.begin()+i, nums2[j]);
                i++;
            }
        }
    }
};
