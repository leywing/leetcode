//
//  306_ Additive Number.cpp
//  test
//
//  Created by ley on 2020/5/26.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//厉害了。完全自己完成，还是可以写出来的。
//就是。too ugly

//我觉得应该还是得用 BFS/DFS
//DFS快一点
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len=num.size();
        if(len<=2){
            return false;
        }
        int half_len=len/2;
        vector<long> nn;
        if(num[0]=='0'){
            nn.push_back(0);
            return isA2(nn,1,1,num);
        }else{
            long tmp=0;
            for(int i=0;i<half_len && i<=34;i++){           //len 5   i max 1 (0,1) 1+1=2
                                                            //len 4   i max 1  (0,1) 1+1=2
                tmp=tmp*10-'0'+num[i];
                nn.push_back(tmp);
                if(isA2(nn,i+1,i+1,num)){
                    return true;
                }
                nn.pop_back();
            }
        }
        return false;
    }
private:
    bool isA2(vector<long>& nn,int start,int min_size,const string& num){
        int len=num.size();
        if(len-min_size<=min_size){
            return false;
        }   //because need 2 number
        
        if(num[start]=='0'){
            nn.push_back(0);
            if(helper(nn,start+1,min_size,num)){
                return true;
            }
            nn.pop_back();
        }else{
            long tmp=0;
            for(int i=0;start+i<len && i<=34;i++){
                tmp=tmp*10-'0'+num[start+i];
                nn.push_back(tmp);
                min_size=min_size>=i+1?min_size:i+1;
                if(helper(nn,start+i+1,min_size,num)){
                    return true;
                }
                nn.pop_back();
            }
        }
        return false;
    }
    
    bool helper(vector<long>& nn,int start,int min_size,const string& num){
        int len=num.size();
        if(start==len){
            if(nn.size()>2){
                return true;
            }
            return false;
        }
        
        if(len-start<min_size){
            return false;
        }
        
        int nn_len=nn.size();
        long pastsum=nn[nn_len-1]+nn[nn_len-2];
        if(num[start]=='0'){
            if(pastsum==0){
                nn.push_back(0);
                if(helper(nn, start+1, min_size, num)){
                    return true;
                }
                nn.pop_back();
                return false;
            }
            return false;
        }else{
            // num[start]!='0'
            long tmp=stol(num.substr(start,min_size));
            for(int i=min_size-1;start+i<len && i<=34;i++){
                if(i!=min_size-1){
                    tmp=tmp*10-'0'+num[start+i];
                }
                
                if(tmp==pastsum){
                    nn.push_back(tmp);
                    min_size=i+1;
                    if(helper(nn, start+i+1, min_size, num)){
                        return true;
                    }
                    nn.pop_back();
                    return false;
                }else if(tmp>pastsum){
                    return false;
                }
            }
            return false;
        }
    
    }
};
