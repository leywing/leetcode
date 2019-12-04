//
//  044_wildcard_matching_2_can_pass.cpp
//  test
//
//  Created by ley on 2019/12/4.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len=s.size();
        int p_len=p.size();
        int s_star=-1,p_star=-1;
        int i,j;
        
        for(i=0,j=0;i<s_len;i++,j++){
            if(j<p_len&&p[j]=='*'){
                //this j    the author didn't think of .  it's found from the reply from someone else
                
                //new star
                //so you don't need to save the past star,  because star can pass any sequence
                s_star=i;
                p_star=j;
                i--;
            }else{
                if(j>=p_len||(p[j]!='?'&&p[j]!=s[i]))
                {
                    if(s_star>=0){
                        i=s_star++;
                        j=p_star;
                    }else return false;
                }
                
            }
        }
        
        while(j<p_len&&p[j]=='*') j++;
        
        return j==p_len;
    }
};
