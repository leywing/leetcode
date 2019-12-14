//
//  072_Edit_Distance_DP.cpp
//  test
//
//  Created by ley on 2019/12/14.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        if(n1==0||n2==0) return n1+n2;
        vector<int> tmp(n1+1,0);
        vector<vector<int>> aaa;
        for(int i=0;i<n2+1;i++){
            aaa.push_back(tmp);
        }
//看看人家写的，学学
//        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i=0;i<n1+1;i++){
            aaa[0][i]=i;
            //0 1 2 3 4 ..
        }
        for(int i=0;i<n2+1;i++){
            aaa[i][0]=i;
            //0
            //1
            //2
            //..
        }
        
        for(int i=1;i<n2+1;i++){
            for(int j=1;j<n1+1;j++){
                if(word1[j-1]==word2[i-1]) aaa[i][j]=aaa[i-1][j-1];
                //!!!!!!! step forword
                else{
                    aaa[i][j]=min_of_three(aaa[i][j-1],aaa[i-1][j-1],aaa[i-1][j])+1;
                }
            }
        }
        
        //空间利用率低
        //卜东波老师讲过的
        //可以用两行就好了
        //毕竟下一行的只会用到上一行的数据
        
//        for(int i=0;i<n2+1;i++){
//            for(int j=0;j<n1+1;j++){
//                cout<<aaa[i][j]<<" ";
//                if(aaa[i][j]<10) cout<<" ";
//            }
//            cout<<endl;
//        }
//
        return aaa[n2][n1];
        

    }
    
    int min_of_three(int i1,int i2,int i3){
        int min=i1<i2?i1:i2;
        min=min<i3?min:i3;
        
        return min;
    }
};


int main(){
    string a="zoologicoarchaeologist";
    string b="zoogeologist";
    Solution ley;
    cout<<ley.minDistance(a, b)<<endl;
}
