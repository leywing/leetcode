//
//  347_ Top K Frequent Elements.cpp
//  test
//
//  Created by ley on 2020/6/11.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> u_map;
        for(auto a:nums){
            u_map[a]++;
        }
        
        
        //use prority_queue,   but speed is the same as directly compare to count[i] array
        vector<int> ans;
        //vector<int> count;
        typedef pair<int, int> p_ley;
        priority_queue<p_ley,vector<p_ley>,greater<p_ley>> pq;      //有greater 降序。   不然默认生序 根据a.first
        for(auto a:u_map){
            pq.push(make_pair(a.second, a.first));
            if(pq.size()<=k){
                continue;
            }else{
                //==k
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        
        
        //enough fast by myself
//        for(auto a:u_map){
//            if(count.size()<k){
//                ans.push_back(a.first);
//                count.push_back(a.second);
//            }else{
//                // =k
//                int min_i=-1;
//                int tmp_min=a.second;
//                for(int i=0;i<k;i++){
//                    if(count[i]<tmp_min){
//                        min_i=i;
//                        tmp_min=count[i];
//                    }
//                }
//
//                if(min_i==-1) continue;
//                ans[min_i]=a.first;
//                count[min_i]=a.second;
//            }
//        }
        return ans;
    }
};
