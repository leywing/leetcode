//
//  054_spiral_matrix.cpp
//  test
//
//  Created by ley on 2019/12/9.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size()==0) return ans;
        
        sp2(matrix,0,0,0,ans);
        
        return ans;
    }
    
    void sp2(vector<vector<int>>& matrix,int i,int j,int direct,vector<int>& ans){
        //direct  0:right  1:down  2:left  3:up
        if(matrix[i][j]==0x80000000) return;
        int row=matrix.size();
        int col=matrix[0].size();
        
        if(direct==0){
            ans.push_back(matrix[i][j]);
            matrix[i][j]=0x80000000;
            if(j+1<col&&matrix[i][j+1]!=0x80000000) sp2(matrix, i, j+1, 0, ans);
            else{
                //=
                if(i+1>=row) return;
                else{
                sp2(matrix, i+1, j, 1, ans);
                }
            }
        }else if(direct==1){
            ans.push_back(matrix[i][j]);
            matrix[i][j]=0x80000000;
            if(i+1<row&&matrix[i+1][j]!=0x80000000) sp2(matrix, i+1, j, 1, ans);
            else{
                //=
                if(j-1<0) return;
                else{
                sp2(matrix, i, j-1, 2, ans);
                }
            }
        }else if(direct==2){
            ans.push_back(matrix[i][j]);
            matrix[i][j]=0x80000000;
            if(j-1>=0&&matrix[i][j-1]!=0x80000000) sp2(matrix, i, j-1, 2, ans);
            else{
                //=
                if(i-1<0) return;
                else{
                sp2(matrix, i-1, j, 3, ans);
                }
            }
        }else{
            //==2
            ans.push_back(matrix[i][j]);
            matrix[i][j]=0x80000000;
            if(i-1>=0&&matrix[i-1][j]!=0x80000000) sp2(matrix, i-1, j, 3, ans);
            else{
                //=
                if(j+1>=col) return;
                else{
                sp2(matrix, i, j+1, 0, ans);
                }
            }
        }
    }
};
