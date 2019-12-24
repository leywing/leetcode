//
//  093_restore_IP_address.cpp
//  test
//
//  Created by ley on 2019/12/22.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        vector<string> ans;
        if(n/4<1) return ans;
        if(n==4){
            string tmp="";
            for(int i=0;i<4;i++){
                tmp+=s[i];
                if(i!=3) tmp+='.';
            }
            ans.push_back(tmp);
            return ans;
        }
        //n>4
        string tmp_s="";
        res2(ans, s, tmp_s, 0, 1, n);
        
        return ans;
        
    }
    void res2(vector<string>& ans,string& s,string tmp_s,int k,int stage,int left_n){
        // ans means answer
        // s   means   s
        // tmp_s     tmp_answer
        // k      s[k]
        // stage        1/2/3/4
        //left_n       left s[i]->s[n-1]
        
        if(stage==5){
            if(left_n!=0) return;
            else{
                ans.push_back(tmp_s);
                return ;
            }
        }
        
        if(k>s.size()-1) return;
        
        if(stage!=1) tmp_s+='.';
        
        if(s[k]-'0'==0){
            tmp_s+='0';
            res2(ans, s, tmp_s, k+1, stage+1, left_n-1);
            return ;
        }
        
        int tmp_int=0;
        for(int i=0;i<3;i++){
            if(k+i>s.size()-1) break;
            
            tmp_int=tmp_int*10+(s[k+i]-'0');
            if(i<2){
                string tmp_007=tmp_s+s.substr(k,i+1);
                res2(ans, s, tmp_007, k+i+1, stage+1, left_n-i-1);
            }else{
                // i==2
                if(tmp_int>255) break;
                else{
                    tmp_s+=s.substr(k,i+1);
                    res2(ans, s, tmp_s, k+i+1, stage+1, left_n-i-1);
                }
            }
        }
        
        
    }
};
