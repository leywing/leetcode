//
//  08_string_to_integer.cpp
//  test
//
//  Created by ley on 2019/12/7.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int myAtoi(string str) {
        long long a=0;
        int min=0x80000000;
        int max=0x7fffffff;
        bool flag=0;
        bool flag_02=0; //+ - sure
        bool flag_03=0; // num start
        
        for(int i=0;i<str.size();i++){
            if(str[i]==' '&&flag_02==0&&flag_03==0) continue;
            else if(str[i]=='-'&&flag_02==0&&flag_03==0){
                flag=1;
                flag_02=1;
            }
            else if(str[i]=='+'&&flag_02==0&&flag_03==0){
                flag=0;
                flag_02=1;
            }
            else if(str[i]>='0'&&str[i]<='9'){
                if(flag_03==0){
                    if(str[i]=='0') {
                        flag_03=1;
                        continue;
                    }
                    a=(int)(str[i]-'0');
                    flag_03=1;
                }else{
                    a=a*10+(int)(str[i]-'0');
                    if(a-2>max) break;
                    //flag_03=1
                }
            }else{
                break;
            }
        }
        
        if(flag==1) a=-a;
       
        if(a<min) return 0x80000000;
        if(a>max) return 0x7fffffff;
        
        int ans=a;
        
        return ans;
    }
};

int main(){
    string str="4193 with words";
    Solution aaa;
    cout<<"start"<<endl;
    cout<<aaa.myAtoi(str)<<endl;
}
