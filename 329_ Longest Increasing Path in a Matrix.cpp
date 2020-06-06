//
//  329_ Longest Increasing Path in a Matrix.cpp
//  test
//
//  Created by ley on 2020/6/6.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"



class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if(row==0) return 0;
        int col=matrix[0].size();
        if(col==0) return 0;
        
        int ans=1;
        vector<vector<int>> count(row,vector<int>(col,0));  //means from this point start ,longest len
        //int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int maxtmp=lo3(matrix,count,i,j,row,col);
                ans=max(ans,maxtmp);
            }
        }
        return ans;
    }
private:
    int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    int lo3(vector<vector<int>>& matrix, vector<vector<int>>& count,int i,int j,const int& row,const int& col){
        if(count[i][j]!=0) return count[i][j];
        int tmp_max=1;
        for(auto a:dir){
            int x=a[0]+i;
            int y=a[1]+j;
            if(x<0 || x>=row || y<0 || y>=col || matrix[x][y]<=matrix[i][j]) continue;
            int len=1+lo3(matrix, count, x, y, row, col);
            tmp_max=max(tmp_max,len);
        }
        count[i][j]=tmp_max;
        return tmp_max;
    }
};


//知道为什么太慢了。。
//别人的dp记得是，以当前数为起点，最长的长度
//所以新的数，比周围小，就加1.  这样每次出现新的数，都只要更新一次即可。
//要想清楚下，到底是咋样的
//她们这种方法，那就是。出现比周围小的数，更新一次。   出现比周围大的数 不动。。。。。。。卧槽。真这么简单？  s所以每个cell就更新一次！！1厉害
//我的每次出现更小的数，要更新 整个相关链。出现大数，不动。



// bymyself ,but too slow......
//why???????我以为。。我已经d够简便的
//class Solution {
//public:
//    int longestIncreasingPath(vector<vector<int>>& matrix) {
//        int row=matrix.size();
//        if(row==0) return 0;
//        int col=matrix[0].size();
//        if(col==0) return 0;
//        vector<vector<int>> count(row,vector<int>(col,1));
//        int ans=1;
//        for(int i=0;i<row;i++){
//            for(int j=0;j<col;j++){
//                if(count[i][j]>1) continue;
//                //count[i][j]==1
//                if(i-1>=0 && matrix[i-1][j]>matrix[i][j] && count[i-1][j]<2){
//                    count[i-1][j]=2;
//                    //ans=max(ans,count[i-1][j]);
//                    lo2(matrix,count,i-1,j,row,col);
//                }
//                if(i+1<row && matrix[i+1][j]>matrix[i][j] && count[i+1][j]<2){
//                    count[i+1][j]=2;
//                    //ans=max(ans,count[i+1][j]);
//                    lo2(matrix,count,i+1,j,row,col);
//                }
//                if(j-1>=0 && matrix[i][j-1]>matrix[i][j] && count[i][j-1]<2){
//                    count[i][j-1]=2;
//                    //ans=max(ans,count[i][j-1]);
//                    lo2(matrix,count,i,j-1,row,col);
//                }
//                if(j+1<col && matrix[i][j+1]>matrix[i][j] && count[i][j+1]<2){
//                    count[i][j+1]=2;
//                    //ans=max(ans,count[i][j+1]);
//                    lo2(matrix,count,i,j+1,row,col);
//                }
//            }
//        }
//
//        for(int i=0;i<row;i++){
//            for(int j=0;j<col;j++){
//                ans=max(ans,count[i][j]);
//            }
//        }
//
//
//        return ans;
//
//    }
//private:
//    void lo2(vector<vector<int>>& matrix,vector<vector<int>>& count,int i,int j,const int& row,const int& col){
//        //int row=matrix.size();
//        //int col=matrix[0].size();
//        if(i-1>=0 && matrix[i-1][j]>matrix[i][j] && count[i-1][j]<count[i][j]+1){
//            count[i-1][j]=count[i][j]+1;
//            //ans=max(ans,count[i-1][j]);
//            lo2(matrix,count,i-1,j,row,col);
//        }
//        if(i+1<row && matrix[i+1][j]>matrix[i][j] && count[i+1][j]<count[i][j]+1){
//            count[i+1][j]=count[i][j]+1;
//            //ans=max(ans,count[i+1][j]);
//            lo2(matrix,count,i+1,j,row,col);
//        }
//        if(j-1>=0 && matrix[i][j-1]>matrix[i][j] && count[i][j-1]<count[i][j]+1){
//            count[i][j-1]=count[i][j]+1;
//            //ans=max(ans,count[i][j-1]);
//            lo2(matrix,count,i,j-1,row,col);
//        }
//        if(j+1<col && matrix[i][j+1]>matrix[i][j] && count[i][j+1]<count[i][j]+1){
//            count[i][j+1]=count[i][j]+1;
//            //ans=max(ans,count[i][j+1]);
//            lo2(matrix,count,i,j+1,row,col);
//        }
//    }
//};
