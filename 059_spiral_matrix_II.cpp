//
//  059_spiral_matrix_II.cpp
//  test
//
//  Created by ley on 2019/12/11.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        vector<int> temp(n,0);
        for(int i=0;i<n;i++){
            ans.push_back(temp);
        }
        
        sp2(ans,0,0,0,1);
        
        return ans;
    }
    
    void sp2(vector<vector<int>>& matrix,int i,int j,int direct,int count){
        //direct  0:right  1:down  2:left  3:up
        if(matrix[i][j]!=0) return;
        int row=matrix.size();
        int col=matrix[0].size();
        
        if(direct==0){
            matrix[i][j]=count;
            count++;
            if(j+1<col&&matrix[i][j+1]==0) sp2(matrix, i, j+1, 0, count);
            else{
                //=
                if(i+1>=row) return;
                else{
                    sp2(matrix, i+1, j, 1, count);
                }
            }
        }else if(direct==1){
            matrix[i][j]=count;
            count++;
            if(i+1<row&&matrix[i+1][j]==0) sp2(matrix, i+1, j, 1, count);
            else{
                //=
                if(j-1<0) return;
                else{
                    sp2(matrix, i, j-1, 2, count);
                }
            }
        }else if(direct==2){
            matrix[i][j]=count;
            count++;
            if(j-1>=0&&matrix[i][j-1]==0) sp2(matrix, i, j-1, 2, count);
            else{
                //=
                if(i-1<0) return;
                else{
                    sp2(matrix, i-1, j, 3, count);
                }
            }
        }else{
            //==2
            matrix[i][j]=count;
            count++;
            if(i-1>=0&&matrix[i-1][j]==0) sp2(matrix, i-1, j, 3, count);
            else{
                //=
                if(j+1>=col) return;
                else{
                    sp2(matrix, i, j+1, 0, count);
                }
            }
        }
    }
};
