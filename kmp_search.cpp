//
//  kmp_search.cpp
//  test
//
//  Created by ley on 2020/4/7.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class solution{
public:
    void getnext(string& p,vector<int>& next){
        int plen=p.size();
        next[0]=-1;
        int k=-1;
        int j=0;
        while(j<plen-1){
            if(k==-1||p[j]==p[k]){
                k++;
                j++;    //0   ->    1
                if(p[j]!=p[k]){     //p[1]  !=  p[0]
                    next[j]=k;
                }else{
                    next[j]=next[k];
                }
            }else{
                k=next[k];
            }
        }
    }
    
    int kmpsearch(string& s,string& p){
        int i=0;
        int j=0;
        int slen=s.size();
        int plen=p.size();
        vector<int> next(plen,0);
        getnext(p, next);
        while(i<slen&&j<plen){
            if(j==-1||s[i]==p[j]){
                i++;
                j++;
            }else{
                j=next[j];
            }
        }
        
        if(j==plen){
            return i-j;
        }else{
            return -1;
        }
    }
};
