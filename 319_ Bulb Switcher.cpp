//
//  319_ Bulb Switcher.cpp
//  test
//
//  Created by ley on 2020/6/1.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"


class Solution {
public:
    int bulbSwitch(int n) {
        int ans=0;
        int i=1;
        while(i*i<=n){
            ans++;
            i++;
        }
        return ans;
    }
};
