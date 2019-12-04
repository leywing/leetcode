//
//  043_multiply_string.cpp
//  test
//
//  Created by ley on 2019/12/4.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        int num1_size=num1.size();
        int num2_size=num2.size();
        if(num1_size==0||num2_size==0) return "0";
        if(num1=="0"||num2=="0") return "0";
        vector<int> ley(num1_size+num2_size,0);
        
        
        for(int i=1;i<=num1_size;i++){
            int carry=0;
            int l1=(int)(num1[num1_size-i]-'0');
            for(int j=1;j<=num2_size;j++){
                //i+j-1     carry will be i+j
                int l2=(int)(num2[num2_size-j]-'0');
                int sum=l1*l2+carry+ley[i+j-1-1];
                
                int temp=sum%10;
                ley[i+j-1-1]=temp;
                carry=(sum-temp)/10;
                
                if(j==num2_size) ley[i+j-1]=carry;
            }
        }
        string ans="";
        bool flag=0;
        for(int i=num1_size+num2_size-1;i>=0;i--){
            if(flag==0&&ley[i]==0) continue;
            else{
                flag=1;
            }
            ans=ans+(char)(ley[i]+'0');
        }
        
        return ans;
    }
};
