//
//  315_ Count of Smaller Numbers After Self.cpp
//  test
//
//  Created by ley on 2020/5/31.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
       //O(n^2) solution time limit exceeded
        
        //nums[dex.first] : real num
        //dex.second:  record how many times it switch to the right
        
        int len=nums.size();
        vector<int> ans(len,0);
        vector<int> index(len);
        for(int i=0;i<len;i++){
            index[i]=i;
        }
        //cout<<"what the fuck"<<endl;
        mergesort(nums, 0, len-1, ans, index);
        return ans;
    }
private:
    void mergesort(vector<int>& nums,int start,int end,vector<int>& ans,vector<int>& index){
        if(end<=start){
            return;
        }else if (end-start==1){
            if(nums[ index[start] ]>nums[ index[end] ]){
                ans[ index[start] ]++;
                int tmp=index[start];
                index[start]=index[end];
                index[end]=tmp;
            }
        }else{
            int half=(end-start)/2+start;
            mergesort(nums, start, half, ans, index);
//            cout<<" first half "<<endl;
//            for(int i=start;i<=half;i++){
//                cout<<nums[index[i]]<<" ";
//            }
//            cout<<endl;
            mergesort(nums, half+1, end, ans, index);
//            cout<<" second half "<<endl;
//            for(int i=half+1;i<=end;i++){
//                cout<<nums[index[i]]<<" ";
//            }
//            cout<<endl;
            //merge
            
            int t1=start,t2=half+1;
            int count2=0;
            vector<int> tmp;
            while(t1<=half || t2<=end){
                if(t2>end || (t1<=half && nums[ index[t1] ]<=nums[ index[t2] ])){
                    ans[ index[t1] ]+=count2;
                    tmp.push_back(index[t1]);
                    t1++;
                }else{
                    count2++;
                    tmp.push_back(index[t2]);
                    t2++;
                }
            }
//            for(auto t:index){
//                cout<<nums[t]<<"("<<t<<")("<<ans[t]<<") ";
//            }
//            cout<<endl;
            
            for(int i=start;i<=end;i++){
                index[i]=tmp[i-start];
            }
//            for(auto t:index){
//                cout<<nums[t]<<"("<<t<<")("<<ans[t]<<") ";
//            }
//            cout<<endl;
//            for(auto t2:ans){
//                cout<<t2<<" ";
//            }
//            cout<<endl;
        }
    }
    
};

int main(){
    vector<int> nums={5,2,6,1};
    Solution aaa;
    cout<<"hahaha "<<endl;
    aaa.countSmaller(nums);
    return 0;
}
