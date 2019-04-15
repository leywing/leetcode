//
//  022_generate_parentheses.cpp
//  test
//
//  Created by ley on 2019/4/15.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //想不出来，又去看了别人的答案
        vector<string> ans;
        add_s(ans,"",n,n);
        return ans;
    }
    void add_s(vector<string>& s,string v,int left,int right){
        if(left==0&&right==0){
            s.push_back(v);
        }else{
            if(left>0) {add_s(s, v+'(', left-1, right);}
            if(right>0&&right>left) {add_s(s, v+')', left, right-1);}
        }//真的很厉害，这样，不就遍历了所有可能情况，学起来
    }
};

int main(){
    cout<<endl<<endl;
    Solution aaa;
    vector<string> aab;
    aab=aaa.generateParenthesis(3);
    for(int i=0;i<aab.size();i++){
        cout<<aab[i]<<endl;
    }
    
    return 0;
    
}
