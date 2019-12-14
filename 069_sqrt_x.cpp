//
//  069_sqrt_x.cpp
//  test
//
//  Created by ley on 2019/12/12.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x==1) return 1;
        int dayu=46340;
        if(dayu*dayu<=x) return 46340;
        //看了别人的   用除法啊    tmp>x/tmp
        int xiaoyu=0;
        while(dayu-xiaoyu>1){
            int tmp=(dayu+xiaoyu)/2;
            
            int tmp02=tmp*tmp;
            if(tmp02>x) dayu=dayu<tmp?dayu:tmp;
            else if(tmp02==x) return tmp;
            else{
                //tmp02<x
                xiaoyu=xiaoyu>tmp?xiaoyu:tmp;
            }
            
            int tmp03=(tmp+1)*(tmp+1);
            if(tmp03>x) dayu=dayu<(tmp+1)?dayu:tmp+1;
            else if (tmp03==x) return tmp+1;
            else{
                //tmp03<x
                xiaoyu=xiaoyu>(tmp+1)?xiaoyu:tmp+1;
            }
            
        }
        
        return xiaoyu;
    }
};

int main(){
    cout<<0x7fffffff<<endl;
    return 0;
}
