//
//  132_palindrome_patitioning_II.cpp
//  test
//
//  Created by ley on 2020/1/11.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int minCut(string s) {
        int ans=INT_MAX;
        int length=s.size();
        if(length==0) return 0;
        
        int path=0;
        dfs(ans,length,0,path,s);
        
        return ans;
    }
    
    void dfs(int& ans,int length,int index,int& path,string& s){
        if(path>ans){
            return;
        }
        if(index==length){
            ans=((path-1)<ans)?(path-1):ans;
            return;
        }
        
        for(int i=length-1;i>=index;i--){
            if(ispalindrome(s, index, i)){
                path++;
                dfs(ans, length, i+1, path, s);
                path--;
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
