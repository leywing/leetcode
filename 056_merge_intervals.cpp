//
//  056_merge_intervals.cpp
//  test
//
//  Created by ley on 2019/12/10.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0||intervals.size()==1) return intervals;
        
        quicksort(intervals, 0, intervals.size()-1);
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
    
    void quicksort(vector<vector<int>>& intervals,int first,int last){
        if(first>=last) return;
        
        int pivot=intervals[first][0];
        int left=first+1;
        int right=last;
        vector<int> temp;
        
        while(left<=right){
            while(left<=right&&intervals[left][0]<pivot) left++;
            while(left<=right&&intervals[right][0]>pivot) right--;
            
            if(left>=right) break;
            
            temp=intervals[left];
            intervals[left]=intervals[right];
            intervals[right]=temp;
            
            left++;
            right--;
        }
        
        temp=intervals[right];
        intervals[right]=intervals[first];
        intervals[first]=temp;
        
        quicksort(intervals, first,right-1);
        quicksort(intervals, left, last);
    }
};
