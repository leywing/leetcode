//
//  168_excel_sheet_column_title.cpp
//  test
//
//  Created by ley on 2020/2/29.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n>0){
            int tmp=n%26;  //0----25       1-25 A--Y   0 mean Z
            if(tmp==0){
                tmp=26;
                n=n/26-1;
            }else{
                n=n/26;
            }
            char a=char(tmp+'A'-1);
            ans=a+ans;
        }
        return ans;
    }
};
