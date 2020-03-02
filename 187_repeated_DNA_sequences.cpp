//
//  187_repeated_DNA_sequences.cpp
//  test
//
//  Created by ley on 2020/3/2.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //others
        unordered_map<int, int> map;
        vector<string> ans;
        long t=0;
        for(int i=0;i<s.size();i++){
            if(map[t=t<<3&0x3fffffff|s[i]&7]++==1){
                ans.push_back(s.substr(i-9,10));
            }
        }
        return ans;
        
        
        
//my solution
//        int n=s.size();
//        vector<string> ans;
//        unordered_map<string, int> map;
//        for(int i=0;i<=n-10;i++){
//            string tmp=s.substr(i,10);
//            if(map[tmp]==1){
//                ans.push_back(tmp);
//            }
//            map[tmp]++;
//        }
//        return ans;
    }
};
