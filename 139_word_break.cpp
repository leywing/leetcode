//
//  139_word_break.cpp
//  test
//
//  Created by ley on 2020/2/1.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
//others DP
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        int max_l=0;
        //!!!!!!!!!!!!!!!!!!
        //好的，来解释下，为什么max_l初始化为负数时，size()>max_l  判断为0
        //因为size()函数的类型是。unsigned long 无符号数，  所以跟负数比时，   判断为0
        //！！！！！！以后一定要注意了
        
        for(auto it:wordDict){
            set.insert(it);
            max_l=it.size()>max_l?it.size():max_l;
        }
        
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        
        for(int i=1;i<=n;i++){
            //dp[i] means    s[i-1] can be wordbreak
            
            //dp[i]= find(s[i-1]) ||  ( dp[j]&&find(s.substr[j,i-j]) )
//            if(i<=max_l){
//                if(set.find(s.substr(0,i))!=set.end()){
//                    dp[i]=true;
//                    continue;
//                }
//            }
            //&&i-j<=max
            for(int j=i-1;j>=0&&(i-j<=max_l);j--){
                if(dp[j]){
                    if(set.find(s.substr(j,i-j))!=set.end()){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
};





//!!!!!time limit exceed      must use DP
//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        unordered_map<string, int> map;
//        int n=wordDict.size();
//        int minsize=INT_MAX;
//        int maxsize=INT_MIN;
//        for(int i=0;i<n;i++){
//            map[wordDict[i]]++;
//            minsize=wordDict[i].size()<minsize?wordDict[i].size():minsize;
//            maxsize=wordDict[i].size()>maxsize?wordDict[i].size():maxsize;
//        }
//
//        return word2(s,map,minsize,maxsize);
//    }
//
//    bool word2(string s,unordered_map<string, int>& map,int& minsize,int& maxsize){
//        int s_size=s.size();
//
//        if(s.size()<=maxsize){
//            if(map.find(s)!=map.end()){
//                return true;
//            }
//        }
//
//        for(int i=minsize;i<=s_size-minsize;i++){
//            if(word2(s.substr(0,i), map, minsize,maxsize)&&word2(s.substr(i), map, minsize,maxsize)){
//                return true;
//            }
//        }
//
//        return false;
//    }
//};
