//
//  010regular_expression_matching.cpp
//  test
//
//  Created by ley on 2019/4/1.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        unsigned long length_s=s.size();
        length_s=length_s-1;
        unsigned long length_p=p.size();
        length_p=length_p-1;
        int j=0;
        int i=0;
        if(p[0]=='*') return false;
        for(;i<=length_s&&j<=length_p;){
            if(s[i]==p[j]||p[j]=='.'){ //直接相等的情况
                i++;
                j++;
            }else if(p[j]=='*'){         //'.*'单独a考虑
                if(p[j-1]=='*') return false;
                else if(p[j-1]=='.'){
                    cout<<"this"<<endl;
                    if(j==length_p){
                        return true;
                    }else{
                        cout<<"now"<<endl;
                        if(i-1>=0){
                            cout<<i<<endl;
                            cout<<"007"<<endl;
                            for(int ii=0;i+ii-1<=length_s&&j+1<=length_p;ii++){
                                if(isMatch(s.substr(i+ii-1), p.substr(j+1))){
                                    return true;
                                }
                            }
                                return false;
                        }else{
                            cout<<"here"<<endl;
                            for(int ii=0;i+ii<=length_s&&j+1<=length_p;ii++){
                                if(isMatch(s.substr(i+ii), p.substr(j+1))){
                                    return true;
                                }
                            }
                            return false;
                        }
                        }
                    }
                else if (i-1>=0&&p[j-1]==s[i-1]){
                    int temp1=1,temp2=0;
                    for(;i+temp1-1<=length_s;){
                        if(s[i+temp1-1]==s[i-1])
                        {
                            temp1=temp1+1;
                        }else{
                            break;
                        }
                    }
//                    while(s[i+temp1-1]==s[i-1]){
//                        temp1=temp1+1;
//                    }
                    for(;j+temp2+1<=length_p;){
                        if(s[j+temp2+1]==s[i-1])
                        {
                            temp2=temp2+1;
                        }else{
                            break;
                        }
                    }
//                    while(p[j+temp2+1]==s[i-1]){     //未考虑‘.'
//                        temp2=temp2+1;
//                    }
                    if(temp1>=temp2){
                        //这里要考虑a*aa.a.a的情形，这里还没写？？？
                            i=i+temp1-1;
                            j=j+temp2+1;
                    }else{
                        return false;
                    }
            }else{
                    return false;
                }
                
        }else if(j+1<=length_p){
            if(p[j+1]=='*') j=j+2;
            else return false;
        }else{
                return false;
            }
            
        }
        if(i==length_s+1&&j==length_p+1){
            
            return true;
        }else{
            return false;
        }
            
        
    }
};


int main(){
    string s="";
    string p= ".*b";
    Solution aa;
    cout<<endl<<endl<<"answer:1/0"<<endl<<aa.isMatch(s, p)<<endl;
    
    
    return 0;
}
