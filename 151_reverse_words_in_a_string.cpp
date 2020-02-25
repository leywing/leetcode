//
//  151_reverse_words_in_a_string.cpp
//  test
//
//  Created by ley on 2020/2/17.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0;
        int l=0;
        int n=s.size();
        int wordcount=0;
        while(true){
            while(i<n&&s[i]==' ') i++;
            if(i==n){
                break;
            }
            if(wordcount){
                s[j]=' ';
                j++;
            }
            l=j;
            while(i<n&&s[i]!=' '){
                s[j]=s[i];
                i++;
                j++;
            }
            rev2(s, l, j-1);
            wordcount++;
        }
        
        s.resize(j);
        rev2(s,0,j-1);
        return s;
    }
    
    void rev2(string& s,int i,int j){
        while(i<j){
            char t=s[i];
            s[i]=s[j];
            s[j]=t;
            i++;
            j--;
        }
    }
};


//我的，速度可以，但是时间不是O（1）
//class Solution {
//public:
//    string reverseWords(string s) {
//        string ans;
//        int n=s.size();
//        string word;
//        bool flag=false;
//        for(int i=0;i<n;i++){
//            if(s[i]==' '){
//                if(flag==false) continue;
//                else{
//                    //new word
//                    flag=false;
//                    if(ans.size()==0){
//                        ans=word;
//                    }else{
//                        ans=word+' '+ans;
//                    }
//
//                }
//            }else{
//                if(flag==false){
//                    word=s[i];
//                    flag=true;
//                }else{
//                    word+=s[i];
//                }
//            }
//        }
//        if(flag){
//            if(ans.size()==0){
//                ans=word;
//            }else{
//                ans=word+' '+ans;
//            }
//        }
//
//        return ans;
//    }
//};
