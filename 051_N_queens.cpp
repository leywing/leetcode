//
//  051_N_queens.cpp
//  test
//
//  Created by ley on 2019/12/8.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
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
    
    void search(int hang,vector<int>& col,vector<vector<string>>& ans,vector<int>& zuoxie,vector<int>& youxie,int n,vector<string>& empty){
        if(hang>=n){
            ans.push_back(empty);
            
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


int main(){
    cout<<"start"<<endl;
    int n=9;
    vector<int> aaa(2*n,3);
    for(int i=0;i<2*n;i++){
        cout<<i<<" "<<aaa[i]<<endl;
    }
    return 0;
}
