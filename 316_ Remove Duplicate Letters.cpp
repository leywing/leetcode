//
//  316_ Remove Duplicate Letters.cpp
//  test
//
//  Created by ley on 2020/5/31.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"


//others solution from discussion/.....super fast
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26]={0};
        bool visited[26]={false};
        
        int len=s.size();
        for(int i=0;i<len;i++){
            count[s[i]-'a']++;
        }
        string ans="";
        for(int i=0;i<len;i++){
            count[s[i]-'a']--;
            if(visited[s[i]-'a']) continue;
            //not visited
            while(!ans.empty() && s[i]<ans.back() && count[ans.back()-'a']>0){
                visited[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans=ans+s[i];
            visited[s[i]-'a']=true;
        }
        
        return ans;
    }
};



////others' solution from discussion
//too slow....C++ do not hace replaceALL,    so the sub_s spend too much time
//class Solution {
//public:
//    string removeDuplicateLetters(string s) {
//        int count[26]={0};
//        int len=s.size();
//        for(int i=0;i<len;i++){
//            count[s[i]-'a']++;
//        }
//
//        int pos=0;
//        for(int i=0;i<len;i++){
//            if(s[i]<s[pos]) pos=i;
//            count[s[i]-'a']--;
//            if(count[s[i]-'a']==0) break;
//        }
//
//        string sub_s="";
//        for(int i=pos+1;i<len;i++){
//            if(s[i]!=s[pos]){
//                sub_s=sub_s+s[i];
//            }
//        }
//
//        return  len==0?"":s[pos]+removeDuplicateLetters(sub_s);
//    }
//};
