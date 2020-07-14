//
//  367_ Valid Perfect Square.cpp
//  test
//
//  Created by ley on 2020/7/15.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    bool isPerfectSquare(int num) {
        long i=2;
        long square=i*i;
        while(num >= square){
            int tmp=num % square;
            if(tmp==0){
                num=num/square;
            }else{
                //not
                i++;
                square=i*i;
            }
            
        }
        
        return (num==1);
    }
};
