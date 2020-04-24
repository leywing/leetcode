//
//  238_product_of_array_except_self.cpp
//  test
//
//  Created by ley on 2020/4/24.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//from the discussion
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int left=1;
        for(int i=0;i<n;i++){
            if(i>0) left*=nums[i-1];
            ans[i]=left;
        }
        
        int right=1;
        for(int i=n-1;i>=0;i--){
            if(i<n-1) right*=nums[i+1];
            ans[i]*=right;
        }
        return ans;
    }
};



//满足其他要求，但不满足  不用除法
//class Solution {
//public:
//    vector<int> productExceptSelf(vector<int>& nums) {
//        //不用除法，还要O(n)。想不到。。。。
//        int nums_len=nums.size();
//        vector<int> ans(nums_len,0);
//        vector<int> tmp0;
//        int total=1;
//        for(int i=0;i<nums_len;i++){
//            if(nums[i]==0){
//                tmp0.push_back(i);
//            }else{
//                total*=nums[i];
//            }
//        }
//
//        if(tmp0.size()>=2){
//            return ans;
//        }else if (tmp0.size()==1){
//            ans[tmp0[0]]=total;
//            return ans;
//        }else{
//            for(int i=0;i<nums_len;i++){
//                ans[i]=total/nums[i];
//            }
//            return ans;
//        }
//
//    }
//};
