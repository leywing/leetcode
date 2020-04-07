//
//  215_kth_largest_element_in_an_array.cpp
//  test
//
//  Created by ley on 2020/4/7.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"


//discussion 用的方法就是   快排

//  确定了你要 第k个
//那么，随便挑一个数，一分为2后，只需对存在第n个的部分继续就行，另一部分丢弃

//O(1)space   平均时间 O（n)

//奇了怪了。。。。为啥这个运行时间那么长。。。。。。130ms  6% speed
//我还以为我写得有问题，但是复制别人的跑，也是130ms
//明明这是 快搜的一部分，为什么会这么慢。。。

//我只能猜，大部分数据都是worst case
//优化，应该从随机选 比较数， or 选次优数。 下手
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int numslen=nums.size();
        int lo=0;
        int hi=numslen-1;
        while(lo<hi){
            //need  从大到小。  5，3，1
            int j=partition(nums, lo, hi);
            if(j==k-1){
                break;
            }else if(j>k-1){
                hi=j-1;
            }else{
                //j<k-1
                lo=j+1;
            }
        }
        
        return nums[k-1];
    }
    
    int partition(vector<int>& nums,int lo,int hi){
        int i=lo;
        int j=hi;
//        if(i==j){
//            if(nums[lo]<nums[j]){
//                exch(nums, lo, j);
//            }
//            return j;
//        }
        while(true){
            while(i<hi&&nums[i]>=nums[lo]){
                i++;
            }//means the i is  nums[i]<nums[lo]
            while(j>lo&&nums[j]<nums[lo]){
                j--;
            }//means the j is nums[j]>=nums[lo]
            if(i>=j){
                break;
            }
            exch(nums, i, j);
        }
        exch(nums,lo,j);    //because at this the j<i
        return j;
    }
    
    void exch(vector<int>& nums,int i,int j){
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }
};





//bool cmp(int a,int b){
//    return a>b;
//}
//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        //the easiest
//        //sort()  and then pick the kth
//        sort(nums.begin(), nums.end(), cmp);
//        return nums[k-1];
//    }
//
//
//};
