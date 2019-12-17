//
//  079_word_search.cpp
//  test
//
//  Created by ley on 2019/12/17.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> start;
        if(word.size()==0) return true;
        int row=board.size();
        if(row==0) return false;
        int col=board[0].size();
        if(col==0) return false;
        
        //next to find all the start point
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    start.push_back(tmp);
                }
            }
        }
        
        //next from start point to search
        if(start.size()==0) return false;
        for(int i=0;i<start.size();i++){
            if(search(board, word, 1, start[i][0], start[i][1], row, col)) return true;
        }
        return false;
        
    }
    
    bool search(vector<vector<char>>& board,string& word,int k,int i,int j,int row,int col){
        if(k==word.size()) return true;
        //left
        if(j-1>=0&&board[i][j-1]==word[k]){
            board[i][j]='.';
            if(search(board, word, k+1, i, j-1,row,col)) return true;
            board[i][j]=word[k-1];
        }
        //right
        if(j+1<col&&board[i][j+1]==word[k]){
            board[i][j]='.';
            if(search(board, word, k+1, i, j+1, row, col)) return true;
            board[i][j]=word[k-1];
        }
        //up
        if(i-1>=0&&board[i-1][j]==word[k]){
            board[i][j]='.';
            if(search(board, word, k+1, i-1, j,row,col)) return true;
            board[i][j]=word[k-1];
        }
        //down
        if(i+1<row&&board[i+1][j]==word[k]){
            board[i][j]='.';
            if(search(board, word, k+1, i+1, j,row,col)) return true;
            board[i][j]=word[k-1];
        }
        
        return false;
    }
};
