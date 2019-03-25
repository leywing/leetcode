//
//  003longestsubstring.cpp
//  test
//
//  Created by ley on 2019/3/25.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int s_length;
     
        s_length=int(s.length());
        if(s_length==0) {return 0;}
//        printf("%d",s_length);
        char b[201];
        int a[201];
        int maxlength=1;  ///zuidachangdu
        int start=1,end=1;
        for(int i=0;i<s_length;i++){
            int sign=0;
            if(b[end]==s[i]) {start=end; a[end]=1;}
            if(i==0){b[start]=s[i];a[start]=1; continue;}
            if(start==end) {
                if(b[start]!=s[i]) {
                    if(end<=199){ b[end+1]=s[i]; end=end+1; a[end]=2;}
                    else   {end=1; b[end]=s[i]; a[end]=2;}
                    maxlength=a[end]>maxlength?a[end]:maxlength;
                    
                }
                
            }
            else if(start<end){
            for(int j=start;j<=end;j++){
                if(s[i]==b[j]) {
                    sign=1;   //xinhao
                        if(j==end) {start=end;} //qianmian yijian yanle
                        else {start=j+1;}
                    for(int num_01=start;num_01<=end;num_01++){
                        a[num_01]=a[num_01]-a[j];
                    }
                    if(end<=199){ b[end+1]=s[i]; end=end+1; a[end]=a[end-1]+1;}
                    else   {end=1; b[end]=s[i]; a[end]=a[200]+1;}
                    
                    maxlength=a[end]>maxlength?a[end]:maxlength;
                    break;
                }
            }
                if(sign==0){
                    if(end<=199){ b[end+1]=s[i]; end=end+1; a[end]=a[end-1]+1;}
                    else   {end=1; b[end]=s[i]; a[end]=a[200]+1;}
                    maxlength=a[end]>maxlength?a[end]:maxlength;
                }
            }
//            else (start>end){
            
            else {
                for(int j=start;j<=end+200;j++){
                    int temp=0;
                    int temp_02=0;
                    int temp_03=0;
                    if(j>200) {temp_03=j-200; }
                    else {temp_03=j;}
                    if(s[i]==b[temp_03]) {
                       sign=1;   //xinhao
                            if(temp_03==end) {start=end;}  //qianmian yijian yanle
                            else {
                                start=(temp_03+1)>200?temp_03+1-200:temp_03+1; temp=200;}
                        int st=0,ed=0;
                        if(start<=end){
                            st=start;ed=end;
                        }
                        else {
                            st=start;ed=end+200;
                        }
                        
                        for(int num_01=st;num_01<=ed;num_01++){
                            if(num_01>200) {temp_02=num_01-200;}
                            else {temp_02=num_01;}
                            a[temp_02]=a[temp_02]-a[temp_03];
                            
                        }
                    
                        end=end+1;
                        b[end]=s[i];
                        a[end]=a[end-1]+1;
                        maxlength=a[end]>maxlength?a[end]:maxlength;
                        break;
                    }
                }
                if(sign==0){
                    end=end+1;
                    b[end]=s[i];
                    a[end]=a[end-1]+1;
                    maxlength=a[end]>maxlength?a[end]:maxlength;
                }
            }
////         cout<<a[end]<<endl;  ///jianyan
//            cout<<start<<" "<<end<<" "<<a[end]<<endl;
        }
        
        
        
        
        return maxlength;
        
    }
};

//正解，是用哈希，依次遍历，当不存在冗余时加入哈希，并记上序号J，当存在冗余时，哈希查找出该符号对应的wi，并去掉[i，wi）的，将wi修改为J，即可。J-i与max比


int main()
{
    cout<<"haha"<<endl;
    cout<<"haha1"<<endl;
    cout<<"this one"<<endl;
    string s="qopubjguxhxdipfzwswybgfylqvjzhar";
    Solution a;
    cout<<a.lengthOfLongestSubstring(s)<<endl;
    
    return 0;
}
