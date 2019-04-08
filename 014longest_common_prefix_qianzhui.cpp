//
//  014longest_common_prefix_qianzhui.cpp
//  test
//
//  Created by ley on 2019/4/3.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        unsigned long words=strs.size();
        if(words==0) return "";
        unsigned long length=0;
        for(int i=0;i<words;i++){
            length=length>strs[i].size()?length:strs[i].size();
        }
        int sign=0;
        for(int i=0;i<length;i++){
            char temp=strs[0][i];
            for(int j=0;j<words;j++){
                if(strs[j][i]==temp) continue;
                else {
                    sign=1;
                    break;
                }
            }
            if(sign==1) break;
            else ans=ans+temp;
                
        }
        
        
        return ans;
    }
};


int main(){
    cout<<endl<<"ley"<<endl;
    vector<string> ab={"dog","racecar","car"};
    Solution aa;
    cout<<aa.longestCommonPrefix(ab);
    
   
    
    
    cout<<endl;
    
    return 0;
}
