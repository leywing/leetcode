//
//  060_permutation_sequence.cpp
//  test
//
//  Created by ley on 2019/12/11.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        if(n==1) return "1";
        
        vector<int> num;
        for(int i=1;i<=n;i++){
            num.push_back(i);
        }
        
        while(num.size()!=0){
            //cout<<num.size();
            int next_n=num.size()-1;
            int tmp_sum=1;
            for(int i=1;i<=next_n;i++){
                tmp_sum=i*tmp_sum;
            }
            
            
            for(int i=1;i<=num.size();i++){
                if(i*tmp_sum>=k){
                    ans=ans+(char)(num[i-1]+'0');
                    k=k-(i-1)*tmp_sum;
                    num.erase(num.begin()+i-1);
                    break;
                }else{
                    continue;
                }
            }
        }
        
        return ans;
    }
};

int main(){
    int a=3,b=6;
    Solution aaa;
    cout<<aaa.getPermutation(a, b)<<endl;
}
