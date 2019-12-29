//
//  118_pascals_triangle.cpp
//  test
//
//  Created by ley on 2019/12/29.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows==0) return ans;
        for(int i=0;i<numRows;i++){
            ans.push_back(vector<int>());
            for(int j=0;j<=i;j++){
                if(j==0||j==i) ans[i].push_back(1);
                else{
                    ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
            }
        }
        return ans;
    }
};
