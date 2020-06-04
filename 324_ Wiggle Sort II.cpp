//
//  324_ Wiggle Sort II.cpp
//  test
//
//  Created by ley on 2020/6/4.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//others' solution from discussion
//learn     nth_element
//learn     #define
//learn      amazing reorder way

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len=nums.size();
        
        auto midp=nums.begin()+len/2;
        nth_element(nums.begin(), midp, nums.end());    //   big   nth   small
        
        int mid=*midp;
    #define A(i) nums[(1+2*i)%(len|1)]
        int i=0,j=0,k=len-1;
        while(j<=k){
            if(A(j)>mid){
                swap(A(i++), A(j++));
            }else if(A(j)<mid){
                swap(A(j),A(k--));
            }else{
                j++;
            }
        }
    }
};
