//
//  240_search_a_2d_matrix_II.cpp
//  test
//
//  Created by ley on 2020/4/25.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//from the discussion
//brilliant!!!!!!!

//my solution timelimit exceed

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        if(row==0) return false;
        int col=matrix[0].size();
        if(col==0) return false;
        
        int i=0,j=col-1;
        while(i<row && j>=0){
            if(matrix[i][j]==target){
                return true;
            }else if(matrix[i][j]>target){
                j--; //mean the j column is impossible
            }else{
                //matrix[i][j]<target mean the i column is impossible
                i++;
            }
        }
        return false;
    }
};
