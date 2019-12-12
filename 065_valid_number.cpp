//
//  065_valid_number.cpp
//  test
//
//  Created by ley on 2019/12/11.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool isNumber(string s) {
        int size=s.size();
        if(size==0) return 0;
        int j=0;
        while(s[j]==' '){
            j++;
        }
        if(j>=size) return 0;
        
        int p=size-1;
        while(s[p]==' '){
            p--;
        }
        if(p-j==0&&s[p]=='.') return 0;
        
        int state=0;
        //0 initial   1: +-     2:number    3:  .    4:number    5: e    6: +-  7 number
        for(int i=j;i<=p;i++){
            if(state==0){
                //   nothing
                if(s[i]=='+'||s[i]=='-'){
                    state=1;
                    if(i+1>p) return false;
                    continue;
                }else if(s[i]>='0'&&s[i]<='9'){
                    state=2;
                    continue;
                }else if(s[i]=='.'){
                    state=3;
                    if(i+1>p) return false;
                    continue;
                }else{
                    return false;
                }
            }else if(state==1){
                // +/-
                if(s[i]>='0'&&s[i]<='9'){
                    state=2;
                    continue;
                }else if(s[i]=='.'){
                    state=3;
                    if(i+1>p) return false;
                    continue;
                }else{
                    return false;
                }
            }else if(state==2){
                // +5
                if(s[i]>='0'&&s[i]<='9'){
                    continue;
                }else if(s[i]=='.'){
                    state=3;
                    continue;
                }else if(s[i]=='e'){
                    state=5;
                    if(i+1>p) return false;
                    continue;
                }else{
                    return false;
                }
            }else if(state==3){
                // +5.
                if(s[i]>='0'&&s[i]<='9'){
                    state=4;
                    continue;
                }else if(s[i]=='e'){
                    if(i-2<j) return false;
                    state=5;
                    if(i+1>p) return false;
                    continue;
                }else{
                    return false;
                }
            }else if(state==4){
                // +5.6
                if(s[i]>='0'&&s[i]<='9'){
                    continue;
                }else if(s[i]=='e'){
                    state=5;
                    if(i+1>p) return false;
                    continue;
                }else{
                    return false;
                }
            }else if(state==5){
                //+5.6e
                if(s[i]=='+'||s[i]=='-'){
                    state=6;
                    if(i+1>p) return false;
                    continue;
                }else if(s[i]>='0'&&s[i]<='9'){
                    state=7;
                    continue;
                }else{
                    return false;
                }
            }else if(state==6){
                // +5.6e+
                if(s[i]>='0'&&s[i]<='9'){
                    state=7;
                    continue;
                }else{
                    return false;
                }
            }else{
                //state=7
                // +5.6e+8
                if(s[i]>='0'&&s[i]<='9'){
                    continue;
                }else{
                    return false;
                }
                
            }
        }
        
        return true;
    }
};
