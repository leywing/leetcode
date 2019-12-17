//
//  081_search_in_rotated_sorted_array_II.cpp
//  test
//
//  Created by ley on 2019/12/17.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return false;
        
        int left=0;
        int right=n-1;
        
        if(nums[right]>nums[left]){
            left=right;
        }else if(nums[right]<nums[left]){
            while(right-left>1){
                //cout<<"hi"<<endl;
                int tmp=left+(right-left)/2;
                if(nums[tmp]>=nums[left]){
                    left=tmp>left?tmp:left;
                }else{
                    //nums[tmp]<nums[left]
                    right=tmp<right?tmp:right;
                }
                
                if(tmp+1<nums.size()&&nums[tmp+1]>=nums[left]){
                    left=tmp+1>left?tmp+1:left;
                }else{
                    //nums[tmp-1]<nums[left]
                    right=tmp+1<right?tmp+1:right;
                }
            }
        }else{
            // ==
            // 一个个找吧。。。。11111111121111111
            //这种想不到可以二分找的方法
            int i;
            for(i=0;i<nums.size();i++){
                if(nums[i]==target) return true;
                if(i==0) continue;
                if(i-1>=0&&nums[i]>=nums[i-1]) continue;
                else{
                    //nums[i]<nums[i-1]
                    break;
                }
            }
            left=i-1;
            right=left+1<nums.size()?left+1:nums.size()-1;
            
        }
        
        if(target>nums[left]) return false;
        if(target==nums[left]) return true;
        
        int begin;
        int end;
        if(target>=nums[0]){
            //2 spilt    0->left
            begin=0;
            end=left;
        }else{
            //2 spilt    right->nums.size()-1
            begin=right;
            end=nums.size()-1;
        }
        
        while(end-begin>1){
            //cout<<"oh no"<<endl;
            int tmp=begin+(end-begin)/2;
            if(nums[tmp]==target) return true;
            else if(nums[tmp]>target){
                end=end<tmp?end:tmp;
            }else{
                //  nums[tmp]<target
                begin=begin>tmp?begin:tmp;
            }
            
            if(tmp+1<=end){
                if(nums[tmp+1]==target) return true;
                else if(nums[tmp+1]>target){
                    end=end<tmp+1?end:tmp+1;
                }else{
                    //nums[tmp+1]<target
                    begin=begin>tmp?begin:tmp;
                }
            }
        }
        
        if(nums[begin]==target||nums[end]==target) return true;
        return false;
        
        
    }
};

int main(){
    vector<int> aaa={2,5,6,0,0,1,2};
    Solution ley;
    cout<<ley.search(aaa, 3);
    
    return 0;
}
