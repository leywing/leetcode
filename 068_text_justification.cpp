//
//  068_text_justification.cpp
//  test
//
//  Created by ley on 2019/12/12.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int size=words.size();
        
        int pre_n=0;
        int left_size=maxWidth;
        int i;
        for(i=0;i<size;i++){
            int tmp=words[i].size();
            if(left_size-pre_n>tmp){
                left_size=left_size-tmp;
                pre_n++;
            }else if(left_size-pre_n==tmp){
                string tmp_str;
                for(int j=pre_n;j>=1;j--){
                    tmp_str+=words[i-j];
                    tmp_str+=' ';
                }
                tmp_str+=words[i];
                ans.push_back(tmp_str);
                
                pre_n=0;
                left_size=maxWidth;
                
            }else{
                //  <
                if(pre_n==1){
                    string tmp_str=words[i-1];
                    while(tmp_str.size()<maxWidth){
                        tmp_str+=' ';
                    }
                    ans.push_back(tmp_str);
                    
                    pre_n=1;
                    left_size=maxWidth-words[i].size();
                    continue;
                    
                }
                
                int shang=left_size/(pre_n-1);
                //how many empty each one
                int yushu=left_size%(pre_n-1);
                //how many one can get the most  (shang+1)
                
                string tmp_str;
                for(int j=pre_n;j>1;j--){
                    tmp_str+=words[i-j];
                    for(int k=0;k<shang;k++){
                        tmp_str+=' ';
                    }
                    if(yushu>0){
                        tmp_str+=' ';
                        yushu--;
                    }
                }
                
                tmp_str+=words[i-1];
                ans.push_back(tmp_str);
                
                //  words[i]  to deal with
                
                pre_n=1;
                left_size=maxWidth-words[i].size();
                
            }
        }
        
        if(pre_n==0) return ans;
        else{
            string tmp_str;
            for(int j=pre_n;j>1;j--){
                tmp_str+=words[i-j];
                tmp_str+=' ';
            }
            tmp_str+=words[i-1];
            while(tmp_str.size()<maxWidth){
                tmp_str+=' ';
            }
            ans.push_back(tmp_str);
            return ans;
        }
    }
};
