//
//  310_Minimum Height Trees.cpp
//  test
//
//  Created by ley on 2020/5/28.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            vector<int> ans;
            ans.push_back(0);
            return ans;
        }
        
        vector<int> count(n,0);
        vector<bool> found(n,0);    //all not found
        vector<vector<int>> v2(n,vector<int>());
        int len=edges.size();
        for(int i=0;i<len;i++){
            count[edges[i][0]]++;
            v2[edges[i][0]].push_back(edges[i][1]);
            
            count[edges[i][1]]++;
            v2[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        vector<int> ans;
        vector<int> next;
        for(int i=0;i<n;i++){
            if(count[i]==1){
                found[i]=true;
                ans.push_back(i);
            }
        }
        for(int i=0;i<ans.size();i++){
            for(auto a1:v2[ans[i]]){
                if(!found[a1]){
                    //not found
                    count[a1]--;
                    if(count[a1]<=1){
                        found[a1]=true;
                        next.push_back(a1);
                    }
                }
            }
        }
        
        int getNode=0;
        
        
        if(ans.size()+next.size()==n){
            if(next.size()==0){
                return ans;
            }
            return next;
        }
        getNode=ans.size();
        
        while(getNode+next.size()<n){
            getNode+=next.size();
            ans=next;
            next.clear();
            for(int i=0;i<ans.size();i++){
                for(auto a1:v2[ans[i]]){
                    if(!found[a1]){
                        //not found
                        count[a1]--;
                        if(count[a1]<=1){
                            found[a1]=true;
                            next.push_back(a1);
                        }
                    }
                }
            }
        }
        
        return next;
        
    }
};
