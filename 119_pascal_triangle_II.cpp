//
//  119_pascal_triangle_II.cpp
//  test
//
//  Created by ley on 2019/12/29.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        if(rowIndex==0) return ans;
        for(int i=1;i<=rowIndex;i++){
            for(int j=i;j>=0;j--){
                if(j==0){
                    continue;
                }else if(j==i) ans.push_back(1);
                else{
                    ans[j]+=ans[j-1];
                }
            }
        }
        return ans;
    }
};
