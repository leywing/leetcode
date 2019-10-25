//
//  037_sudoku_solver_2.cpp
//  test
//
//  Created by ley on 2019/10/23.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> char2int;
        char2int={{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9}};
        
    
        unordered_map<int, char> square[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
            square[i][j]={{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},{7,'7'},{8,'8'},{9,'9'}};
            
            }
            
        }
        int num_empty=0;
        int row[9][10]={0}; //1_9
        int col[9][10]={0}; //1-9
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    row[i][ char2int[board[i][j]] ]=1;
                    col[j][ char2int[board[i][j]] ]=1;
                    square[i/3][j/3].erase(char2int[board[i][j]]);
                }else{
                    num_empty+=1;
                }
            }
        }
        //上面的操作找出了有多少个空num_empty
        //并且确定了每个9格里还缺哪些数
        //每行哪些数已经有了
        while(num_empty>0){
            
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    //square
                    if(square[i][j].size()==0) continue;
                    else if(square[i][j].size()==1){
                        for(int k=0;k<3;k++){
                            int s01=0;
                            for(int m=0;m<3;m++){
                                if(board[3*i+k][3*j+m]=='.'){
                                    board[3*i+k][3*j+m]=square[i][j].begin()->second;
                                    square[i][j].clear();
                                    num_empty-=1;
                                    s01=1;
                                    break;
                                }
                            }
                            if(s01==1) break;
                        }
                        continue;
                        //前面的这两个分别是在9宫格为1或0时，处理，然后跳过，进下一个9宫格
                    }else{
                        //9格内的空多于1个
                        for(int k=0;k<3;k++){
                           // int s02=0;
                            for(int m=0;m<3;m++){
                                if(board[3*i+k][3*j+m]=='.'){
                                    //找到一个空
                                    //int s03=0;
                                    int possible=0;
                                    int temp;
                                    for(auto it=square[i][j].begin();it!=square[i][j].end();it++){
                                        if(row[3*i+k][(it->first)]==1) continue;
                                        if(col[3*j+m][(it->first)]==1) continue;
                                        
                                        possible+=1;
                                        temp=it->first;
                                        //这里要判断另外2行2列是不是不可以是这个数
                                        int test=1;
                                        for(int q=0;q<3;q++){
                                                if(q!=k){
                                                    test=test*row[3*i+q][(it->first)];
                                                }
                                        }
                                        for(int w=0;w<3;w++){
                                            if(w!=m){
                                                test=test*col[3*j+w][(it->first)];
                                            }
                                        }
                                        if(test==1){
                                            //success
                                            board[3*i+k][3*j+m]=it->second;
                                            num_empty-=1;
                                            square[i][j].erase(it->first);
                                            //s03=1;
                                            //s02=1;
                                            possible=-1;
                                            break;
                                            //这里break,是我怕it被删了，会出现问题
                                        }
                                        
                                    }
                                    if(possible==1){
                                        board[3*i+k][3*j+m]=square[i][j][temp];
                                        num_empty-=1;
                                        square[i][j].erase(temp);
                                    }
                                    
                                }
                            }
                        }
                    }
                    
                    
                    
                }
            }
            
            
        }
        
       
        
    }
};
