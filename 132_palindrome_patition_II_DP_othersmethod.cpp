//
//  132_palindrome_patition_II_DP_othersmethod.cpp
//  test
//
//  Created by ley on 2020/1/21.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<int> cut(n,0);
        vector<vector<bool>> table(n,vector<bool> (n,false));
        
        for(int i=0;i<n;i++){
            cut[i]=i;
            for(int j=0;j<=i;j++){
                if(s[j]==s[i]&&(j+1>i-1||table[j+1][i-1]) ){
                    table[j][i]=true;
                    cut[i]=(j==0)?0:min_ley(cut[j-1]+1, cut[i]);
                }
            }
        }
        
        return cut[n-1];
    }
    
    int min_ley(int a,int b){
        return a<b?a:b;
    }
};
