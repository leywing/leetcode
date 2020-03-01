//
//  174_dungeon_game.cpp
//  test
//
//  Created by ley on 2020/3/1.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//others solution from discussion
//this question ,I try to figure out from [0][0]----->[n-1][m-1]
//but too difficult,you need to deal with a lot of situation
//this solution is excellent       from the back to the front!!!!!!!!!good!!!!!remember it
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        if(n==0) return 1;
        int m=dungeon[0].size();
        vector<vector<int>> ley_vec(n+1,vector<int>(m+1,INT_MAX));
        ley_vec[n][m-1]=1;
        ley_vec[n-1][m]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int need=min(ley_vec[i][j+1],ley_vec[i+1][j])-dungeon[i][j];
                ley_vec[i][j]=max(1,need);
            }
        }
        return ley_vec[0][0];
    }
};

