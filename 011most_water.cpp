//
//  011most_water.cpp
//  test
//
//  Created by ley on 2019/4/2.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        unsigned long num=height.size();
        unsigned long i=0;
        unsigned long j=num-1;
        int zuo=height[i];
        int you=height[j];
        int temp_min=zuo<you?zuo:you;
        int signal_zuo=zuo<you?1:0;
        unsigned long max=temp_min*(j-i);
        while(i<j-1){
            //cout<<zuo<<" "<<you<<" "<<max<<" "<<signal_zuo<<" "<<i<<" "<<j<<endl;
            if(signal_zuo==1){
                i++;
                if(zuo<height[i]&&height[i]<=you){
                    unsigned long temp_01=height[i]*(j-i);
                    if(temp_01>max){
                        max=temp_01;
                    }
                    zuo=height[i];
                }else if (zuo<height[i]&&you<height[i]){
                    unsigned long temp_02=you*(j-i);
                    if(temp_02>max){
                        max=temp_02;
                    }
                    zuo=height[i];
                    signal_zuo=0;
                }else{
                    
                }
                
            }else{
                j--;
                if(you<height[j]&&height[j]<=zuo){
                    unsigned long temp_01=height[j]*(j-i);
                    if(temp_01>max){
                        max=temp_01;
                    }
                     you=height[j];
                }else if (you<height[j]&&zuo<height[j]){
                    unsigned long temp_02=zuo*(j-i);
                    if(temp_02>max){
                        max=temp_02;
                    }
                    you=height[j];
                    signal_zuo=1;
                }else{
                    
                }
            }
            //cout<<i<<" "<<j<<endl;
            
        }
        return max;
    }
};

int main(){
    
    vector<int> bb={2,3};
    cout<<endl<<"ley"<<endl;
    Solution aa;
    cout<<aa.maxArea(bb)<<endl;
    
    return 0;
}
