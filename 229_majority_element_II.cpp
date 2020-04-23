//
//  229_majority_element_II.cpp
//  test
//
//  Created by ley on 2020/4/23.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//更慢，用的空间更多。。。。但分析确实是O（N）time  O(1) space
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> ma;
        for(int i=0;i<nums.size();i++){
            if(ma.find(nums[i])!=ma.end()){
                ma[nums[i]]++;
            }else if(ma.size()==2){
                vector<int> tmp;
                for(auto& a:ma){
                    a.second--;
                    if(a.second==0){
                        tmp.push_back(a.first);
                    }
                }
                for(auto& c:tmp){
                    ma.erase(c);
                }
            }else{
                ma[nums[i]]++;
            }
        }
        
        vector<int> ans;
        if(ma.size()==0) return ans;
        else{
            for(auto& a:ma){
                a.second=0;
            }
            for(auto& t:nums){
                if(ma.find(t)!=ma.end()){
                    ma[t]++;
                }
            }
            int tmp=nums.size()/3;
            for(auto& a:ma){
                if(a.second>tmp){
                    ans.push_back(a.first);
                }
            }
        }
        return ans;
    }
};



//enough fast  but not meet the question's requirement
//O(N) time  O(1) space
//class Solution {
//public:
//    vector<int> majorityElement(vector<int>& nums) {
//        unordered_map<int, int> ma;
//        int nums_len=nums.size();
//        int a=nums_len/3;
//        for(auto t:nums){
//            ma[t]++;
//        }
//        vector<int> ans;
//        for(auto t:ma){
//            if(t.second>a){
//                ans.push_back(t.first);
//            }
//        }
//        return ans;
//    }
//};
