//
//  042_Trapping_rain_water.cpp
//  test
//
//  Created by ley on 2019/12/3.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> max_01;
        max_01=find_max(height, 0, height.size()-1);
        int ans=0;
        
        if(max_01.size()==1){
            ans=left_water(height,max_01[0])+right_water(height,max_01[0]);
            
        }else if(max_01.size()>1){
            //calcul for mid_water
            int mid_min=max_01[0];
            int mid_max=max_01[0];
            for(int j=1;j<max_01.size();j++){
                if(max_01[j]<mid_min) mid_min=max_01[j];
                if(max_01[j]>mid_max) mid_max=max_01[j];
            }
            int mid_water=0;
            for(int i=mid_min;i<=mid_max;i++){
                mid_water=(height[mid_min]-height[i])+mid_water;
            }
            
            ans=mid_water+left_water(height, mid_min)+right_water(height, mid_max);
        }else{
            //max_01.size()<1
            ans=0;
        }
        
        return ans;
    }
    int left_water(vector<int>& height,int i_max_right){
        if(i_max_right==0||i_max_right==1) return 0;
        
        int left_max=i_max_right-1;
        for(int i=left_max;i>=0;i--){
            if(height[i]>=height[left_max]) left_max=i;
        }
        
        int now_water=0;
        for(int i=left_max;i<i_max_right;i++){
            now_water=now_water+(height[left_max]-height[i]);
        }
        
        return now_water+left_water(height,left_max);
        
    }
    int right_water(vector<int>& height,int i_max_left){
        if(i_max_left==(height.size()-1)||i_max_left==(height.size()-2)) return 0;
        
        int right_max=i_max_left+1;
        for(int i=right_max;i<=height.size()-1;i++){
            if(height[i]>=height[right_max]) right_max=i;
        }
        
        int now_2_water=0;
        for(int i=right_max;i>i_max_left;i--){
            now_2_water=now_2_water+(height[right_max]-height[i]);
        }
        
        return now_2_water+right_water(height, right_max);
        
    }
    vector<int> find_max(vector<int>& height,int l,int r){
        vector<int> ans;
        if(l>r) return ans;
        if(l==r) {
            ans.push_back(l);
            return ans;
        }
        
        ans.push_back(l);
        for(int i=l;i<=r;i++){
            if(height[i]==height[ans[0]]&&i!=l){
                ans.push_back(i);
            }else if(height[i]>height[ans[0]]){
                ans.clear();
                ans.push_back(i);
            }else{
                //  height[i]<height[l]
                continue;
            }
        }
        
        return ans;
    }
};
