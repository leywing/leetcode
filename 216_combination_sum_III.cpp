//
//  216_combination_sum_III.cpp
//  test
//
//  Created by ley on 2020/4/7.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        kk=k;
        com2(ans, tmp, 8, n, 0);
        return ans;
    }
    
    void com2(vector<vector<int>>& ans,vector<int>& tmp,int i,int target,int count){
        if(count>kk||count+i<kk-1||i<0) return;
        
        if(target-candi[i]>0){
            tmp.push_back(candi[i]);
            com2(ans, tmp, i-1, target-candi[i], count+1);
            tmp.pop_back();
        }else if(target-candi[i]==0){
            if(count==kk-1){
                tmp.push_back(candi[i]);
                ans.push_back(tmp);
                tmp.pop_back();
            }
        }
        
        com2(ans, tmp, i-1, target, count);
        
    }
private:
    vector<int> candi={1,2,3,4,5,6,7,8,9};
    int kk;
};
