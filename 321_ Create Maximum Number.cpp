//
//  321_ Create Maximum Number.cpp
//  test
//
//  Created by ley on 2020/6/1.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//see the answer from the discussion
//try to write it

//看到一个C++的超快的算法
//但是建立DP的过程想想。。实现起来。。写起来有点复杂
//就是。比如你现在是。【9，3，2，6，5，4】
//你要。 宽度 1-5的
//那么 从长度6，依次drop 1就可
//drop流程，    vector<int> out
//9: out 空，压入
//3:  <9  压入
//2:  <3 压入
//6:  >2  且drop目标1>0   所以弹出2 ；弹完drop目标0，所以后续全压入，然后压入dp

//下面要再弹出1.直接找上次的6的位置，  6>3, erase 3  压入dp
//继续。此时9>6,所以压入，往后，5，   4<5,而out.size()==3 所以4不压入，记录此时末尾为最后（则后面的依次删除最后的就可以了）

//诶。。。写完感觉实现起来应该还简单，那我试试

//卧槽。。。。竟然一次就通过了。。。没报error,神奇。
//库函数真是好东西，max 直接比 vector<int>
//lexicographical_compare  比vector<int>等字符串 。 神奇神奇。
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1=nums1.size();
        int len2=nums2.size();
        int mink1=max(k-len2,0), maxk1=min(len1,k);
        int mink2=max(k-len1,0), maxk2=min(len2,k);
        //or mink2=k-maxk1   maxk2=k-mink1
        
        vector<vector<int>> dp1;
        vector<vector<int>> dp2;
        generate_dp(nums1, mink1, maxk1, dp1);
        generate_dp(nums2, mink2, maxk2, dp2);
        
        int size1=dp1.size();
        int size2=dp2.size();
        vector<int> ans;
        for(int i=0;i<size1;i++){
            ans=max(ans,merge(dp1[i], dp2[size2-1-i]));
        }
        return  ans;
    }
private:
    vector<int> merge(vector<int>& n1,vector<int>& n2){
        vector<int> ans;
        if(n1.size()==0){
            ans=n2;
        }else if(n2.size()==0){
            ans=n1;
        }else{
            // [9 5 8]
            // [9 5 6]   ??????? how to deal with       lexicographical_compare
            auto i1=n1.begin(),end1=n1.end();
            auto i2=n2.begin(),end2=n2.end();
            while(i1!=end1 || i2!=end2){
                if(lexicographical_compare(i1,end1,i2,end2)){
                    ans.push_back(*i2);
                    i2++;
                }else{
                    ans.push_back(*i1);
                    i1++;
                }
            }
        }
        return ans;
    }
    
    
    void generate_dp(vector<int>& nums,int mink,int maxk,vector<vector<int>>& dp){
        int len=nums.size();        //mink=0  maxk=4
        int drop_min=len-maxk;
        //int drop_max=len-mink;
        
        int range=maxk-mink;
        
        vector<int> tmp;
        int regi=INT_MAX;
        bool flag=false;
        for(auto a: nums){
            while(drop_min && !tmp.empty() && tmp.back()<a){
                drop_min--;
                tmp.pop_back();
            }
            if(!flag && drop_min==0){
                regi=tmp.size();
                flag=true;
            }
            tmp.push_back(a);
        }
        tmp.resize(maxk);   //!!!!!!!resize
        dp.push_back(tmp);  //0
        
        //每次drop1,drop range 次
        for(int i=0;i<range;i++){
            maxk--;     //target len
            if(regi>=tmp.size()){
                tmp.pop_back();
                dp.push_back(tmp);
            }else{
                int target=1;
                vector<int> next(tmp.begin(),tmp.begin()+regi);
                for(int t=regi;t<tmp.size();t++){
                    if(target && !next.empty() && next.back()<tmp[t]){
                        next.pop_back();
                        target=0;
                        regi=next.size();
                    }
                    next.push_back(tmp[t]);
                }
                if(target==1){
                    //means   从大到小
                    regi=INT_MAX;
                }
                next.resize(maxk);
                dp.push_back(next);
                tmp=next;
            }
        }
    
    }
    
    
    
};
