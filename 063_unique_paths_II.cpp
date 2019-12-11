//
//  063_unique_paths_II.cpp
//  test
//
//  Created by ley on 2019/12/11.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        if(row==0) return 0;
        int col=obstacleGrid[0].size();
      
        if(row==1){
            for(int i=0;i<col;i++){
                if(obstacleGrid[0][i]==1) return 0;
            }
            return 1;
        }
        if(col==1){
            for(int i=0;i<row;i++){
                if(obstacleGrid[i][0]==1) return 0;
            }
            return 1;
        }
        vector<vector<long long>> table;
        vector<long long> tmp(col,0);
        for(int i=0;i<row;i++){
            table.push_back(tmp);
        }
        
        
        //本来我是用它原本的数组做的
        //但是报错说出现了大于int范围的数
        //所以我新建了这个long long
        //但是现在看了别人的讨论，想了想，确实啊！那些超过的设成0就好了，绝对传不到终点。。。原因是题目设置了int型。。。233333，还是long long 严谨
        
        //好笑的是，这个方法感觉中国人小学学了奥数的，都知道，但对于外国人而言，就是一道全新的题目了
        for(int i=0;i<row;i++){
            if(obstacleGrid[i][0]!=1) table[i][0]=1;
            else{
                break;
            }
        }
        for(int j=0;j<col;j++){
            if(obstacleGrid[0][j]!=1) table[0][j]=1;
            else{
                break;
            }
        }
        
        
        if(obstacleGrid[row-1][col-1]==1) return 0;
        //col   row   all >2
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(obstacleGrid[i][j]==1) continue;
                
                table[i][j]=table[i-1][j]+table[i][j-1];
            }
        }
        
        int ans=table[row-1][col-1];
        return ans;
        
        
    }
};
