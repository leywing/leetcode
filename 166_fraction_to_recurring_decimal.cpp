//
//  166_fraction_to_recurring_decimal.cpp
//  test
//
//  Created by ley on 2020/2/27.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    //see the answer from the discussion
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0){
            return "0";
        }
        string ans;
        if(numerator>0^denominator>0){
            ans+='-';
        }
        long beichushu=labs(numerator),chushu=labs(denominator),r=beichushu%chushu;
        ans+=to_string(beichushu/chushu);
        if(!r){
            return ans;
        }else{
            ans+='.';
        }
        
        unordered_map<long, int> rmap;
        while(r){
            if(rmap.find(r)!=rmap.end()){
                //not found
                ans.insert(rmap[r], "(");//this need to be "str" string , not char '('
                ans+=')';
                return ans;
            }
            rmap[r]=ans.size();
            r*=10;
            ans+=to_string(r/chushu);
            r=r%chushu;
        }
        
        return ans;
    }
};
