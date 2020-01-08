//
//  127_word_ladder.cpp
//  test
//
//  Created by ley on 2020/1/7.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans=0;
        
        unordered_set<string> words(wordList.begin(),wordList.end());
        if(!words.count(endWord)) return ans;
        
        unordered_set<string> front={beginWord};
        unordered_set<string> back={endWord};
        
        //unordered_map<string, vector<string>> children;
        
        int level=1;
        
        bool found=false;
        //bool backward=false;
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
               // backward=!backward;
            }//always deal with the smaller one ,so deal with the front
            
            for(auto tmp:front){
                for(int i=0;i<tmp.size();i++){
                    string t_01=tmp;
                    for(char cc='a';cc<='z';cc++){
                        t_01[i]=cc;
                        if(back.count(t_01)){
                            found=true;
                            return level;
                            //if(backward){
                            //    children[t_01].push_back(tmp);
                            //}else{
                            //    children[tmp].push_back(t_01);
                            //}
                        }else if(words.count(t_01)&&found==false){   //need found==0?????
                            //if(backward){
                            //    children[t_01].push_back(tmp);
                            //    next_f.insert(t_01);
                            //}else{
                            //    children[tmp].push_back(t_01);
                                  next_f.insert(t_01);
                            //}
                        }
                    }
                }
            }//for(auto tmp:front)
            
            swap(front, next_f);
        }//the while
        
        //if(found){
            //dfs to search the way
        //    vector<string> paths={beginWord};
        //    dfs(ans, beginWord, endWord, children, paths);
            
        //}
        
        return ans;
    }
};
