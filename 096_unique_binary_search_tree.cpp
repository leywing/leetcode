//
//  096_unique_binary_search_tree.cpp
//  test
//
//  Created by ley on 2019/12/23.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int numTrees(int n) {
        vector<int> a(n+1,0);
        if(n==0||n==1) return 1;
        a[0]=1;
        a[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                a[i]+=a[j-1]*a[i-j];
                
                // i代表以  0-i
                //第2层循环表示。 以j为根的有多少种，分别是1。。。j...n
                //左边是。 j-1个数，所以a[j-1]
                //右边是。 n-j个数，所以a[n-j]
                //相乘，就是以j为根的有多少种情况
                //则0---i   就是j从0取到i,累加，这么多种情况
                
                //DP
                
                
            }
        }
        return a[n];
    }
};
