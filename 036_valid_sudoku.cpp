//
//  036_valid_sudoku.cpp
//  test
//
//  Created by ley on 2019/10/22.
//  Copyright © 2019 ley. All rights reserved.
//

#include "leetcode.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_map<char, int> nums;
        for(int i=0;i<9;i++){
            //row
            //unordered_map<char, int> nums;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    nums[board[i][j]]+=1;
                    if(nums[board[i][j]]>=2){
                        return 0;
                    }
                }
            }
            nums.clear();
        }
        
        
            //column
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    nums[board[j][i]]+=1;
                    if(nums[board[j][i]]>=2){
                        return 0;
                    }
                }
            }
            nums.clear();
        }
        
        for(int i=0;i<7;i+=3){
            for(int j=0;j<7;j+=3){
                //这里
              for(int y=0;y<3;y++){
                for(int e=0;e<3;e++){
                    if(board[i+y][j+e]!='.'){
                        nums[board[i+y][j+e]]+=1;
                        if(nums[board[i+y][j+e]]>=2){
                            return 0;
                        }
                    }
                }
              }
                nums.clear();
            
            }
        }
        
        return 1;
    }
};
