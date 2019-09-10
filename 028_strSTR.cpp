//
//  028_strSTR.cpp
//  test
//
//  Created by ley on 2019/9/8.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hay_size=haystack.size();
        int need_size=needle.size();
        if(need_size==0) return 0;
        
        bool flag=1;
        int ans;
        for(int i=0;i<hay_size-need_size+1;i++){
            if(haystack[i]==needle[0]){
                ans=i;
                for(int j=1;j<need_size;j++){
                    if(haystack[i+j]!=needle[j]){
                        flag=0;
                        break;
                    }
                }
                if(flag==1){
                    return ans;
                }else{
                    flag=1;
                }
            }
        }
        
        return -1;
    }
};
