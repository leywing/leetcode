//
//  018_4sum.cpp
//  test
//
//  Created by ley on 2019/4/15.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        unsigned long size=nums.size();
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
            int temp_sum=target-nums[i]-nums[j];
            unsigned long front=j+1;
            unsigned long end=size-1;
            while (front<end) {
                if(temp_sum<nums[front]+nums[end]){
                    end--;
                }else if (temp_sum>nums[front]+nums[end]){
                    front++;
                }
                else{
                    vector<int> ab(4,0);
                    ab[0]=nums[i];
                    ab[1]=nums[j];
                    ab[2]=nums[front];
                    ab[3]=nums[end];
                    ans.push_back(ab);
                    //                    cout<<ab[0]<<" "<<ab[1]<<" "<<ab[2]<<endl;
                    //重复的去掉
                    while(front<end&&nums[front]==ab[2]) front++;
                    while(front<end&&nums[end]==ab[3]) end--;
                    
                    
                }
            }
            while(j+1<size&&nums[j+1]==nums[j]){
                j++;
            }
            }
            while(i+1<size&&nums[i+1]==nums[i]){
                i++;
            }
            }
        
        return ans;
    }
};



int main(){
    cout<<endl<<endl;
    vector<int> nums={1, 0, -1, 0, -2, 2};
    Solution aaa;
    vector<vector<int>> ans;
    ans=aaa.fourSum(nums, 0);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<4;j++){
            cout<<ans[i][j]<<",";
        }
        cout<<endl;
    }
    
    
    return 0;
}
