//
//  131_palindrome_partitioning.cpp
//  test
//
//  Created by ley on 2020/1/10.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    //others' method
    //so brilliant
    // loop the string, check start---i  is palindrome?  yes push ,and recursively dfs(the least)
    
    //how can they be so smart to think up this?
    
    //这样想吧，一个s[i]的命运有哪些
    //特殊点，就s[0]吧，它可能自己被插入，也有可能和后面组成回文 被插入。
    //s[i]  4个可能，自己插入，和前面组成回文。 和后面的组成回文。  和前面后面一起组成回文
    //这样想就好复杂。  而这个方法就好简单，递归得。
    
    //还是觉得好聪明，通过一个for循环，就把所有的可能的palindrome都找出来了
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int length=s.size();
        if(length==0) return ans;
        
        vector<string> path;
        dfs(ans,length,0,path,s);
        
        return ans;
    }
    
    void dfs(vector<vector<string>>& ans,int length,int index,vector<string>& path,string& s){
        if(index==length){
            ans.push_back(path);
            return;
        }
        
        for(int i=index;i<length;i++){
            if(ispalindrome(s, index, i)){
                path.push_back(s.substr(index,i-index+1));
                dfs(ans, length, i+1, path, s);
                path.pop_back();
            }
        }
        
        
    }
    
    bool ispalindrome(string& s,int start,int end){
        bool flag=true;
        while(start<=end){
            if(s[start]!=s[end]){
                flag=false;
                break;
            }
            start++;
            end--;
        }
        
        return flag;
    }
};
