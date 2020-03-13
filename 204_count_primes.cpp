//
//  204_count_primes.cpp
//  test
//
//  Created by ley on 2020/3/13.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> leyvec(n,false);
        int ans=0;
        for(int i=2;i<n;i++){
            if(leyvec[i]==false){
                ans++;
            }else{
                continue;
            }
            for(int j=2;i*j<n;j++){
                leyvec[i*j]=true;
            }
        }
        return ans;
    }
};
