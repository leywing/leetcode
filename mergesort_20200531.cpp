//
//  mergesort_20200531.cpp
//  test
//
//  Created by ley on 2020/5/31.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Mergesort {
public:
    //from min to max
    void mergesort(vector<int>& nums){
        int len=nums.size();
        spilt(nums,0,len-1);
    }
private:
    void spilt(vector<int>& nums,int start,int end){
        if(end<=start){
            return;
        }else if(end-start==1){
            if(nums[start]>=nums[end]){
                int tmp1=nums[end];
                nums[end]=nums[start];
                nums[start]=tmp1;
            }
        }else{
            int half=(end-start)/2+start;
            //cout<<half<<" ";
            spilt(nums, start, half);
            spilt(nums, half+1, end);
            merge(nums,start,half,end);
        }
    }
    
    void merge(vector<int>& nums,int start,int half,int end){
        vector<int> tmp1(nums.begin()+start,nums.begin()+half+1);
        vector<int> tmp2(nums.begin()+half+1,nums.begin()+end+1);
        int i=start;
        int j1=0,j2=0;
        int j1size=tmp1.size();
        int j2size=tmp2.size();
        
        while(i<=end){
            if(j2>=j2size || (j1<j1size && tmp1[j1]<=tmp2[j2]) ){
                nums[i]=tmp1[j1];
                j1++;
            }else{
                nums[i]=tmp2[j2];
                j2++;
            }
            i++;
        }
    }
};


int main(){
    Mergesort solution;
    vector<int> a={1,3,5,7,9,2,4,6,8,3,12313,1,523,6346,7,78678,23423};
    solution.mergesort(a);
    
    cout<<endl;
    for(auto t:a){
        cout<<t<<" ";
    }
    cout<<endl;
}
