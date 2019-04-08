//
//  009hui_shu.cpp
//  test
//
//  Created by ley on 2019/4/1.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        int n=0;
        if(x<0) return false;
        else if (x==0) return true;
        else{
        vector<int> a;
        while(x>0){
            int temp=x%10;
            a.push_back(temp);
            x=x/10;
            n=n+1;
        }
            int m=n-1;
            for(int i=0;i<=m-i;i++)
            {
                if(a[i]!=a[m-i]) return false;
            }
            
            return true;
        }
    }
};

int main(){
    
    int a=-121;
    Solution bb;
    cout<<endl<<endl<<bb.isPalindrome(a)<<endl;
    return 0;
}
