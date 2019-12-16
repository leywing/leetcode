//
//  076_minimum_window_substring_from_others.cpp
//  test
//
//  Created by ley on 2019/12/16.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    
    //i see if from discussion
    //other's method
    //so great
    //!!!!learn it
    string minWindow(string s, string t) {
        vector<int> m(128,0);
        int begin=0,end=0,minStart=0,minLen=INT_MAX,counter=t.size();
        for(auto c:t){
            m[c]++;
        }
        
        while(end<s.size()){
            if(m[s[end]]>0) counter--;
            m[s[end]]--;
            end++;
            
            while(counter==0){
                if(end-begin<minLen){
                    minStart=begin;
                    minLen=end-begin;
                    //because the end have plus one
                }
                
                m[s[begin]]++;
                //not in t at most to 0
                //in t get bigger than 0
                if(m[s[begin]]>0) counter++;
                begin++;
            }
        }
        
        if(minLen==INT_MAX) return "";
        else return s.substr(minStart,minLen);
    }
};
