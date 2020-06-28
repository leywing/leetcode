//
//  352_ Data Stream as Disjoint Intervals.cpp
//  test
//
//  Created by ley on 2020/6/13.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//wow!!.......
// i write it by myself ....and pass.....
//is enough fast......

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    //SummaryRanges() {
        
    //}
    
    void addNum(int val) {
        vector<int> tmp_one(2,val);
        if(ans.empty()) ans.push_back(tmp_one);
        
        int getlow_i=getlow(val, tmp_one);
        int len=ans.size();
        if(getlow_i<len){
            if(ans[getlow_i][0]==val+1){
                ans[getlow_i][0]=tmp_one[0];
                return;
            }else if(ans[getlow_i][0]<=val){
                return;
            }else{
                ans.insert(ans.begin()+getlow_i, tmp_one);
            }
        }else{
            ans.insert(ans.begin()+getlow_i, tmp_one);
            //ans.push_back(tmp_one);
        }
        
    }
    
    vector<vector<int>> getIntervals() {
        return ans;
    }
private:
    vector<vector<int>> ans;
    
    int getlow(int val,vector<int>& tmp_one){
        //i need to find the i   which ans[i][1]<val
        //if ans[i][1]+1=val   i need to tmp_one[0]=ans[i][0], and erase the ans[i] ,return i
        //if  not equal,  just return  i+1
        
        int lf=0;
        int rg=ans.size()-1;
        if(ans[0][1]>=val){
            return 0;
        }
        //ans[0][1]<val
        if(ans[rg][1]<val){
            if(ans[rg][1]+1==val){
                tmp_one[0]=ans[rg][0];
                ans.erase(ans.begin()+rg);
                return rg;
            }
            return rg+1;
        }
        //ans[rg][1]>=val
        
        // so at this point    lf is ok,  rg is not
        
        while(rg-lf>1){
            int mid=(rg-lf)/2+lf;
            if(ans[mid][1]<val){
                lf=mid;
            }else{
                rg=mid;
            }
        }
        
        if(ans[lf][1]+1==val){
            tmp_one[0]=ans[lf][0];
            ans.erase(ans.begin()+lf);
            return lf;
        }else{
            return lf+1;
        }

    }

};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
