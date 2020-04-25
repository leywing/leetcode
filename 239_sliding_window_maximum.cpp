//
//  239_sliding_window_maximum.cpp
//  test
//
//  Created by ley on 2020/4/25.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        //bool flag=false;
        int count=0;
        int tmpi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            count++;
            if(nums[i]>=nums[tmpi]){
                tmpi=i;
            }
            if(count<k){
                continue;
            }else if(count==k){
                ans.push_back(nums[tmpi]);
            }else{
                //count>k
                if(tmpi==i-k){
                    int tmp2=tmpi+1;
                    for(int j=tmpi+1;j<=i;j++){
                        if(nums[j]>=nums[tmp2]){
                            tmp2=j;
                        }
                    }
                    tmpi=tmp2;
                    ans.push_back(nums[tmpi]);
                }else{
                    ans.push_back(nums[tmpi]);
                }
            }
        }
        return ans;
    }
};




//heihei  good deque      by myself  enough fast and with little space
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        deque<int> dq;
//        int tmpi=0;
//        int n=nums.size();
//        vector<int> ans;
//        for(int i=0;i<n;i++){
//            dq.push_back(nums[i]);
//            if(nums[i]>=nums[tmpi]){
//                tmpi=i;
//            }
//            if(dq.size()<k){
//                continue;
//            }else if(dq.size()==k){
//                ans.push_back(nums[tmpi]);
//            }else{
//                //dq.size()>k
//                if(tmpi==i-k){
//                    int tmp2=tmpi+1;
//                    for(int j=tmpi+1;j<=i;j++){
//                        if(nums[j]>=nums[tmp2]){
//                            tmp2=j;
//                        }
//                    }
//                    tmpi=tmp2;
//                    dq.pop_front();
//                    ans.push_back(nums[tmpi]);
//                }else{
//                    ans.push_back(nums[tmpi]);
//                }
//
//            }
//        }
//        return ans;
//    }
//};




//by myself  too slow and use too much space
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        priority_queue<int> que;
//        unordered_map<int, int> map;
//        vector<int> ans;
//        int n=nums.size();
//        for(int i=0;i<n;i++){
//            que.push(nums[i]);
//            map[nums[i]]++;
//            if(que.size()==k){
//                ans.push_back(que.top());
//            }else if(que.size()>k){
//                if(map[nums[i-k]]==1){
//                    map.erase(nums[i-k]);
//                }else{
//                    map[nums[i-k]]--;
//                }
//
//                while(map.find(que.top())==map.end()){
//                    que.pop();
//                }
//
//                ans.push_back(que.top());
//            }
//        }
//        return ans;
//    }
//};
