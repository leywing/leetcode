//
//  332_ Reconstruct Itinerary.cpp
//  test
//
//  Created by ley on 2020/6/7.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//others' solution from discussion
//amazing!!!!!
//learn:
//         multiset<int>       default  小顶堆
//         multiset<int,greater<int>>   大顶堆
//         multiset<int,less<int>>

//          priority_queue<int>  default 大顶堆
//          priority_queue<int,greater<int>>   小顶堆。 从小到大。     很奇怪，要记住。
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        u_map.clear();
        route.clear();
        for(auto a:tickets){
            u_map[a[0]].insert(a[1]);
        }
        visit("JFK");
        return vector<string>(route.rbegin(),route.rend());
    }
private:
    unordered_map<string, multiset<string>> u_map;
    //default multiset<string>  equal   multiset<string, less<string>>    小顶堆，从小到大 begin()--to end()
    vector<string> route;
    
    void visit(string airport){
        while(u_map[airport].size()){
            string tmp=*u_map[airport].begin();
            u_map[airport].erase(u_map[airport].begin());
            visit(tmp);
        }
        route.push_back(airport);
    }
    
};
