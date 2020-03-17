//
//  207_course_schedule.cpp
//  test
//
//  Created by ley on 2020/3/13.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    //others solution from discussion
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses,vector<int>());
        vector<int> degree(numCourses,0);
        for(auto v:prerequisites){
            adj[v[1]].push_back(v[0]);
            degree[v[0]]++;
        }
        queue<int> que;
        for(int i=0;i<numCourses;i++){
            if(degree[i]==0) que.push(i);
        }
        while(!que.empty()){
            int tmp=que.front();que.pop();numCourses--;
            for(auto v1:adj[tmp]){
                degree[v1]--;
                if(degree[v1]==0){
                    que.push(v1);
                }
            }
            
            
        }
        return numCourses==0;
    }
    
};
