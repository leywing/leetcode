//
//  301_ Remove Invalid Parentheses.cpp
//  test
//
//  Created by ley on 2020/5/25.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//看了discussion......原来是 暴力BFS
//哎呀。。。。DFS/BFS,想不到好方法的时候就用啊！！！同学

//想不出来。。。。。。
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // 肯定是递归啊
        vector<string> ans;
        int left_remove=0;
        int right_remove=0;
        int len=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                left_remove++;
            }else if(s[i]==')'){
                if(left_remove>0){
                    left_remove--;
                }else{
                    right_remove++;
                }
            }
        }
        
        rem2(ans,0,left_remove,right_remove,0,"",s);
        return ans;
        
    }
    
private:
    void rem2(vector<string>& ans,int start,int left_remove,int right_remove,int pair,string path,const string& s){
        int len=s.size();
        if(start==len){
            if(left_remove==0 && right_remove==0 && pair==0){
                ans.push_back(path);
                return;
            }
            return;
        }
        
        if(left_remove<0 || right_remove<0 || pair<0 ){
            return ;
        }
        
        char c=s[start];
        if(c=='('){
            if(start==0 || s[start-1]!=c){
                for(int i=0;start+i<len && s[start+i]==c && i+1<=left_remove;i++){
                    rem2(ans, start+i+1, left_remove-i-1, right_remove, pair, path, s);
                    //i=0    rem2(ans,start+1,left_remove-1,right_remove,pair,path,s);
                }
            }
            rem2(ans, start+1, left_remove, right_remove, pair+1, path+c, s);
        }else if(c==')'){
            if(start==0 || s[start-1]!=c){
                for(int i=0;start+i<len && s[start+i]==c && i+1<=right_remove;i++){
                    rem2(ans, start+i+1, left_remove, right_remove-1-i, pair, path, s);
                    //i=0    rem2(ans,start+1,left_remove,right_remove-1,pair,path,s);
                }
            }
            rem2(ans, start+1, left_remove, right_remove, pair-1, path+c, s);
        }else{
            rem2(ans, start+1, left_remove, right_remove, pair, path+c, s);
        }
        
    }
    
    
    
};
