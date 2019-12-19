//
//  085_maximal_rectangle.cpp
//  test
//
//  Created by ley on 2019/12/19.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    
    //others' method
    //from discussion
    
    //smart!!!!!
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        if(row==0) return 0;
        int col=matrix[0].size();
        if(col==0) return 0;
        
        vector<vector<int>> a(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='1'){
                    a[i][j]=1;
                }
            }
        }
        
        for(int j=0;j<col;j++){
            for(int i=0;i<row;i++){
                if(i-1>=0&&a[i-1][j]>0&&a[i][j]>0) a[i][j]+=a[i-1][j];
            }
        }
        
        int ans=0;
        for(int i=0;i<row;i++){
            if(largestRectangleArea(a[i])>ans) ans=largestRectangleArea(a[i]);
        }
        
        return ans;
        
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0) return 0;
        if(n==1) return heights[0];
        
        heights.push_back(0);
        n++;
        stack<int> s;
        int ans=0;
        
        int i=0,j=0,h=0;
        while(i<n){
            if(s.empty()||heights[i]>=heights[s.top()]){
                s.push(i);
                i++;
            }
            else{
                h=heights[s.top()];
                s.pop();
                
                j=s.empty()?-1:s.top();
                ans=h*(i-j-1)>ans?h*(i-j-1):ans;
            }
        }
        
        return ans;
        
    }
    
};
