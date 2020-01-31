//
//  135_candy.cpp
//  test
//
//  Created by ley on 2020/1/30.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int candy(vector<int>& ratings) {
        //开心，至少完全是我自己想的
        //空闲效率差了，时间可以70%
        
        //思路如下
        //1.先找出那些比两边都小于等于的，给一个。标-1
        //2.从 -1。到 下一个 -1。  同时往中间走，取大的
        queue<int> min_q;
        int n=ratings.size();
        vector<int> can(n,1);
        //假设分数都是正数
        if(n==1) return 1;
        for(int i=0;i<n;i++){
            if(i==0){
                if(ratings[i]<=ratings[i+1]){
                    min_q.push(i);
                }else{
                    ;
                }
            }else if(i==n-1){
                if(ratings[i]<=ratings[i-1]){
                    min_q.push(i);
                }else{
                    ;
                }
            }else if(ratings[i-1]>=ratings[i]&&ratings[i]<=ratings[i+1]){
                min_q.push(i);
            }else{
                ;
            }
        }
        
        //step 2
        int left=min_q.front();
        min_q.pop();
        if(min_q.empty()){
            for(int i=left;i>=0;i--){
                if(i==left) continue;
                else{
                    can[i]=can[i+1]+1;
                }
            }
            for(int i=left;i<n;i++){
                if(i==left) continue;
                else{
                    can[i]=can[i-1]+1;
                }
            }
            int ans=0;
            for(int i=0;i<n;i++){
                ans+=can[i];
            }
            return ans;
        }
        //mean at least two min
        for(int i=left;i>=0;i--){
            if(i==left) continue;
            else{
                can[i]=can[i+1]+1;
            }
        }
        while(!min_q.empty()){
            int right=min_q.front();
            min_q.pop();
            for(int i=left+1;i<right;i++){
                if(ratings[i]>ratings[i-1]){
                    can[i]=can[i-1]+1;
                }else{
                    break;
                }
            }
            for(int i=right-1;i>left;i--){
                if(ratings[i]>ratings[i+1]){
                    can[i]=(can[i+1]+1)>can[i]?(can[i+1]+1):can[i];
                    //may can be youhua
                }else{
                    break;
                }
            }
            left=right;
        }
        for(int i=left;i<n;i++){
            if(i==left) continue;
            else{
                can[i]=can[i-1]+1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=can[i];
        }
        return ans;
        
        
        
        return ans;
    }
};


//别人的
//int candy(vector<int> &ratings)
//{
//    int size=ratings.size();
//    if(size<=1)
//        return size;
//    vector<int> num(size,1);
//    for (int i = 1; i < size; i++)
//    {
//        if(ratings[i]>ratings[i-1])
//            num[i]=num[i-1]+1;
//    }
//    for (int i= size-1; i>0 ; i--)
//    {
//        if(ratings[i-1]>ratings[i])
//            num[i-1]=max(num[i]+1,num[i-1]);
//    }
//    int result=0;
//    for (int i = 0; i < size; i++)
//    {
//        result+=num[i];
//        // cout<<num[i]<<" ";
//    }
//    return result;
//}
