//
//  077_combinations.cpp
//  test
//
//  Created by ley on 2019/12/16.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> left_n;
        for(int i=0;i<n;i++){
            left_n.push_back(n-i);
        }
        //cout<<"start "<<left_n.size()<<endl;
        vector<int> tmp_ans;
        com2(ans, left_n, k, tmp_ans);
        
        return ans;
        
        
    }
    
    void com2(vector<vector<int>>& ans,vector<int> left_n,int lk,vector<int> tmp_ans){
        if(lk>left_n.size()) return;
        if(lk==left_n.size()){
            for(int j=0;j<left_n.size();j++){
                tmp_ans.push_back(left_n[j]);
            }
            ans.push_back(tmp_ans);
            return ;
        }
        //lk<left_n.size()
        if(lk==1){
            //cout<<"left_n.size: "<<left_n.size()<<endl;
            for(int i=0;i<left_n.size();i++){
                tmp_ans.push_back(left_n[i]);
                //cout<<"left_n: "<<i<<" "<<left_n[i]<<endl;
                ans.push_back(tmp_ans);
                tmp_ans.pop_back();
            }
            return ;
        }else{
            //lk>=2
            int tmp=left_n[left_n.size()-1];
            left_n.pop_back();
            com2(ans, left_n, lk, tmp_ans);
            
            tmp_ans.push_back(tmp);
            com2(ans,left_n,lk-1,tmp_ans);
            
        }
        
        
    }
    
};


int main(){
    Solution aaa;
    aaa.combine(4, 3);
    
    cout<<"end"<<endl;
    return 0;
}
