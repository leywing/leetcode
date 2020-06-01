//
//  318_ Maximum Product of Word Lengths.cpp
//  test
//
//  Created by ley on 2020/6/1.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"


//from the discussion
//!!! amazing   |   &
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size(),0);
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                mask[i]|=1<<words[i][j]-'a';
            }
            for(int k=0;k<i;k++){
                if( !(mask[i]&mask[k]) )
                    ans=ans> (words[i].size()*words[k].size())?ans:  (words[i].size()*words[k].size());
            }
        }
        return ans;
    }
};

//myself
//class Solution {
//public:
//    int maxProduct(vector<string>& words) {
//        int ans=0;
//        int len=words.size();
//
//        for(int i=0;i<len;i++){
//            int count[26]={0};
//            for(int j=0;j<words[i].size();j++){
//                count[words[i][j]-'a']++;
//            }
//            for(int k=i+1;k<len;k++){
//                for(int p=0;p<words[k].size();p++){
//                    if(count[words[k][p]-'a']>0){
//                        break;
//                    }
//                    if(p==words[k].size()-1){
//                        ans=ans>=( words[i].size()*words[k].size() )?ans:( words[i].size()*words[k].size() );
//                    }
//                }
//            }
//
//        }
//        return ans;
//    }
//};
