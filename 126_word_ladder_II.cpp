//
//  126_word_ladder_II.cpp
//  test
//
//  Created by ley on 2020/1/3.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        
        queue<vector<string>> que;
        
        int level=1;
        int minlevel=INT_MAX;
        
        unordered_set<string> words;
        int flag01=0;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==beginWord){
                continue;
            }else if(wordList[i]==endWord){
                flag01=1;
                words.insert(wordList[i]);
            }else{
                words.insert(wordList[i]);
            }
        }
        
        if(flag01==0) return ans;
        
        if(beginWord.size()==1){
            vector<string> tmp02;
            tmp02.push_back(beginWord);
            tmp02.push_back(endWord);
            ans.push_back(tmp02);
            return ans;
        }
        unordered_set<string> visited;
        int n=beginWord.size();
        
        que.push({beginWord});
        while(!que.empty()){
            vector<string> tmp_path=que.front();
            que.pop();
            //reach a new level
            if(tmp_path.size()>level){
                for(auto w:visited){
                    words.erase(w);
                }
                visited.clear();
                if(tmp_path.size()>minlevel){
                    break;
                }else{
                    level=tmp_path.size();
                }
            }
            
            
            string tmp_string=tmp_path.back();
            for(int i=0;i<n;i++){
                string tmp01=tmp_string;
                for(char cc='a';cc<='z';cc++){
                    tmp01[i]=cc;
                    if(words.find(tmp01)!=words.end()){
                        vector<string> tmp02_path=tmp_path;
                        tmp02_path.push_back(tmp01);
                        visited.insert(tmp01);
                        if(tmp01==endWord){
                            minlevel=level;
                            ans.push_back(tmp02_path);
                            break;
                        }else{
                            que.push(tmp02_path);
                        }
                    }
                }
            }
     
            
        }
        
        return ans;
        
    }
};


