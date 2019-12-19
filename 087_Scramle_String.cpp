//
//  087_Scramle_String.cpp
//  test
//
//  Created by ley on 2019/12/19.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    
    //others' method
    //excellent!!!!!
    
    //递归下去。  直到1，1 or 1，2 这样，完美啊！！！！  递归的美
    
    bool isScramble(string s1, string s2) {
        if(s1==s2) return true;
        int n=s1.size();
        if(n!=s2.size()) return false;

        int count[26]={0};
        for(int i=0;i<n;i++){
            count[s1[i]-'a']++;
        }
        
        for(int i=0;i<n;i++){
            count[s2[i]-'a']--;
            if(count[s2[i]-'a']<0) return false;
        }
        
        for(int i=1;i<=n-1;i++){
            if(isScramble(s1.substr(0,i), s2.substr(0,i))&&isScramble(s1.substr(i), s2.substr(i))) return true;
            if(isScramble(s1.substr(0,i), s2.substr(n-i))&&isScramble(s1.substr(i), s2.substr(0,n-i))) return true;
        }
        
        return false;
    
        
    }
};
