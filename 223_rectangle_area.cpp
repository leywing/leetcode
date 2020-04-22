//
//  223_rectangle_area.cpp
//  test
//
//  Created by ley on 2020/4/22.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//from the discussion
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int tmp=(C-A)*(D-B);
        int tmp2=(G-E)*(H-F);
        int ans;
        if(A>=G || B>=H || E>=C || F>=D){
            return tmp+tmp2;
        }else{
            int tmp3=(min(G,C)-max(A,E))*(min(H,D)-max(B,F));
            return tmp-tmp3+tmp2;
        }
        
        
    }
};


//by myself
//bool cmp(pair<int, int>a,pair<int, int>b){
//    return a.first<b.first;
//}
//
//class Solution {
//public:
//    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
//        if(A==E && B==F && C==G && D==H) {
//            return (C-A)*(D-B);
//        }
//        long long row1=C-A;
//        long long col1=D-B;
//        long long ans=row1*col1;
//
//        row1=G-E;
//        col1=H-F;
//        long long tmp2=row1*col1;
//        ans=tmp2+ans;
//        vector<pair<int, int>> rr={{A,1},{C,1},{E,2},{G,2}};
//        vector<pair<int,int>> cc={{B,1},{D,1},{F,2},{H,2}};
//        sort(rr.begin(),rr.end(),cmp);
//        sort(cc.begin(),cc.end(),cmp);
//
//        if(rr[0].second==rr[1].second || cc[0].second==cc[1].second){
//            return int(ans);
//        }else{
//            long long tmp3=rr[2].first-rr[1].first;
//            long long tmp4=cc[2].first-cc[1].first;
//            long long tmp5=tmp3*tmp4;
//            ans=ans-tmp5;
//            return int(ans);
//        }
//    }
//
//};
