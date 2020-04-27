//
//  262_trips_and_users.cpp
//  test
//
//  Created by ley on 2020/4/28.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool isUgly(int num) {
        while(num>=5 && num%5==0){
            num=num/5;
        }
        while(num>=3 && num%3==0){
            num=num/3;
        }
        while(num>=2 && num%2==0){
            num=num/2;
        }
        if(num==1){
            return true;
        }else{
            return false;
        }
    }
};
