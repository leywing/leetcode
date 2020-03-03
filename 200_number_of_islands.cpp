//
//  200_number_of_islands.cpp
//  test
//
//  Created by ley on 2020/3/3.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int hang=grid.size();
        if(hang==0) return 0;
        int lie=grid[0].size();
        if(lie==0) return 0;
        
        int ans=0;
        for(int i=0;i<hang;i++){
            for(int j=0;j<lie;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    num2(grid, i, j);
                }
            }
        }
        return ans;
        
    }
private:
    void num2(vector<vector<char>>& grid,int i,int j){
        int hang=grid.size();
        int lie=grid[0].size();
        if(i<0||i>=hang||j<0||j>=lie) return;
        if(grid[i][j]!='1') return;
        grid[i][j]='b';
        num2(grid, i+1, j);
        num2(grid, i-1, j);
        num2(grid, i, j+1);
        num2(grid, i, j-1);
    }
};
