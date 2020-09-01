//
//  374_ Guess Number Higher or Lower.cpp
//  test
//
//  Created by ley on 2020/9/1.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return          -1 if num is lower than the guess number
 *                  1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int min=1;
        return helper(1, n);
    }
private:
    int helper(int min, int max){
        if(min==max) return min;
        int mid=(max-min)/2+min;
        int tmp=guess(mid);
        if(tmp==0) return mid;
        else if (tmp==1){
            return helper(mid+1, max);
        }else{
            return helper(min, mid-1);
        }
    }
};
