//
//  064_minimum_path_sum.cpp
//  test
//
//  Created by ley on 2019/12/11.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        if(row==0) return 0;
        int col=grid[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0&&j==0) continue;
                
                if(i==0){
                    grid[i][j]+=grid[i][j-1];
                    continue;
                }
                if(j==0){
                    grid[i][j]+=grid[i-1][j];
                    continue;
                }
                
                int up=grid[i-1][j];
                int left=grid[i][j-1];
                grid[i][j]=up>left?left+grid[i][j]:up+grid[i][j];
            }
        }
        
        return grid[row-1][col-1];
    }
};
