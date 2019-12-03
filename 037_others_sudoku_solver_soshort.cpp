//
//  037_others_sudoku_solver_soshort.cpp
//  test
//
//  Created by ley on 2019/12/2.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        tryandback(board,0,0);
    }
    
    bool check(vector<vector<char>>& board,int i,int j,char val){
        int row=i-i%3;
        int col=j-j%3;
        
        for(int k=0;k<9;k++) if(board[k][j]==val) return false;
        for(int m=0;m<9;m++) if(board[i][m]==val) return false;
        for(int a=0;a<3;a++){
            for(int b=0;b<3;b++){
                if(board[a+row][b+col]==val) return false;
            }
        }
        
        return true;
    }
    
    bool tryandback(vector<vector<char>>& board,int i,int j){
        if(i==9) return true;
        if(j==9) return tryandback(board, i+1, 0);
        if(board[i][j]!='.') return tryandback(board, i, j+1);
        else{
            for(char c='1';c<='9';c++){
                
                if(check(board, i, j, c)){
                    board[i][j]=c;
                    if(tryandback(board, i, j+1)) return true;
                    board[i][j]='.';
                }else continue;
            }
            return false;
        }
    }
};
