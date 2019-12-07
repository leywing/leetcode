//
//  049_group_anagrams.cpp
//  test
//
//  Created by ley on 2019/12/7.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    //good job , myself solution beat 90%
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        //auto copy=strs;
        int n=strs.size();
        
        unordered_map<string, int> a;
        int col=0;
        
        for(int i=0;i<n;i++){
            string tmp_s=strs[i];
            sort(strs[i].begin(),strs[i].end());
            if(a.find(strs[i])==a.end()) {
                a[strs[i]]=col;
                col++;
                vector<string> temp_vs;
                temp_vs.push_back(tmp_s);
                ans.push_back(temp_vs);
                
            }else{
                //found
                int tmp_int=a[strs[i]];
                ans[tmp_int].push_back(tmp_s);
            }
            
        }
        
        
        
        return ans;
    }
};


int main(){
    cout<<"please cin"<<endl;
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    cout<<s;
    
    return 0;
}
