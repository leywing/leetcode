//
//  120_triangle.cpp
//  test
//
//  Created by ley on 2019/12/29.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        if(row==0) return 0;
        //vector<int> ans(row,INT_MAX);
        for(int i=0;i<row;i++){
            if(i==0) continue;
            if(i==1){
                triangle[1][0]+=triangle[0][0];
                triangle[1][1]+=triangle[0][0];
                continue;
            }
            for(int j=0;j<=i;j++){
                if(j==0){
                    triangle[i][0]+=triangle[i-1][0];
                }else if(j==i){
                    triangle[i][j]+=triangle[i-1][j-1];
                }else{
                    triangle[i][j]+=min_of_two(triangle[i-1][j-1], triangle[i-1][j]);
                }
            }
        }
        
        int ans=INT_MAX;
        for(int i=0;i<row;i++){
            ans=triangle[row-1][i]<ans?triangle[row-1][i]:ans;
        }
        
        return ans;
        
    }
    
    int min_of_two(int i,int j){
        return i>j?j:i;
    }
};
