//
//  140_word_break_II.cpp
//  test
//
//  Created by ley on 2020/2/1.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(auto i:wordDict){
            set.insert(i);
        }
    }
    
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_map<string, int> map;
            int n=wordDict.size();
            int minsize=INT_MAX;
            int maxsize=INT_MIN;
            for(int i=0;i<n;i++){
                map[wordDict[i]]++;
                minsize=wordDict[i].size()<minsize?wordDict[i].size():minsize;
                maxsize=wordDict[i].size()>maxsize?wordDict[i].size():maxsize;
            }
    
            return word2(s,map,minsize,maxsize);
        }
    
        bool word2(string s,unordered_map<string, int>& map,int& minsize,int& maxsize){
            int s_size=s.size();
    
            if(s.size()<=maxsize){
                if(map.find(s)!=map.end()){
                    return true;
                }
            }
    
            for(int i=minsize;i<=s_size-minsize;i++){
                if(word2(s.substr(0,i), map, minsize,maxsize)&&word2(s.substr(i), map, minsize,maxsize)){
                    return true;
                }
            }
    
            return false;
        }
};
