//
//  050_pow_x_n.cpp
//  test
//
//  Created by ley on 2019/12/7.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        if(x==0.0) {
            ans=0.0;
            return ans;
        }
        if(n==0.0){
            return 1.0;
        }
        if(x==1.0){
            return 1.0;
        }
        if(x==-1.0){
            if(n>=0){
                if(n%2==0) return 1.0;
                else return -1.0;
            }else{
                //n<0
                if(n==0x80000000){
                    return 1.0;
                }else if((-n)%2==0) return 1.0;
                else return -1.0;
            }
        }
 //       cout<<"what"<<endl;
       
        if(n<0){
            if(n==0x80000000){
                ans=1/x;
                x=1/x;
                n=n+1;
                n=-n;
            }else{
                n=-n;
                x=1/x;
            }
            
//            cout<<"???"<<endl;
        }
        //别人的方法！！！比我快一倍
        while(n){
            if(n&1){
                ans*=x;
                if(ans==0) break;
            }
            x*=x;
            n>>=1;
        }
        
//        for(int i=0;i<n;i++){
//            ans=ans*x;
//            if(ans==0) break;
//        }
        
        
        return ans;
        
    }
};

int main(){
    cout<<"start"<<endl;
    double x=8.95371;
    cout<<pow(x, -3)<<endl;
    
}
