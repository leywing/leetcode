//
//  220_contain_duplicate_III.cpp
//  test
//
//  Created by ley on 2020/4/15.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//from others in discussion
//重点 ：用到了 set    自动排序。  那么实际只要比较。  nums[i]-t<=   *aa   <= nums[i]+t
//维持一个window,  找出其中最小的 >=nums[i]-t的。   由于它最小，所以它最有可能<=nums[i]+t   检验它即可
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> st;
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(i>k) st.erase(nums[i-k-1]);
            auto aa=st.lower_bound((long long)nums[i]-t); //找到最小的，大于nums[i]-t的数
            if(aa!=st.end()&&*aa-nums[i]<=t) return true;
            st.insert(nums[i]);
        }
        return false;
    }
};



// time limit exceeded
//class Solution {
//public:
//    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//        int len=nums.size();
//        long tmp1;
//        long tmp2;
//        for(int i=0;i<len;i++){
//            tmp1=nums[i];
//            for(int j=1;j<=k&&i+j<len;j++){
//                tmp2=nums[i+j];
//                tmp2=labs(tmp2-tmp1);
//                if(tmp2<=t){
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//};
