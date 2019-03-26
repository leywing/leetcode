//
//  004find_median_in_two_sorted_array.cpp
//  test
//
//  Created by ley on 2019/3/26.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

//此题自己对于二分的思考实在花了很长时间，虽然知道二分方法，却不知道细节该怎么写，基本为模仿答案所写，请加油！

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median=0;
        unsigned long length_1=nums1.size();
        unsigned long length_2=nums2.size();
        unsigned long m,n;
        vector<int> n1;
        vector<int> n2;
        if(length_1<=length_2){
             n1=nums1; m=length_1;
             n2=nums2; n=length_2;
        }else{
             n1=nums2; m=length_2;
             n2=nums1; n=length_1;
        }
        unsigned long i,j;
        unsigned long imin,imax;
        imin=0;
        imax=m;
        //m个数，故而m+1种切法
        
        while(imin<=imax){
            i=(imin+imax)/2;j=(m+n+1)/2-i;  //2分时，这里m+n+1的神奇之处
            if (i>imin&&n1[i-1]>n2[j]){
                imax=i-1;   //重点！！！
//                cout<<imax<<"  max ";   /////
            }else if (i<imax&&n1[i]<n2[j-1]){
                imin=i+1;  ///重点！！1
//                cout<<imin<<" min ";
            }else{
                int maxleft=0;
                if(i==0){  maxleft=n2[j-1];}
                else if (j==0) { maxleft=n1[i-1];}
                else{
                    maxleft=n1[i-1]>=n2[j-1]?n1[i-1]:n2[j-1];
                }
                
                if((m+n)%2==1) return maxleft;
               
                
                int maxright=0;
                if(i==m){
                    maxright=n2[j];
                }else if (j==n){
                    maxright=n1[i];
                }else{
                    maxright=n1[i]>=n2[j]?n2[j]:n1[i];
                }
            
                median=(maxright+maxleft)/2.0; //注意这个2.0，写2的时候按照整形算了，2.0则正常double
                return median;
            }
        }
        return 0.0;
    }
    
};



int main(){
    
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    Solution a;
    cout<<endl<<endl<<" aaaaaaa"<<endl<<a.findMedianSortedArrays(nums1, nums2)<<endl;
    return 0;
    
}
