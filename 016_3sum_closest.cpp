//
//  016_3sum_closest.cpp
//  test
//
//  Created by ley on 2019/4/9.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int juli=10000;
        int ans=0;
        unsigned long size=nums.size();
        for(int i=0;i<size;i++){
            int temp=target-nums[i];
            int front=i+1;
            int end=size-1;
            
            while(front<end){
                if(jueduizhi(temp-nums[front]-nums[end])<juli){
                    ans=nums[i]+nums[front]+nums[end];
                    juli=jueduizhi(target-ans);
                }
                
                
                if(temp>nums[front]+nums[end]){
                    front++;
                }else if (temp<nums[front]+nums[end]){
                    end--;
                }else{
                    return target;
                }
            }
            
            
        }
        
        return ans;
    }
    int jueduizhi(int x){
        return x>=0?x:-x;
    }
};


int main(){
    cout<<endl<<endl;
    vector<int>  aa={-1, 2, 1, -4};
    Solution ab;
    cout<<ab.threeSumClosest(aa, 1);
    cout<<endl;
    return 0;
}
