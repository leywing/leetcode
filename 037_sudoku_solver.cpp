//
//  037_sudoku_solver.cpp
//  test
//
//  Created by ley on 2019/10/23.
//  Copyright © 2019 ley. All rights reserved.
//

#include "leetcode.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> biao[9][9];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                biao[i][j]={{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9}};
            }
        }
        
        int num=0;
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    //delete
                    
                    //row
                    for(int k=0;k<9;k++){
                        biao[i][k].erase(board[i][j]);
                    }
                    //column
                    for(int f=0;f<9;f++){
                        biao[f][j].erase(board[i][j]);
                    }
                    //square
                    int temp_i=i/3;
                    int temp_j=j/3;
                    for(int k=0;k<3;k++){
                        for(int f=0;f<3;f++){
                            biao[temp_i*3+k][temp_j*3+f].erase(board[i][j]);
                        }
                    }
                    
                    
                }else{
                    num+=1;
                }
            }
        }
        //上面是遍历了第一遍，把该删的删了，并统计出剩下的。空num
        
        int row=0,col=0;
        int signal=0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'&&biao[i][j].size()==1){
                    row=i;
                    col=j;
                    signal=1;
                    break;
                }
            }
            if(signal==1){break;}
        }
        
        if(signal==0) std::cout<<"not valid"<<endl;
        
   
        while(num>0){
            int temp_row=row;
            int temp_col=col;
            
            board[row][col]=biao[row][col].begin()->first;
            num-=1;
            if(num==0){
                break;
            }
            
            for(int k=0;k<9;k++){
                biao[row][k].erase(board[row][col]);
                if(board[row][k]=='.'&&biao[row][k].size()==1){
                    temp_row=row;
                    temp_col=k;
                }
            }
            //column
            for(int f=0;f<9;f++){
                biao[f][col].erase(board[row][col]);
                if(board[f][col]=='.'&&biao[f][col].size()==1){
                    temp_row=f;
                    temp_col=col;
                }
            }
            //square
            int temp_i=row/3;
            int temp_j=col/3;
            for(int k=0;k<3;k++){
                for(int f=0;f<3;f++){
                    biao[temp_i*3+k][temp_j*3+f].erase(board[row][col]);
                    if(board[temp_i*3+k][temp_j*3+f]=='.'&&biao[temp_i*3+k][temp_j*3+f].size()==1){
                        temp_row=temp_i*3+k;
                        temp_col=temp_j*3+f;
                    }
                }
            }
            
            if(!(temp_row==row&&temp_col==col)){
                row=temp_row;
                col=temp_col;
            }else{
                int sig2=0;
                for(int i=0;i<9;i++){
                    for(int j=0;j<9;j++){
                        if(board[i][j]=='.'&&biao[i][j].size()==1){
                            row=i;
                            col=j;
                            sig2=1;
                            break;
                        }
                    }
                    if(sig2==1){break;}
                }
                
                if(sig2==0){
                    
                }else{
                    std::cout<<"unvalid"<<endl;
                    break;
                }
            }
            
        }
        
        
    }
};

[[".",".","9","7","4","8",".",".","."],
 ["7",".",".","6",".","2",".",".","."],
 [".","2",".","1",".","9",".",".","."],
 [".",".","7","9","8","6","2","4","1"],
 ["2","6","4","3","1","7","5","9","8"],
 ["1","9","8","5","2","4","3","6","7"],
 [".",".",".","8","6","3",".","2","."],
 [".",".",".","4","9","1",".",".","6"],
 [".",".",".","2","7","5","9",".","."]]


[["5","1","9","7","4","8","6","3","2"],
 ["7","8","3","6","5","2","4","1","9"],
 ["4","2","6","1","3","9","8","7","5"],
 ["3","5","7","9","8","6","2","4","1"],
 ["2","6","4","3","1","7","5","9","8"],
 ["1","9","8","5","2","4","3","6","7"],
 ["9","7","5","8","6","3","1","2","4"],
 ["8","3","2","4","9","1","7","5","6"],
 ["6","4","1","2","7","5","9","8","3"]]
