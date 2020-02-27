//
//  165_compare_version_numbers.cpp
//  test
//
//  Created by ley on 2020/2/26.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int num1=0,num2=0;
        bool flag1=false,flag2=false;
        int n1=version1.size(),n2=version2.size();
        int i=0;
        while(i<n1){
            if(version1[i]=='.'){
                if(i+1<n1){
                    version1=version1.substr(i+1);
                }else{
                    flag1=true;
                }
                break;
            }else{
                int temp=int(version1[i]-'0');
                num1=num1*10+temp;
            }
            i++;
        }
        if(i==n1){
            flag1=true;
        }
        
        i=0;
        while(i<n2){
            if(version2[i]=='.'){
                if(i+1<n2){
                    version2=version2.substr(i+1);
                }else{
                    flag2=true;
                }
                break;
            }else{
                int temp=int(version2[i]-'0');
                num2=num2*10+temp;
            }
            i++;
        }
        if(i==n2){
            flag2=true;
        }
        
        if(num1>num2){
            return 1;
        }else if(num1<num2){
            return -1;
        }else{
            // ==
            if(flag1&&flag2){
                return 0;
            }else if(flag1){
                i=0;
                n2=version2.size();
                num2=0;
                while(i<n2){
                    if(version2[i]=='.'){
                        if(num2>0){
                            return -1;
                        }
                    }else{
                        int temp=int(version2[i]-'0');
                        num2=num2*10+temp;
                    }
                    i++;
                }
                if(num2>0){
                    return -1;
                }else{
                    return 0;
                }
            }else if(flag2){
                i=0;
                n1=version1.size();
                num1=0;
                while(i<n1){
                    if(version1[i]=='.'){
                        if(num1>0){
                            return 1;
                        }
                    }else{
                        int temp=int(version1[i]-'0');
                        num1=num1*10+temp;
                    }
                    i++;
                }
                if(num1>0){
                    return 1;
                }else{
                    return 0;
                }
            }else{
                return compareVersion(version1, version2);
            }
        }
        
    }
};
