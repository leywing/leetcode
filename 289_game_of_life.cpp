//
//  289_game_of_life.cpp
//  test
//
//  Created by ley on 2020/5/21.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//others
//see it from discussion
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        row=board.size();
        if(row==0){
            return;
        }
        col=board[0].size();
        
    
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int tmp=count(i-1, j-1,board)+count(i-1, j,board)+count(i-1, j+1,board)
                +count(i,j-1,board)+count(i, j+1,board)
                +count(i+1,j-1,board)+count(i+1, j,board)+count(i+1, j+1,board);
                if(board[i][j]==0){
                    if(tmp==3){
                        board[i][j]+=2;
                    }
                }else{
                    //board[i][j]==1
                    if(tmp==2||tmp==3){
                        board[i][j]+=2;
                    }
                }
            }
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                board[i][j]=board[i][j]>>1;
            }
        }
        
    }
    
    int count(const int& i,const int& j,vector<vector<int>>& tt){
        if(i<0||i>=row||j<0||j>=col){
            return 0;
        }else if((tt[i][j]&1)==1){
            return 1;
        }else{
            return 0;
        }
    }
private:
    int row;
    int col;
};



//enough simple
//enough fast
//but the space can be more small
//class Solution {
//public:
//    void gameOfLife(vector<vector<int>>& board) {
//        row=board.size();
//        if(row==0){
//            return;
//        }
//        col=board[0].size();
//
//        tt=board;
//        vector<vector<int>> ans;
//        for(int i=0;i<row;i++){
//            for(int j=0;j<col;j++){
//                int tmp=count(i-1, j-1)+count(i-1, j)+count(i-1, j+1)
//                    +count(i,j-1)+count(i, j+1)
//                +count(i+1,j-1)+count(i+1, j)+count(i+1, j+1);
//                if(board[i][j]==0){
//                    if(tmp==3){
//                        board[i][j]=1;
//                    }
//                }else{
//                    //board[i][j]==1
//                    if(!(tmp==2||tmp==3)){
//                        board[i][j]=0;
//                    }
//                }
//            }
//        }
//
//    }
//
//    int count(int i,int j){
//        if(i<0||i>=row||j<0||j>=col){
//            return 0;
//        }else if(tt[i][j]==1){
//            return 1;
//        }else{
//            return 0;
//        }
//    }
//
//private:
//    vector<vector<int>> tt;
//    int row;
//    int col;
//
//};
