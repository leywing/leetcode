//
//  029_divide_two_integers.cpp
//  test
//
//  Created by ley on 2019/12/8.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans=0;
        long long dd=dividend;
        long long di=divisor;
        
        int max=0x7fffffff;
        int min=0x80000000;
        
        int flag=0;
        // 0  or 2 :+
        //1  : -
        if(dd==0) return 0;
        if(dd<0){
            flag+=1;
            dd=-dd;
        }
        if(di<0){
            flag+=1;
            di=-di;
        }
        
        if(di==1){
            if(flag==1){
                // -
                    int tmp=-dd;
                    return tmp;
            }else{
                // +
                if(dividend==min) return max;
                else{
                int tmp=dd;
                return tmp;
                }
            }
        }
        
        //别人的方法
        //我一开始一个个减，超时了。。。。
        //唉，作为一个verilog工程师，怎么能用不好移位呢！！！！学好移位啊
        //哦，学到labs()  取绝对值
        while(dd-di>=0){
            long temp01=di,m=1;
            while(temp01<<1<=dd){
                temp01<<=1;
                m<<=1;
            }
            dd-=temp01;
            ans+=m;
            //impossible overflow
        }
        
        
        if(flag==1){
                int tmp=-ans;
                return tmp;
        
        }else{
            int tmp=ans;
            return tmp;
        }
        
        
    }
};
