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
        unsigned long maxsize=0;
        unsigned long minsize=INT_MAX;
        for(auto i:wordDict){
            set.insert(i);
            maxsize=i.size()>maxsize?i.size():maxsize;
            minsize=i.size()<minsize?i.size():minsize;
        }
        
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0&&(i-j<=maxsize);j--){
                if(dp[j]){
                    if(set.find(s.substr(j,i-j))!=set.end()){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        vector<string> ans;
        if(dp[n]==false){
            return ans;
        }
        
        string tmp;
        word2(s, set, minsize, maxsize, ans,  tmp);
        
        return ans;
    }
    
    
    void word2(string s,unordered_set<string>& set,unsigned long& minsize,unsigned long& maxsize,vector<string>& ans,string tmp){
        
        if(s.size()==0||s.size()<minsize){
            return;
        }
        
        for(int i=minsize;i<=maxsize&&i<=s.size();i++){
            if(set.find(s.substr(0,i))!=set.end()){
                string tmp_s;
                if(tmp.size()==0){
                    tmp_s=s.substr(0,i);
                }else{
                    tmp_s=tmp+' '+s.substr(0,i);
                }
                if(i==s.size()){
                    ans.push_back(tmp_s);
                    return;
                }
                word2(s.substr(i), set, minsize, maxsize, ans, tmp_s);
            }
        }
        
       
    }
};
