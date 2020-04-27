//
//  260_single_number_III.cpp
//  test
//
//  Created by ley on 2020/4/28.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
//others' solution from discussion
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int axorb=0;
        for(auto& t:nums){
            axorb=axorb^t;
        }
        int last_bit=axorb&(-axorb);
        vector<int> ans;
        int a=0,b=0;
        for(auto& t:nums){
            if(t&last_bit){
                a=a^t;
            }else{
                b=b^t;
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};


//class Solution {
//public:
//    vector<int> singleNumber(vector<int>& nums) {
//        unordered_map<int, int> mp;
//        for(auto& a:nums){
//            mp[a]++;
//        }
//        vector<int> ans;
//        for(auto&b:mp){
//            if(b.second==1){
//                ans.push_back(b.first);
//            }
//        }
//        return ans;
//    }
//};

//i&（-i）。  或者。 i&（i-1）      得到最小位为1的
//   7   0111
//   -7    全部取反+1
