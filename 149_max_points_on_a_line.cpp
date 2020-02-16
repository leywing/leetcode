//
//  149_max_points_on_a_line.cpp
//  test
//
//  Created by ley on 2020/2/16.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        //给的是点的二维坐标，要求找出 在一条直线上，最多的点的个数
        //目前。。。刚看题目。。完全没有任何想法
        
        //看了别人的答案，就是：以每个点作为一个基准点，以斜率，去遍历其他点，但由于这题的case设置，就算用double去保存斜率，精度也不够
        //所以需要用 y/x=a   用y,x 保存
        int n1=points.size();
        if(n1<=2) return n1;
        unordered_map<int, unordered_map<int, int>> map;
        int ans=0;
        for(int i=0;i<n1;i++){
            map.clear();
            int localmax=0,overlap=0;
            for(int j=i+1;j<n1;j++){
                int x=points[j][0]-points[i][0];
                int y=points[j][1]-points[i][1];
                if(x==0&&y==0){
                    overlap++;
                    continue;
                }
                
                int gcd=generateGCD(x, y);
                //找出最大公约数，x，y的
                if(gcd!=0){
                    x/=gcd;
                    y/=gcd;
                }
                
                int tmp=++map[x][y];  //原数加一，再拿出来
                localmax=max(tmp,localmax);
            }
            ans=max(ans,localmax+overlap+1);
        }
        return ans;
        
    }
    
    int generateGCD(int a,int b){
        //辗转相除法，找出最大公约数
        if(b==0) return a;
        
        return generateGCD(b, a%b);
    }
};
