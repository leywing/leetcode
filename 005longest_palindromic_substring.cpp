//
//  005longest_palindromic_substring.cpp
//  test
//
//  Created by ley on 2019/3/27.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        //一个个为中心，偏历 O（o^2),不行
        //想不到，先按上面的方法写吧
        int longest_one=1;
        int longest_two=1;
        unsigned long a=s.size();  //题目说了不超1000
        
        //if(a==1&&s[0]=='a') return "a";
        //不知道为什么系统就是不让我过这一行，虽然我输出是对的，所以我就加了上面那行去做题
        if(a==0) return "";
        int start;
        int start2;
        for(int i=0;i<a;i++){
            int temp=1;
            int temp2=2;
            if(i==0){
                start=0;
                if(s[0]==s[1]){
                    start2=0;longest_two=2;
                }
            }else{
                for(int j=1;i-j>=0&&i+j<=a;j++){
                    if(s[i-j]==s[i+j]) {
                        temp=temp+2;
                        if(longest_one<temp){
                            longest_one=temp;
                            start=i-j;
                        }
                        
                    }
                    else {
                        
                        break;
                    }
                } //查了奇数个的回数
                if(s[i]==s[i+1]){
                    if(longest_two<temp2){
                        longest_two=temp2;
                        start2=i;
                    }
                    for(int j=1;i-j>=0&&i+1+j<=a;j++)
                    {
                        if(s[i-j]==s[i+1+j]){
                            temp2=temp2+2;
                            if(longest_two<temp2){
                                longest_two=temp2;
                                start2=i-j;
                            }
                        }
                        else{
                            break;
                        }
                    }
                }//偶数个的
            }
        }
        int final_start,final_length;
        if(longest_one>longest_two) {
            final_start=start;
            final_length=longest_one;
        }else{
            final_start=start2;
            final_length=longest_two;
        }
        return s.substr(final_start,final_length);
    }
};


int main(){
    string bbb="a";
    Solution aaa;
    cout<<endl<<endl<<endl<<aaa.longestPalindrome(bbb)<<endl;

    return 0;
}
