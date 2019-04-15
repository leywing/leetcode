//
//  020_kuohao_peidui.cpp
//  test
//
//  Created by ley on 2019/4/15.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> a;
        if(s=="") return true;
        unsigned long size=s.size();
        for(int i=0;i<size;i++){
            if(s[i]=='('){
                a.push(1);
            }else if (s[i]=='{'){
                a.push(2);
            }else if(s[i]=='['){
                a.push(3);
            }else if(s[i]==')'){
                if(a.empty()!=1&&a.top()==1) a.pop();
                else{
                    return 0;
                }
            }else if (s[i]=='}'){
                if(a.empty()!=1&&a.top()==2) a.pop();
                else {
                    return 0;
                }
            }else{
                if(a.empty()!=1&&a.top()==3) a.pop();
                else{
                    return 0;
                }
            }
        }
        if(a.empty()==1) return 1;
        else return 0;
    }
};


int main(){
    cout<<endl<<endl;
    string s="]";
    Solution aaa;
    cout<<aaa.isValid(s);
    
    
    return 0;
    
}
