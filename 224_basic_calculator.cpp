//
//  224_basic_calculator.cpp
//  test
//
//  Created by ley on 2020/4/22.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//others solution from discussion
//so brilliant
class Solution {
public:
    int calculate(string s) {
        int total=0;
        vector<int> signs(2,1); //so brilliant
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c >= '0'){
                int number=0;
                while(i<s.size()&&s[i]>='0'){
                    number=number*10-'0'+s[i];
                    i++;
                }
                total+=signs.back()*number;
                signs.pop_back();
                i--;
            }else if (c==')'){
                signs.pop_back();
            }else if(c!=' '){
                signs.push_back(signs.back()*(c=='-'?-1:1)); // so brilliant
            }
        }
        return total;

    }
};

////....233333.不想浪费自己写了这么久的答案。。。。d
////但是这个解法是错误的。。。因为。整数-整数，会出现 这些我用来表示符号的负数！
////2333  不行
//class Solution {
//public:
//    int calculate(string s) {
//        //  '('：-19999   ')'：-20000   ' '   '+'：-39999   '-'：-49999  和 非负整数
//        stack<int> st;
//        int s_len=s.size();
//        for(int i=0;i<s_len;i++){
//            if(s[i]==' ') continue;
//            else if(s[i]=='('){
//                if(st.size()>2){
//                    ley(st);
//                }
//                st.push(-19999);
//            }else if(s[i]==')'){
//                if(st.top()==-19999){
//                    st.pop();
//                    continue;
//                }
//                ley(st);
//                int tmpN=st.top();
//                st.pop();
//                st.pop();
//                st.push(tmpN);
//            }else if(s[i]=='+'){
//                if(st.size()>2){
//                    ley(st);
//                }
//                st.push(-39999);
//            }else if(s[i]=='-'){
//                if(st.size()>2){
//                    ley(st);
//                }
//                st.push(-49999);
//            }else{
//                int tmp=s[i]-'0';
//                if(st.empty()){
//                    st.push(tmp);
//                }else if(st.top()>0){
//                    tmp=st.top()*10+tmp;
//                    st.pop();
//                    st.push(tmp);
//                }else{
//                    st.push(tmp);
//                }
//            }
//        }
//
//        if(st.size()!=1){
//            ley(st);
//        }
//        return st.top();
//    }
//
//private:
//    void ley(stack<int>& st){
//        int tmp=st.top();
//        st.pop();
//        if(st.top()==-39999){
//            st.pop();
//            tmp+=st.top();
//            st.pop();
//            st.push(tmp);
//        }else if(st.top()==-49999){
//            st.pop();
//            tmp=st.top()-tmp;
//            st.pop();
//            st.push(tmp);
//        }else{
//            st.push(tmp);
//        }
//    }
//};
