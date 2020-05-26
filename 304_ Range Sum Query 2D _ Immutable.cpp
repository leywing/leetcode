//
//  304_ Range Sum Query 2D _ Immutable.cpp
//  test
//
//  Created by ley on 2020/5/26.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if(row==0){
            return;
        }
        int col=matrix[0].size();
        vector<int> tt3(col+1,0);
        sum.push_back(tt3);         //     0 0 0
                                    //     0 1 2
                                    //     0 2 4
        for(int i=0;i<row;i++){
            vector<int> t1;
            t1.push_back(0);
            int tmp=0;
            for(int j=0;j<col;j++){
                tmp+=matrix[i][j];      //col tmp sum
                int t2=tmp+sum[i][j+1];
                t1.push_back(t2);       //t2 i+1  j+1
            }
            sum.push_back(t1);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1]-sum[row2+1][col1]-sum[row1][col2+1]+sum[row1][col1];
    }
private:
    vector<vector<int>> sum;
    
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
