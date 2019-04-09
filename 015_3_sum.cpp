//
//  015_3_sum.cpp
//  test
//
//  Created by ley on 2019/4/9.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    //没那么简单，这个允许输入的数列有重复的元素，有重复元素咋办？？？？
    //我自己想的是用哈希，unordered_map来实现查找，但是r后面发现题目要求，是不能出现重复答案的，所以不行
    //于是去看了别人的标准答案
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        unsigned long size=nums.size();
        for(int i=0;i<size;i++){
            int temp_sum=-nums[i];
            unsigned long front=i+1;
            unsigned long end=size-1;
            while (front<end) {
                if(temp_sum<nums[front]+nums[end]){
                    end--;
                }else if (temp_sum>nums[front]+nums[end]){
                    front++;
                }
                else{
                    vector<int> ab(3,0);
                    ab[0]=nums[i];
                    ab[1]=nums[front];
                    ab[2]=nums[end];
                    ans.push_back(ab);
//                    cout<<ab[0]<<" "<<ab[1]<<" "<<ab[2]<<endl;
                    //重复的去掉
                    while(front<end&&nums[front]==ab[1]) front++;
                    while(front<end&&nums[end]==ab[2]) end--;
                    
                    
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
    vector<int> cc={-1, 0, 1, 2, -1, -4};
    Solution aaa;
    vector<vector<int>> dd=aaa.threeSum(cc);
    
    unsigned long temptemp=dd.size();
   
    for(int i=0;i<temptemp;i++){
        for(int j=0;j<3;j++){
            cout<<" "<<dd[i][j];
        }
        cout<<endl;
    }
    return  0;
}




