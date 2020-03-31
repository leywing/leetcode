//
//  210_course_schedule_II.cpp
//  test
//
//  Created by ley on 2020/3/25.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> ans;
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
            ans.push_back(tmp);
            for(auto v1:adj[tmp]){
                degree[v1]--;
                if(degree[v1]==0){
                    que.push(v1);
                }
            }
        }
        
        if(numCourses==0) return ans;
        return vector<int>();
    }
    
};



//too slow  speed only beat 17.18%
//class Solution {
//public:
//    typedef vector<vector<int>> canclass;
//
//    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//        vector<int> degree(numCourses,0);
//        vector<int> ans;
//        canclass bb=makemap(numCourses,prerequisites, degree);
//        while(1){
//            int tmp=ans.size();
//            for(int i=0;i<numCourses;i++){
//                if(degree[i]==0){
//                    ans.push_back(i);
//                    degree[i]=-1;
//                    for(auto a:bb[i]){
//                        degree[a]--;
//                    }
//                    break;
//                }
//            }
//            if(ans.size()==tmp) break;
//        }
//        if(ans.size()==numCourses) return ans;
//        return vector<int>();
//    }
//
//    canclass makemap(int numCourses,canclass& prerequistites,vector<int>& degree){
//        canclass ans(numCourses,vector<int>());
//        for(auto a:prerequistites){
//            degree[a[0]]++;
//            ans[a[1]].push_back(a[0]);
//        }
//        return ans;
//    }
//};
