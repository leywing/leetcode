//
//  278_first_bad_version.cpp
//  test
//
//  Created by ley on 2020/4/28.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1||isBadVersion(1)) return 1;
        int l=1;
        int h=n;
        return fir2(l,h);
    }
private:
    int fir2(int l,int h){
        int mid=l+(h-l)/2;
        while (h-l>1) {
            if (isBadVersion(mid)) {
                h=mid;
            }else{
                l=mid;
            }
            mid=l+(h-l)/2;
        }
        return h;
    }
};
