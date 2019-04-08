//
//  013roman_to_integer.cpp
//  test
//
//  Created by ley on 2019/4/3.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        unsigned long length=s.size();
        int num=0;
        int i=0;
        while(i<length&&s[i]=='M'){
            num=num+1000;
            i++;
        }
        if(i+1<length&&s[i]=='C'&&s[i+1]=='M'){
            num=num+900;
            i=i+2;
        }
        if(i<length&&s[i]=='D'){
            num=num+500;
            i++;
        }
        if(i+1<length&&s[i]=='C'&&s[i+1]=='D'){
            num=num+400;
            i=i+2;
        }
        while(i<length&&s[i]=='C'){
            num=num+100;
            i++;
        }
        if(i+1<length&&s[i]=='X'&&s[i+1]=='C'){
            num=num+90;
            i=i+2;
        }
        if(i<length&&s[i]=='L'){
            num=num+50;
            i++;
        }
        if(i+1<length&&s[i]=='X'&&s[i+1]=='L'){
            num=num+40;
            i=i+2;
        }
        while(i<length&&s[i]=='X'){
            num=num+10;
            i++;
        }
        if(i+1<length&&s[i]=='I'&&s[i+1]=='X'){
            num=num+9;
            i=i+2;
        }
        if(i<length&&s[i]=='V'){
            num=num+5;
            i++;
        }
        if(i+1<length&&s[i]=='I'&&s[i+1]=='V'){
            num=num+4;
            i=i+2;
        }
        while(i<length&&s[i]=='I'){
            num=num+1;
            i++;
        }
        return num;
    }
};


int main(){
    cout<<endl<<"ley"<<endl;
    string s="MCMXCIV";
    Solution aa;
    cout<<aa.romanToInt(s);
    
    
    cout<<endl;
    return 0;
}
