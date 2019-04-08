//
//  012integer_to_roman.cpp
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
    string intToRoman(int num) {
        string s;
        while(num-1000>=0){
            s=s+'M';
            num=num-1000;
        }
        while(num-900>=0){
            s=s+"CM";
            num=num-900;
        }
        while(num-500>=0){
            s=s+'D';
            num=num-500;
        }
        while(num-400>=0){
            s=s+"CD";
            num=num-400;
        }
        while(num-100>=0){
            s=s+'C';
            num=num-100;
        }
        while(num-90>=0){
            s=s+"XC";
            num=num-90;
        }
        while(num-50>=0){
            s=s+'L';
            num=num-50;
        }
        while(num-40>=0){
            s=s+"XL";
            num=num-40;
        }
        while(num-10>=0){
            s=s+'X';
            num=num-10;
        }
        while(num-9>=0){
            s=s+"IX";
            num=num-9;
        }
        while(num-5>=0){
            s=s+'V';
            num=num-5;
        }
        while(num-4>=0){
            s=s+"IV";
            num=num-4;
        }
        while(num-1>=0){
            s=s+'I';
            num=num-1;
        }
        return s;
    }
};


int main(){
    cout<<endl<<endl<<"ley"<<endl;
    Solution bb;
    cout<<bb.intToRoman(1994);
    
    cout<<endl;
    return 0;
}
