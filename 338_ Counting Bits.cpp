//
//  338_ Counting Bits.cpp
//  test
//
//  Created by ley on 2020/6/11.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);   //2 need 3 space
        int i=2;
        // 0------num
        while(i<=num){
            ans[i]=1;
            i=i*2;
        }
        if(num==0) return vector<int>{0};
        if(num==1) return vector<int>{0,1};
        if(num==2) return vector<int>{0,1,1};
        ans[1]=1;ans[2]=1;
        int tmp_2=2;
        i=3;
        while(i<=num){
            if(ans[i]==1){
                tmp_2=i;
            }else{
                //ans[i]!=i
                ans[i]=ans[i-tmp_2]+1;
                
            }
            
            i++;
        }
        return ans;
    }
};
