//
//  058_length_of_the_last_word.cpp
//  test
//
//  Created by ley on 2019/12/11.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()==0) return 0;
        
        int ans=0;
        
        int flag=0;
        for(int i=s.size()-1;i>=0;i--){
            if(flag==0&&s[i]==' ') continue;
            //meet the first one
            flag=1;
            if(s[i]!=' '){
                ans++;
                continue;
            }else{
                break;
            }
        }
        
        return ans;
    }
};
