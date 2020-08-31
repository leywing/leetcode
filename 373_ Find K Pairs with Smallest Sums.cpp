//
//  373_ Find K Pairs with Smallest Sums.cpp
//  test
//
//  Created by ley on 2020/8/31.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//good job  by myself
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n1_len=nums1.size();
        int n2_len=nums2.size();
        vector<int> count(n1_len,0);
        if(n1_len==0 || n2_len==0) return ans;   //at least you should have one
        int i=0;
        int i1_start=0;
        int i1_end=0;   //>=i1_start
        
        while(i<k && i1_start<n1_len){
            int tmp_min=nums1[i1_start]+nums2[count[i1_start]];
            int tmp_j=i1_start;
            for(int j=i1_start;j<=i1_end;j++){
                if(nums1[j]+nums2[count[j]]<tmp_min){
                    tmp_min=nums1[j]+nums2[count[j]];
                    tmp_j=j;
                }
            }
            
            vector<int> t_t;
            t_t.push_back(nums1[tmp_j]);
            t_t.push_back(nums2[count[tmp_j]]);
            cout<<nums1[tmp_j]<<"__"<<nums2[count[tmp_j]]<<"  i1start "<<i1_start<<" i1end "<<i1_end<<" tmpmin "<<tmp_min<<endl;
            ans.push_back(t_t);
            i++;
            
            count[tmp_j]++;
            if(count[tmp_j]==n2_len) {
                // ==n2_len is enough
                i1_start=tmp_j+1;
                if(i1_end<i1_start){
                    i1_end=i1_start;
                }
            }
            
            if(i1_end<n1_len-1&&count[i1_end]>0){
                    i1_end++;
            }
        }
        
        return ans;
    }
};
