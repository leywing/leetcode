//
//  089_gray_code.cpp
//  test
//
//  Created by ley on 2019/12/20.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0){
            vector<int> ans={0};
            return ans;
        }
        if(n==1){
            vector<int> ans={0,1};
            return ans;
        }
        
        vector<int> ans={0,1,3,2};
        
        if(n==2) return ans;
        
        int tmp=2;
        for(int i=2;i<n;i++){
            tmp=tmp*2;
            int size=ans.size();
            for(int j=size-1;j>=0;j--){
                ans.push_back(ans[j]+tmp);
            }
        }
        
        return ans;
        
        
    }
};
