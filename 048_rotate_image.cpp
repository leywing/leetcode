//
//  048_rotate_image.cpp
//  test
//
//  Created by ley on 2019/12/7.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    //题目说不让再分一个空间，要in placey，有点难。。。想不到。。。但是下面这个自己写的竟然让过了。。。。还是去看看别人怎么写的
//    void rotate(vector<vector<int>>& matrix) {
//        int n=matrix.size();
//        auto tem_matrix=matrix;
//
//        for(int col=0;col<n;col++){
//            vector<int> temp;
//            for(int row=n-1;row>=0;row--){
//                temp.push_back(tem_matrix[row][col]);
//            }
//            matrix[col]=temp;
//        }
//
//    }
    
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n=matrix.size();
            
            //顺时针90度，实际上就是。(i,j)->(j,N-1-i)
            //so this guy's method is to
            //swap   (i,j)->(j,i)  reverse   (j,i)->(j,N-1-i)
            
            //oh!!!super smart
            
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    //notice j<i,swap only half of the matrix to do this job
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
            
            for(int i=0;i<n;i++){
                reverse(matrix[i].begin(), matrix[i].end());
            }
        }
 
};
