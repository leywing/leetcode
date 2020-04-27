//
//  242_valid_anagram.cpp
//  test
//
//  Created by ley on 2020/4/28.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26]={0};
        for(auto b:s){
            a[b-'a']++;
        }
        for(auto b:t)
        {
            a[b-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(a[i]!=0) return false;
        }
        return true;
    }
};
