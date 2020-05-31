//
//  313_Super Ugly Number.cpp
//  test
//
//  Created by ley on 2020/5/29.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//see the discussion say direct from Ugly number II
//direct????why will fast than my priority_queue solution......I don't understand ,have a try

//........only consume 84 seconds
//what the f-word
//discussion里用有限队列的也更慢了。说，应该是更高级的object相比低级的更花费时间
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ans(n);
        int len=primes.size();
        vector<int> vec(len,0);
        vector<int> val=primes;
        
        int next=1;
        for(int i=0;i<n;i++){
            ans[i]=next;
            
            next=INT_MAX;
            for(int j=0;j<len;j++){
                if(val[j]==ans[i]){
                    vec[j]++;
                    val[j]=ans[vec[j]]*primes[j];
                }
                next=min(next,val[j]);
            }
        }
        
        
        
        
//        while(ans.size()<n){
//            int tmp_min=INT_MAX;
//            for(int i=0;i<len;i++){
//                tmp_min=min(tmp_min,ans[vec[i]]*primes[i]);
//            }
//            ans.push_back(tmp_min);
//            for(int i=0;i<len;i++){
//                if(tmp_min==ans[vec[i]]*primes[i]){
//                    vec[i]++;
//                }
//            }
//        }
        
        return ans[n-1];
        
        
    }
};


////by  myself ,but not fast enough
//struct st1 {
//    bool operator()(const pair<int, int>& a,const pair<int, int>& b){
//        return a.first>=b.first;
//    }
//};
//
//
//
//class Solution {
//public:
//    int nthSuperUglyNumber(int n, vector<int>& primes) {
//        int len=primes.size();
//        if(primes.empty() || primes[0]==1){
//            cout<<"error"<<endl;
//        }
//        
//        vector<int> ans;
//        vector<int> count(len,0);
//        priority_queue<pair<int, int>,vector<pair<int, int>>,st1> pq;
//        for(int i=0;i<len;i++){
//            pair<int,int> tmp_p;
//            tmp_p.first=primes[i];
//            tmp_p.second=i;
//            pq.push(tmp_p);
//        }
//
//        ans.push_back(1);
//
//        while(ans.size()<n){
//            int top_first=pq.top().first;
//            ans.push_back(top_first);
//
//            while(!pq.empty() && pq.top().first==top_first){
//                int tmp_n=pq.top().second;
//                pq.pop();
//                count[tmp_n]++;
//
//                pair<int, int> tt2;
//                tt2.first=ans[count[tmp_n]]*primes[tmp_n];
//                tt2.second=tmp_n;
//                pq.push(tt2);
//            }
//        }
//
//        return ans[n-1];
//        
//    }
//};
