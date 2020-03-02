//
//  179_largest_number.cpp
//  test
//
//  Created by ley on 2020/3/2.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    //others' solution from discussion     s1+s2>s2+s1 is so brilliant
    string largestNumber(vector<int>& nums) {
        string ans;
        vector<string> ley_string;
        for(auto a:nums){
            ley_string.push_back(to_string(a));
        }
        sort(ley_string.begin(), ley_string.end(), [](string& s1,string& s2){return s1+s2>s2+s1;});
        for(auto a:ley_string){
            ans+=a;
        }
        if(ans[0]=='0') return "0";
        return ans;
    }
    
};
