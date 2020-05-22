//
//  292_nim_game.cpp
//  test
//
//  Created by ley on 2020/5/22.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
//so fucking easy
class Solution {
public:
    bool canWinNim(int n) {
        int tmp=n%4;
        if(tmp==0){
            return false;
        }else{
            return true;
        }
    }
};
