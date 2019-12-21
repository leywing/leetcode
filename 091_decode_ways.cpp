//
//  091_decode_ways.cpp
//  test
//
//  Created by ley on 2019/12/22.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(s[0]=='0') return 0;
        
        vector<int> count(n,0);
        
        if(n==1) return 1;
        count[0]=1;
        if(s[1]-'0'==0&&s[0]-'0'>2) return 0;
        if(( (s[0]-'0'==1) || (s[0]-'0'==2&&s[1]-'0'<=6) )&&(s[1]-'0'!=0) ) count[1]=2;
        else count[1]=1;
        
        for(int i=2;i<n;i++){
            if(s[i]-'0'==0){
                if(s[i-1]-'0'!=1&&s[i-1]-'0'!=2) return 0;
                count[i]=count[i-2];
            }else if(s[i-1]-'0'==0){
                count[i]=count[i-1];
            }else if( (s[i-1]-'0'==1)  ||  (s[i-1]-'0'==2&&s[i]-'0'<=6) ){
                count[i]=count[i-1]+count[i-2];
            }else{
                count[i]=count[i-1];
            }
            
        }
        
        return count[n-1];
    }
};
