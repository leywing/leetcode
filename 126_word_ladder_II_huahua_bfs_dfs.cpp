//
//  126_word_ladder_II_huahua_bfs_dfs.cpp
//  test
//
//  Created by ley on 2020/1/7.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
    
        unordered_set<string> words(wordList.begin(),wordList.end());
        if(!words.count(endWord)) return ans;
        
        unordered_set<string> front={beginWord};
        unordered_set<string> back={endWord};
        
        unordered_map<string, vector<string>> children;
        
        int level=1;
        
        bool found=false;
        bool backward=false;
        while (front.size()!=0&&back.size()!=0&&found==false) {
            level++;
            
            for(auto tmp:front){
                words.erase(tmp);
            }
            for(auto tmp:back){
                words.erase(tmp);
            }
            
            unordered_set<string> next_f;
            
            if(front.size()>back.size()){
                swap(front,back);
                backward=!backward;
            }//always deal with the smaller one ,so deal with the front
            
            for(auto tmp:front){
                for(int i=0;i<tmp.size();i++){
                    string t_01=tmp;
                    for(char cc='a';cc<='z';cc++){
                        t_01[i]=cc;
                        if(back.count(t_01)){
                            found=true;
                            if(backward){
                                children[t_01].push_back(tmp);
                            }else{
                                children[tmp].push_back(t_01);
                            }
                        }else if(words.count(t_01)&&found==false){   //need found==0?????
                            if(backward){
                                children[t_01].push_back(tmp);
                                next_f.insert(t_01);
                            }else{
                                children[tmp].push_back(t_01);
                                next_f.insert(t_01);
                            }
                        }
                    }
                }
            }//for(auto tmp:front)
            
            swap(front, next_f);
        }//the while
        
        if(found){
           //dfs to search the way
            vector<string> paths={beginWord};
            dfs(ans, beginWord, endWord, children, paths);
           
        }
        
        return ans;
    }
    
    void dfs(vector<vector<string>>& ans,
             string& beginWord,
             string& endWord,
             unordered_map<string,vector<string>>& children,
             vector<string> paths
             ){
        
        if(paths.back()==endWord){
            ans.push_back(paths);
            return;
        }
        
        string tmp_fa=paths.back();
        if(children.find(tmp_fa)==children.end()) return;
        
        for(int i=0;i<children[tmp_fa].size();i++){
            paths.push_back(children[tmp_fa][i]);
            dfs(ans, beginWord, endWord, children, paths);
            paths.pop_back();
        }
        
        
    }
    
    
};
