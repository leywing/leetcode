//
//  275_h_index_II.cpp
//  test
//
//  Created by ley on 2020/4/28.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//heihei  easy
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int l=0;
        int h=n-1;
        // if(citations[i]>=n-i) h>=n-i
        //find the min i,who upper is true
        if(n==0||citations[n-1]<1){
            return 0;
        }else if (citations[0]>=n){
            return n;
        }else{
            int ans=hdex2(citations, l, h); //h satisify      l not satisfy
            return n-ans;
        }
    }
private:
    int hdex2(vector<int>& citations,int l,int h){
        int n=citations.size();
        int mid=(l+h)/2;      //mid or mid+1
        while(h-l>1){                               //good jobs
            if(citations[mid]>=n-mid){
                h=mid;
            }else{
                l=mid;
            }
            mid=(l+h)/2;
        }
        return h;
    }
};
