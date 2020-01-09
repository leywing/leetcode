//
//  130_surrounded_regions.cpp
//  test
//
//  Created by ley on 2020/1/9.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int row;
    int col;
    struct pair_hash{
        inline size_t operator()(const pair<int,int> &p) const{
            long tmp=p.first;
            tmp=tmp<<32;
            tmp=tmp+p.second;
            return tmp;
        }
    };
    
    void solve(vector<vector<char>>& board) {
        row=board.size();
        if(row==0) return;
        col=board[0].size();
        if(col==0) return;
        
        unordered_set<pair<int, int>,pair_hash> set;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O') set.insert(pair<int,int>(i,j));
            }
        }
        
        vector<vector<pair<int, int>>> change_set;
        while(set.size()!=0){
            pair<int,int> tmp=*set.begin();
            vector<pair<int, int>> visit;
            if(sol2(tmp,visit,set)==0){
                change_set.push_back(visit);
                //cout<<"haha"<<endl;
            }
        }
        
        for(auto a:change_set){
            for(int i=0;i<a.size();i++){
                board[a[i].first][a[i].second]='X';
            }
        }
        
    }
    
    int sol2(pair<int, int> tmp,vector<pair<int, int>>& visit,unordered_set<pair<int, int>,pair_hash>& set){
        visit.push_back(tmp);
        //cout<<tmp.first<<" "<<tmp.second<<endl;
        set.erase(tmp);
        int bound_flag=0;
        int flag=0;
        
        if(tmp.first-1<0){
            bound_flag=1;
        }else{
            if(set.count(pair<int,int>(tmp.first-1,tmp.second))){
                flag+=sol2(pair<int, int>(tmp.first-1,tmp.second), visit, set);
            }
        }
        
        if(tmp.first+1>row-1){
            bound_flag=1;
        }else{
            if(set.count(pair<int,int>(tmp.first+1,tmp.second))){
                flag+=sol2(pair<int, int>(tmp.first+1,tmp.second), visit, set);
            }
        }
        
        if(tmp.second-1<0){
            bound_flag=1;
        }else{
            if(set.count(pair<int,int>(tmp.first,tmp.second-1))){
                flag+=sol2(pair<int, int>(tmp.first,tmp.second-1), visit, set);
            }
        }
        
        if(tmp.second+1>col-1){
            bound_flag=1;
        }else{
            if(set.count(pair<int,int>(tmp.first,tmp.second+1))){
                flag+=sol2(pair<int, int>(tmp.first,tmp.second+1), visit, set);
            }
        }
        
        if(bound_flag==1){
            return 1;
        }else if(flag>=1){
            return 1;
        }else{
            return 0;
        }
        
    }
};
