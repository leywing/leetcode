//
//  134_gas_station.cpp
//  test
//
//  Created by ley on 2020/1/30.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int first=0,last_i=0;
        
        int n=gas.size();
        int tmp_num=0;
        for(int i=0;i<n;i++){
            gas[i]=gas[i]-cost[i];
            tmp_num+=gas[i];
        }
        if(tmp_num<0) return -1;
      
        if(n==1) return 0;
        
        tmp_num=gas[first];
        while(first<n){
            if(gas[first]<0){
                tmp_num=tmp_num-gas[first];
                first++;
                last_i--;
                continue;
            }// find the start point
            if(last_i<=0){
                last_i=0;
                tmp_num=gas[first];
            }
            while(last_i<=n){
                if(last_i==n) return first;
                if(last_i==0){
                    last_i++;
                    continue;
                }
                tmp_num=tmp_num+gas[(first+last_i)%n];
                if(tmp_num<0) break;
                last_i++;
            }
            tmp_num=tmp_num-gas[first];
            first++;
            last_i--;
        }
        
        return -1;
    }
};
