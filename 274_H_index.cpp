//
//  274_H_index.cpp
//  test
//
//  Created by ley on 2020/4/28.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        sort(citations.begin(),citations.end());  //from least to max
        int h=1;
        for(int i=n-1;i>=0;i--){
            if(citations[i]>=h){
                h++;
            }else{
                break;
            }
        }
        return h-1;
    }
};
