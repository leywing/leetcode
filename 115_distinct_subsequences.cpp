//
//  115_distinct_subsequences.cpp
//  test
//
//  Created by ley on 2019/12/28.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        if(n1-n2<0) return 0;
        if(n1==n2){
            if(s==t) return 1;
            else return 0;
        }
        vector<int> tmp_w;
        vector<int> tmp_c;
        for(int j=0;j<n2;j++){
            vector<int> weizhi;
            vector<int> count;
            if(j==0){
                for(int i=0;i<n1;i++){
                    if(s[i]==t[j]){
                        weizhi.push_back(i);
                        if(count.size()==0){
                            count.push_back(1);
                        }else{
                            count.push_back(count.back()+1);
                        }
                    }
                }
                tmp_w=weizhi;
                tmp_c=count;
                if(weizhi.size()==0) return 0;
                continue;
            }else{
                auto cter=tmp_c.begin();
                for(auto iter=tmp_w.begin();iter!=tmp_w.end();){
                    int i=*iter+1;
                    iter++;
                    int max;
                    if(iter==tmp_w.end()){
                        max=n1-1;
                    }else{
                        max=*iter;
                    }
                    int flag=0;
                    for(;i<=max;i++){
                        if(s[i]==t[j]){
                            weizhi.push_back(i);
                            if(count.size()==0){
                                count.push_back(*cter);
                                flag=1;
                            }else if(flag==0){
                                //not the first one
                                //but the first one
                                if(INT_MAX-*cter>=count.back()){
                                    //因为它提示我越界了，而答案是INT，所以超出的绝对不会用到
                                count.push_back(*cter+count.back());
                                }
                                flag=1;
                            }else{
                                if(INT_MAX-*cter>=count.back()){
                                count.push_back(*cter+count.back());
                                }
                            }
                        }
                    }
                    cter++;
                }
                if(weizhi.size()==0) return 0;
                tmp_w=weizhi;
                tmp_c=count;
            }
        }
        return tmp_c.back();
    }
};
    
    
//    //time limit exceed........
//    int ans=0;
//    int numDistinct(string s, string t) {
//        int n1=s.size();
//        int n2=t.size();
//        int step=n1-n2;
//        if(step==0){
//            if(s==t) return 1;
//            else return 0;
//        }
//        num2(s, t, 0, 0, step);
//        return ans;
//
//    }
//    void num2(string& s,string& t,int i1,int i2,int step){
//        if(step<0) return;
//
//        if(i1>s.size()-1){
//            if(i1==s.size()&&i2==t.size()&&step==0){
//                ans++;
//                return;
//            }else{
//                return;
//            }
//        }
//        if(s.size()-i1<t.size()-i2+step) return;
//
//        if(i2==t.size()){
//            ans++;
//            return;
//        }
//
//        if(step==0){
//            if(s.substr(i1)==t.substr(i2)) ans++;
//            return;
//        }else{
//            if(s[i1]==t[i2]){
//                num2(s, t, i1+1, i2+1, step);
//            }
//            num2(s, t, i1+1, i2, step-1);
//
//        }
//    }
//
