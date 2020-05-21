//
//  290_word_pattern.cpp
//  test
//
//  Created by ley on 2020/5/21.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> umap;
        int len=pattern.size();
        int str_len=str.size();
        int j=0;
        
        int aa[26]={0};
        for(int i=0;i<len;i++){
            string word;
            int tmp=j;
            for(;j<str_len;j++){
                if(str[j]==' '){
                    word=str.substr(tmp,j-tmp);
                    j++;
                    break;
                }
            }
            if(j==str_len){
                if(i!=len-1){
                    return false;
                }
                word=str.substr(tmp);
            }
            //cout<<word<<endl;
            
            if(umap.find(word)!=umap.end()){
                if(umap[word]!=pattern[i]){
                    return false;
                }
            }else{
                //not show before
                int tmptmp=pattern[i]-'a';
                if(aa[tmptmp]==1){
                    return false;
                }else{
                    aa[tmptmp]=1;
                    umap[word]=pattern[i];
                }
                
            }
        }
        if(j!=str_len){
            return false;
        }
         return true;
    }
   
};
