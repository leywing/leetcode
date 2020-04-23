//
//  227_basic_calculator_II.cpp
//  test
//
//  Created by ley on 2020/4/22.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int calculate(string s) {
        vector<int> signs={1};      //存加减     乘：2  除：3
        vector<int> num;
        int s_len=s.size();
        for(int i=0;i<s_len;i++){
            if(s[i]==' ') continue;
            else if(s[i]=='+'){
                signs.push_back(1);
            }else if(s[i]=='-'){
                signs.push_back(-1);
            }else if(s[i]=='*'){
                signs.push_back(2);
            }else if(s[i]=='/'){
                signs.push_back(3);
            }else{
                //number
                int number=0;
                while(i<s_len && s[i]>='0' && s[i]!=' '){
                    //in the ASCII    +-*/  < '0'
                    number=number*10-'0'+s[i];
                    i++;
                }
                if(signs.back()<=1){
                    num.push_back(number);
                }else if(signs.back()<3){
                    signs.pop_back();
                    int tmp1=num.back();
                    num.pop_back();
                    tmp1*=number;
                    num.push_back(tmp1);
                }else{
                    //   '/'
                    signs.pop_back();
                    int tmp2=num.back();
                    num.pop_back();
                    tmp2=tmp2/number;
                    num.push_back(tmp2);
                }
                i--;
            }
        }
        
        //deal with + -
        int total=0;
        int num_len=num.size();
        for(int i=0;i<num_len;i++){
            total+=signs[i]*num[i];
        }
        return total;
        
    }
};
