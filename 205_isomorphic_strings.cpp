//
//  205_isomorphic_strings.cpp
//  test
//
//  Created by ley on 2020/3/13.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        if(s.size()==0) return true;
        unordered_set<char> leyset;
        unordered_map<char, char> leymap;
        for(int i=0;i<s.size();i++){
            if(leymap.find(s[i])!=leymap.end()){
                if(leymap[s[i]]!=t[i]){
                    return false;
                }
            }else{
                //not found in leymap
                if(leyset.find(t[i])!=leyset.end()){
                    leymap[s[i]]=t[i];
                    leyset.insert(t[i]);
                }else{
                    //find means have been used
                    return false;
                }
            }
        }
        return true;
    }
};
