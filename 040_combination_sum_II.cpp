//
//  040_combination_sum_II.cpp
//  test
//
//  Created by ley on 2019/12/3.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>  ans;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        int k=candidates.size();
        comsum(candidates, target, k, temp, ans);
        
        return ans;
    }
    
    void comsum(vector<int>& candidates,int target,int k,vector<int>& temp,vector<vector<int>>& ans){
        if(k==0) return;
        
        if(target-candidates[k-1]>0){
            temp.push_back(candidates[k-1]);
            comsum(candidates, target-candidates[k-1], k-1, temp, ans);
            temp.pop_back();
            
            int i=2;
            while(k-i>=0){
                if(candidates[k-i]==candidates[k-1]) {
                    i++;
                    continue;
                }else{
                    //!=
                    break;
                }
            }
            if(k-i>=0){
                comsum(candidates,target,k-i+1,temp,ans);
            }
        }else if(target-candidates[k-1]==0){
            temp.push_back(candidates[k-1]);
            ans.push_back(temp);
            temp.pop_back();
            
            int i=2;
            while(k-i>=0){
                if(candidates[k-i]==candidates[k-1]) {
                    i++;
                    continue;
                }else{
                    //!=
                    break;
                }
            }
            if(k-i>=0){
                comsum(candidates,target,k-i+1,temp,ans);
            }
        }else{
            //  <0
            comsum(candidates,target,k-1,temp,ans);
        }
    }
    
};
