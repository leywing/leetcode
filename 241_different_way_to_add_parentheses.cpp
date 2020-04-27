//
//  241_different_way_to_add_parentheses.cpp
//  test
//
//  Created by ley on 2020/4/25.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"


//我跪了。。。。
//我怎么能这么蠢。。。。。
//写了一大堆。。愣是想用 逻辑写完。。。。。。 recursive!!!!!!!!!!

//最终还是看了discussion里 stefanpochmann大神的解法
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for(int i=0;i<input.size();i++){
            char c=input[i];
            if(ispunct(c)){
                for(int a:diffWaysToCompute(input.substr(0,i))){
                    for(int b:diffWaysToCompute(input.substr(i+1))){
                        ans.push_back(c=='+'?a+b:c=='-'?a-b:a*b);
                    }
                }
            }
        }
        
        return ans.size()?ans:vector<int>{stoi(input)};
    }

};
