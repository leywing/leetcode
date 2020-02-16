//
//  150_evaluate_reverse_polish_notation.cpp
//  test
//
//  Created by ley on 2020/2/16.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"){
                int a1=st.top();
                st.pop();
                int a2=st.top();
                st.pop();
                a2+=a1;
                st.push(a2);
            }else if(tokens[i]=="-"){
                int a1=st.top();
                st.pop();
                int a2=st.top();
                st.pop();
                a2-=a1;
                st.push(a2);
            }else if(tokens[i]=="*"){
                int a1=st.top();
                st.pop();
                int a2=st.top();
                st.pop();
                a2*=a2;
                st.push(a2);
            }else if(tokens[i]=="/"){
                int a1=st.top();
                st.pop();
                int a2=st.top();
                st.pop();
                a2/=a1;
                st.push(a2);
            }else{
                //number
                int tmp_n=tokens[i].size();
                bool flagofplus=true;
                int j=0;
                if(tokens[i][0]=='-'){
                    flagofplus=false;
                    j++;
                }else if(tokens[i][0]=='+'){
                    j++;
                }
                
                int tmp_num=0;
                for(;j<tmp_n;j++){
                    tmp_num=tmp_num*10+int(tokens[i][j]-'0');
                }
                
                if(!flagofplus){
                    tmp_num*=(-1);
                }
                st.push(tmp_num);
            }
        }
        return st.top();
    }
};
