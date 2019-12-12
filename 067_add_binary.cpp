//
//  067_add_binary.cpp
//  test
//
//  Created by ley on 2019/12/12.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    string addBinary(string a, string b) {
        int a_n=a.size();
        int b_n=b.size();
        
        int min=a_n>b_n?b_n:a_n;
        
        string ans;
        
        char carry='0';
        for(int i=0;i<min;i++){
            if(a[a_n-1-i]=='1'&&b[b_n-1-i]=='1'){
                ans=carry+ans;
                carry='1';
            }else if(carry=='1'){
                if(a[a_n-1-i]=='1'||b[b_n-1-i]=='1'){
                    ans='0'+ans;
                    carry='1';
                }else{
                    ans='1'+ans;
                    carry='0';
                }
            }else{
                //carry='0'
                if(a[a_n-1-i]=='1'||b[b_n-1-i]=='1'){
                    ans='1'+ans;
                    carry='0';
                }else{
                    ans='0'+ans;
                    carry='0';
                }
            }
        }
        
        if(a_n==b_n){
            if(carry=='1'){
                ans='1'+ans;
                return ans;
            }else{
                return ans;
            }
        }
        
        if(a_n>b_n){
                for(int i=min;i<a_n;i++){
                    if(carry=='1'){
                        if(a[a_n-1-i]=='1'){
                            ans='0'+ans;
                            carry='1';
                        }else{
                            ans='1'+ans;
                            carry='0';
                        }
                    }else{
                        ans=a[a_n-1-i]+ans;
                    }
                }
        }else{
            for(int i=min;i<b_n;i++){
                if(carry=='1'){
                    if(b[b_n-1-i]=='1'){
                        ans='0'+ans;
                        carry='1';
                    }else{
                        ans='1'+ans;
                        carry='0';
                    }
                }else{
                    ans=b[b_n-1-i]+ans;
                }
            }
        }
        
        if(carry=='1'){
            ans='1'+ans;
            return ans;
        }else{
            return ans;
        }
        
        
    }
};
