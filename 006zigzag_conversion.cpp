//
//  006zigzag_conversion.cpp
//  test
//
//  Created by ley on 2019/3/27.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string a[numRows];
        unsigned long num=s.size();
        int temp=0;
        if(numRows==1) return s;
        while(num>=1){
            if(num>=2*numRows-2){
                for(int i=0;i<numRows;i++){
                    a[i]=a[i]+s[temp+i];
                    }
                temp=temp+numRows;   //应该没错吧
                for(int i=0;i<numRows-2;i++){
                    a[numRows-i-2]=a[numRows-i-2]+s[temp+i];
                }
                temp=temp+numRows-2;
                num=num-(2*numRows-2);
            }else if (num>numRows){
                for(int i=0;i<numRows;i++){
                    a[i]=a[i]+s[temp+i];
                }
                temp=temp+numRows;   //应该没错吧
                num=num-numRows;
                for(int i=0;i<=num-1;i++){
                    a[numRows-i-2]=a[numRows-i-2]+s[temp+i];
                }
                num=0;
            }else{
                for(int i=0;i<=num-1;i++){
                    a[i]=a[i]+s[temp+i];
                }
                num=0;
            }
        }
        //cout<<a[0]<<endl;
        for(int i=1;i<numRows;i++){
          //  cout<<a[i]<<endl;
            a[0]=a[0]+a[i];
        }
        return a[0];
    }
};

//标准答案里：是说定义一个goingdown的信号，在0和n-1处，信号取反即可；
//我的方法一样是0（n),但操作太多？太乱？使得时间和内存都不好；

int main(){
    string s = "A";
    int numRows = 1;
    Solution bb;
    cout<<endl<<endl<<"开始"<<endl<<bb.convert(s, numRows)<<endl;
    
    
    
    return 0;
}
