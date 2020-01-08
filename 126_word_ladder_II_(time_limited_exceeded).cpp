//
//  126_word_ladder_II_(time_limited_exceeded).cpp
//  test
//
//  Created by ley on 2019/12/31.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    vector<vector<string>> ans;
    int min=INT_MAX;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.size();
        int nwl=wordList.size();
        int flag=0;
        int i=0;
        for(i=0;i<nwl;i++){
            if(wordList[i]==endWord){
                flag=1;
                break;
            }
        }
        if(flag==0) return ans;
        wordList.erase(wordList.begin()+i);
        
        if(n==1){
            vector<string> tmp;
            tmp.push_back(beginWord);
            tmp.push_back(endWord);
            ans.push_back(tmp);
            return ans;
        }
        vector<string> tmp_ans;
        fin2(beginWord, endWord, wordList, 0,tmp_ans);
        return ans;
    }
    
    void fin2(string beginWord,string endWord,vector<string>& wordList,int count,vector<string> tmp_ans){
        int n=beginWord.size();
        int nwl=wordList.size();
        if(count>min) return;
        
        for(int j=0;j<n;j++){
            if(j==0){
                if(beginWord.substr(1)==endWord.substr(1)){
                    //cout<<"no way"<<endl;
                    if(count<min){
                        min=count;
                        ans.clear();
                        tmp_ans.push_back(beginWord);
                        tmp_ans.push_back(endWord);
                        ans.push_back(tmp_ans);
                        return;
                    }else{
                        // count==min
                        tmp_ans.push_back(beginWord);
                        tmp_ans.push_back(endWord);
                        ans.push_back(tmp_ans);
                        return;
                    }
                }
            }else if(j==n-1){
                if(beginWord.substr(0,n-1)==endWord.substr(0,n-1)){
                    //cout<<"what the fuck"<<endl;
                    if(count<min){
                        min=count;
                        ans.clear();
                        tmp_ans.push_back(beginWord);
                        tmp_ans.push_back(endWord);
                        ans.push_back(tmp_ans);
                        return;
                    }else{
                        // count==min
                        tmp_ans.push_back(beginWord);
                        tmp_ans.push_back(endWord);
                        ans.push_back(tmp_ans);
                        return;
                    }
                }
            }else{
                if(beginWord.substr(0,j)==endWord.substr(0,j)&&beginWord.substr(j+1)==endWord.substr(j+1)){
                    //cout<<"oh no"<<endl;
                    if(count<min){
                        min=count;
                        ans.clear();
                        tmp_ans.push_back(beginWord);
                        tmp_ans.push_back(endWord);
                        ans.push_back(tmp_ans);
                        return;
                    }else{
                        // count==min
                        tmp_ans.push_back(beginWord);
                        tmp_ans.push_back(endWord);
                        ans.push_back(tmp_ans);
                        return ;
                    }
                }
            }
        }
        
        for(int i=0;i<nwl;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    if(beginWord.substr(1)==wordList[i].substr(1)){
                        string tmp_begin=wordList[i];
                        
                        wordList.erase(wordList.begin()+i);
                        tmp_ans.push_back(beginWord);
                        
                        fin2(tmp_begin, endWord, wordList, count+1,tmp_ans);
                        
                        wordList.insert(wordList.begin()+i, tmp_begin);
                        tmp_ans.pop_back();
                    }else{
                        continue;
                    }
                }else if(j==n-1){
                    if(beginWord.substr(0,n-1)==wordList[i].substr(0,n-1)){
                        string tmp_begin=wordList[i];
                        wordList.erase(wordList.begin()+i);
                        tmp_ans.push_back(beginWord);
                        
                        fin2(tmp_begin, endWord, wordList, count+1,tmp_ans);
                        
                        wordList.insert(wordList.begin()+i, tmp_begin);
                        tmp_ans.pop_back();
                    }else{
                        continue;
                    }
                }else{
                    if((beginWord.substr(0,j)==wordList[i].substr(0,j))&&(beginWord.substr(j+1)==wordList[i].substr(j+1))){
                        string tmp_begin=wordList[i];
                        wordList.erase(wordList.begin()+i);
                        tmp_ans.push_back(beginWord);
                        
                        fin2(tmp_begin, endWord, wordList, count+1,tmp_ans);
                        
                        wordList.insert(wordList.begin()+i, tmp_begin);
                        tmp_ans.pop_back();
                    }else{
                        continue;
                    }
                }
            }
        }
    }
};


