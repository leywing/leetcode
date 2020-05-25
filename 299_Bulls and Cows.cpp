//
//  299_Bulls and Cows.cpp
//  test
//
//  Created by ley on 2020/5/25.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    string getHint(string secret, string guess) {
        int a[10]={0};
        int bull=0,cow=0;
        int len=secret.size();
        for(int i=0;i<len;i++){
            if(secret[i]==guess[i]){
                bull++;
            }
            a[secret[i]-'0']++;
            a[guess[i]-'0']--;
        }
        for(int i=0;i<10;i++){
            if(a[i]>0){
                cow+=a[i];
            }
        }
        cow=len-cow-bull;
        
        string ans=to_string(bull)+"A"+to_string(cow)+"B";
        return ans;
    }
};
