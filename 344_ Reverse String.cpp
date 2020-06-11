//
//  344_ Reverse String.cpp
//  test
//
//  Created by ley on 2020/6/11.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len=s.size();
        int i=0,j=len-1;
        while(i<j){
            //int tmp=s[i];
            //s[i]=s[j];
            //s[j]=tmp;
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};
