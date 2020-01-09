//
//  130_surrounded_regions_others_dfs_or_bfs.cpp
//  test
//
//  Created by ley on 2020/1/10.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    
    //dfs method from others
    //too deep recursive is easy to have stack overflow problem
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        if(row==0) return;
        int col=board[0].size();
        if(col==0) return;
        
        for(int i=0;i<row;i++){
            check(i,0,row,col,board);
            if(col-1>0){
                check(i, col-1, row, col, board);
            }
        }
        for(int j=0;j<col;j++){
            check(0, j, row, col, board);
            if(row-1>0){
                check(row-1, j, row, col, board);
            }
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                board[i][j]=(board[i][j]=='1')?'O':'X';
            }
        }
        
    }
    
    void check(int i,int j,int& row,int& col,vector<vector<char>>& board){
        if(board[i][j]!='O') return;
        else if(board[i][j]=='O'){
            board[i][j]='1';
            if(i>1) check(i-1, j, row, col, board);
            if(j>1) check(i, j-1, row, col, board);
            if(i<row-2) check(i+1, j, row, col, board);
            if(j<col-2) check(i, j+1, row, col, board);
        }
    }
};
