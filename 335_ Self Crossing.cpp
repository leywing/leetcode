//
//  335_ Self Crossing.cpp
//  test
//
//  Created by ley on 2020/6/10.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//others' solution from discussion

//i think a lot too.....  about the if() function
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int b=0,c=0,d=0,e=0,f=0;
        for(auto a:x){
            if( d>=b && d>0 && (a>=c || c>=e && a+e>=c && f+b>=d && e>=0) ){
                cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
                return true;
            }
        f=e;e=d;d=c;c=b;b=a;
        }
        return false;
        
        
        //  you can think    i is only with  i+1,+2,+3,+4,+5
        //                   a                b   c  d  e  f
        
        //or in this code   i is only with   i-1, -2,-3,-4,-5
        //                  a                 b   c   d  e  f
        //only int two situation will a cross  d   or  a cross f
        //a cross d:     need    d>=b && a>=c
        //a cross f:     need    d>=b && c>=e && a+e>=c && f+b>=d
    }
};
