//
//  345_ Reverse Vowels of a String.cpp
//  test
//
//  Created by ley on 2020/6/11.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        int dict[256]={0};
        dict['a']=1; dict['A']=1;
        dict['e']=1; dict['E']=1;
        dict['i']=1; dict['I']=1;
        dict['o']=1; dict['O']=1;
        dict['u']=1; dict['U']=1;
        while(i<j){
            while(i<j && dict[s[i]]==0) i++;
            while(i<j && dict[s[j]]==0) j--;
            if(i<j) swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};
