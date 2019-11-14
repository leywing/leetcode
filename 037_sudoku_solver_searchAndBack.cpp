//
//  037_sudoku_solver_searchAndBack.cpp
//  test
//
//  Created by ley on 2019/11/13.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        int sign=0;
        
        unordered_map<char, int> char2int;
        char2int={{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9}};
        
        int row[9][10];
        int col[9][10];
        
        unordered_map<int, char> square[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                square[i][j]={{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},{7,'7'},{8,'8'},{9,'9'}};
                
            }
            
        }
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    row[9][char2int[board[i][j]]]=1;
                    col[9][char2int[board[i][j]]]=1;
                    square[i/3][j/3].erase(char2int[board[i][j]]);
                }
            }
        }
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(square[i][j].size()==0) continue;
                else{
                    for(int k=0;k<3;k++){
                        for(int m=0;m<3;m++){
                            if(board[3*i+k][3*j+m]=='.'){
                                for(auto it=square[i][j].begin();it!=square[i][j].end();it++){
                                    int temp=it->first;
                                    int a=search(3*i+k,3*j+m,temp,board,&row,&col,&square);
                                    if(a==1) {
                                        sign=1;
                                        break;
                                        //break all!!!!!!!!!
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        
    }
    int search(int a,int b,int c,vector<vector<char>>& board,int(*row)[9][10],int (*col)[9][10],unordered_map<int, char> (*square)[3][3]){
        
        int square_i=a/3;
        int square_j=b/3;
        
        board[a][b]=(*square)[a][b][c];
        for(int i=square_i;i<3;i++){
            for(int j=square_j;j<3;j++){
                if((*square)[i][j].size()==0) continue;
                else{
                    
                }
            }
        }
        
    }
    void back(){
        
    }
};
