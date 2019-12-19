//
//  084_largest_rectangle_in_histogram.cpp
//  test
//
//  Created by ley on 2019/12/18.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    //others method
    //excellent
    //!!!!!!!good good study
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0) return 0;
        if(n==1) return heights[0];
        
        heights.push_back(0);
        n++;
        stack<int> s;
        int ans=0;
        
        int i=0,j=0,h=0;
        while(i<n){
            if(s.empty()||heights[i]>=heights[s.top()]){
                s.push(i);
                i++;
            }
            else{
                h=heights[s.top()];
                s.pop();
                
                j=s.empty()?-1:s.top();
                ans=h*(i-j-1)>ans?h*(i-j-1):ans;
            }
        }
        
        return ans;
        
    }
};


////not pass .....allocate too much vector<int>     if some heights[i]==INT_MAX
//class Solution {
//public:
//    int largestRectangleArea(vector<int>& heights) {
//        int max=0;
//        if(heights.size()==0) return 0;
//
//        int heights_max=0;
//        for(int i=0;i<heights.size();i++){
//            heights_max=heights[i]>heights_max?heights[i]:heights_max;
//        }
//
//        vector<int> count(heights_max,0);
//        int tmp_high=0;
//        for(int i=0;i<heights.size();i++){
//            if(tmp_high>heights[i]){
//                for(int j=heights[i];j<tmp_high;j++){
//                    count[j]=0;
//                }
//            }
//
//            for(int j=0;j<heights[i];j++){
//                count[j]+=j+1;
//                if(count[j]>max) max=count[j];
//            }
//            tmp_high=heights[i];
//        }
//
//        return max;
//    }
//};
