//
//  038_count_and_say.cpp
//  test
//
//  Created by ley on 2019/11/9.
//  Copyright © 2019 ley. All rights reserved.
//

#include "leetcode.h"

class Solution {
public:
    string countAndSay(int n) {
        string ans;
        for(int i=1;i<=n;i++){
            if(i==1) ans="1";
            else{
                int temp_num=ans.size();
                if(temp_num==1) {
                    ans='1'+ans;
                    continue;
                }
                
                string temp_ans;
                
                
                
                int count=1;
                for(int j=1;j<temp_num;j++){
                            if(ans[j]!=ans[j-1]) {
                                temp_ans=temp_ans+to_string(count)+ans[j-1];
                                count=1;
                            }else{
                                count++;
                            }
                   
                    
                }
                
               
                temp_ans=temp_ans+to_string(count)+ans[temp_num-1];

                
                
                ans=temp_ans;
                
                
            }
        }
        return ans;
    }
};
