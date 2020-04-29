//
//  282_expression_add_operators.cpp
//  test
//
//  Created by ley on 2020/4/29.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//copy from the submission
//only use 28ms?????????  why so fast
//let's compare

//class Solution {
//public:
//    vector<string> addOperators(string num, int target) {
//        vector<string> ans;
//        string exp(num.length() * 2, '\0');
//        dfs(num, target, 0, exp, 0, 0, 0, &ans);
//        return ans;
//    }
//private:
//    void dfs(const string& num, const int target,
//             int pos, string& exp, int len, long prev, long curr,
//             vector<string>* ans) {
//        if (pos == num.length()) {
//            if (curr == target) ans->push_back(exp.substr(0, len));
//            return;
//        }
//
//        long n = 0;
//        int s = pos;
//        int l = len;
//        if (s != 0) ++len;      //??
//        while (pos < num.size()) {
//            n = n * 10 + (num[pos] - '0');
//            if (num[s] == '0' && pos - s > 0) break; // 0X... invalid number
//            if (n > INT_MAX) break; // too long
//            exp[len++] = num[pos++];
//            if (s == 0) {
//                dfs(num, target, pos, exp, len, n, n, ans);
//                continue;
//            }
//            exp[l] = '+'; dfs(num, target, pos, exp, len, n, curr + n, ans);
//            exp[l] = '-'; dfs(num, target, pos, exp, len, -n, curr - n, ans);
//            exp[l] = '*'; dfs(num, target, pos, exp, len, prev * n, curr - prev + prev * n, ans);
//        }
//    }
//};



//from the discusson
//i try for a long time........too complex...so give up
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if(num.size()==0) return ans;
        string str(num.size()*2,'\0');
        helper(ans,str,num,0,target,0,0,0);
        return ans;
    }

private:
    void helper(vector<string>& ans,string& str,string& num,int pos,int& target,long eval,long last,int len){
        if(pos==num.size()){
            if(eval==target){
                ans.push_back(str.substr(0,len));
            }
            return;
        }

        int s=pos;
        int l=len;
        if(s!=0) len++;
        long val=0;

        while(pos<num.size()){
            if(s!=pos && num[s]=='0') break;  // 0 start not permitted
            val=val*10-'0'+num[pos];
            str[len++]=num[pos++];
            if(val>INT_MAX) break;
            //string tt=num.substr(pos,i+1-pos);
            //long val=stol(tt);
            if(s==0){
                helper(ans, str, num, pos, target, val, val, len);
                continue;
            }else{
                str[l]='+';helper(ans, str, num, pos, target, eval+val, val, len);
                str[l]='-';helper(ans, str, num, pos, target, eval-val, -val, len);
                str[l]='*';helper(ans, str, num, pos, target, eval-last+last*val, last*val, len);
            }
        }
    }
};
