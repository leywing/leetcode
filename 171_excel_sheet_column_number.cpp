//
//  171_excel_sheet_column_number.cpp
//  test
//
//  Created by ley on 2020/2/29.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int titleToNumber(string s) {
        int n=s.size();
        int ans=0;
        int sup=26;
        for(int i=0;i<n;i++){
            int tmp=int(s[i]-'A'+1);
            ans=ans*sup+tmp;
        }
        return ans;
    }
};
