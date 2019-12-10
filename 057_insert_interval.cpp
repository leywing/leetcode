//
//  057_insert_interval.cpp
//  test
//
//  Created by ley on 2019/12/11.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int flag=0;
        for(int i=0;i<intervals.size();i++){
            if(newInterval[0]>intervals[i][0]) continue;
            else{
                //<=
                intervals.insert(intervals.begin()+i, newInterval);
                flag=1;
                break;
            }
        }
        
        if(flag==0) intervals.push_back(newInterval);
        
        return merge(intervals);
        
        
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0||intervals.size()==1) return intervals;
        
        //quicksort(intervals, 0, intervals.size()-1);
        vector<int> tmp;
        for(int i=0;i<intervals.size();i++){
            if(i==0){
                tmp=intervals[0];
                continue;
            }
            if(tmp[1]>=intervals[i][0]) tmp[1]=tmp[1]>intervals[i][1]?tmp[1]:intervals[i][1];
            else{
                //tmp[1] < intervals[i][0]
                ans.push_back(tmp);
                tmp=intervals[i];
            }
        }
        
        ans.push_back(tmp);
        
        return ans;
    }
};
