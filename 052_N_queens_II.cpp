//
//  052_N_queens_II.cpp
//  test
//
//  Created by ley on 2019/12/8.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
        int totalNQueens(int n) {
            int ans=0;
            //create empty with all '.'
            vector<string> empty;
            for(int i=0;i<n;i++){
                string s;
                for(int j=0;j<n;j++){
                    s+='.';
                }
                empty.push_back(s);
            }
            //        for(auto temp_em:empty){
            //            cout<<temp_em<<endl;
            //        }
            
            vector<int> col(n,0);
            vector<int> zuoxie(2*n,0);
            vector<int> youxie(2*n,0);
            
            search(0,col,ans,zuoxie,youxie,n,empty);
            
            return ans;
        }
    
    
    void search(int hang,vector<int>& col,int& ans,vector<int>& zuoxie,vector<int>& youxie,int n,vector<string>& empty){
        if(hang>=n){
            ans++;
            return ;
            //成功
        }
        
        for(int j=0;j<n;j++){
            if(zuoxie[hang-j+n-1]==1||youxie[hang+j]==1||col[j]==1){
                continue;
            }
            //可以放
            empty[hang][j]='Q';
            col[j]=1;
            zuoxie[hang-j+n-1]=1;
            youxie[hang+j]=1;
            search(hang+1,col,ans,zuoxie,youxie,n,empty);
            empty[hang][j]='.';
            col[j]=0;
            zuoxie[hang-j+n-1]=0;
            youxie[hang+j]=0;
            
            
        }
        
        return ;
    }
    
};
