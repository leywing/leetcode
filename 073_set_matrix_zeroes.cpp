//
//  073_set_matrix_zeroes.cpp
//  test
//
//  Created by ley on 2019/12/14.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if(row==0) return ;
        int col=matrix[0].size();
        
        unordered_map<int, int> map;
        //row
        
        for(int i=0;i<row;i++){
            int flag_row=0;
            for(int j=0;j<col;j++){
                if(matrix[i][j]!=0) continue;
                else{
                    map[j]=1;
                    flag_row=1;
                }
            }
            if(flag_row==1){
                for(int j=0;j<col;j++){
                    matrix[i][j]=0;
                }
            }
        }
        
        //col
        for(int j=0;j<col;j++){
            if(map.find(j)!=map.end()){
                for(int i=0;i<row;i++){
                    matrix[i][j]=0;
                }
            }
        }
        
        
    }
};
