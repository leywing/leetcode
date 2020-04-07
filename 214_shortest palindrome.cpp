//
//  214_shortest palindrome.cpp
//  test
//
//  Created by ley on 2020/4/4.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//see it from the discussion
//and it's so interesting ......i found that i forget KMP
//maybe i not study hard one year before........i think the most possible reason is that
//  if you learn some algorithms,but you didn't try to code it,   you will forget it or may do not understand the algorithm indeed

//so great   and fast
class Solution {
public:
    string shortestPalindrome(string s) {
        int slen=s.size();
        if(slen==1) return s;
        string tmp=s;
        reverse(tmp.begin(), tmp.end());
        tmp=s+'#'+tmp;
        
        int a=sho2(tmp);
        string tmp2=s.substr(a+1);
        reverse(tmp2.begin(), tmp2.end());
        s=tmp2+s;
        return s;
        
    }
    
    int sho2(string& p){
        int plen=p.size();
        vector<int> next(plen,0);
        next[0]=-1;
        int k=-1;
        int j=0;
        while(j<plen-1){
            if(k==-1||p[j]==p[k]){
                k++;
                j++;
                next[j]=k;
            }else{
                k=next[k];
            }
        }
        return next[plen-1];
    }
};





//too slow!!time limit exceeded
//class Solution {
//public:
//    string shortestPalindrome(string s) {
//        int n=s.size();
//        if(n==0||n==1) return s;
//        int i=0;
//        int j=n-1;
//        while(i<j&&!ispalindrome(s, i, j)){
//            j--;
//        }
//        string tmp=s;
//        for(j=j+1;j<n;j++){
//            tmp=s[j]+tmp;
//        }
//
//        return tmp;
//
//    }
//
//    bool ispalindrome(string s,int i,int j){
//        while(i<j){
//            if(s[i]==s[j]){
//                i++;
//                j--;
//            }else{
//                return false;
//            }
//        }
//        return true;
//    }
//};
