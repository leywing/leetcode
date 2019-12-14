//
//  071_simplify_path.cpp
//  test
//
//  Created by ley on 2019/12/14.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        vector<string> aaa;
        int flag_string=0;
        string tmp="";
        for(int i=0;i<n;i++){
            if(flag_string==0){
                if(path[i]=='/') continue;
                else{
                    //path[i] ==  'a'
                    tmp=path[i];
                    flag_string=1;
                    continue;
                }
            }else{
                //flag_string==1
                if(path[i]=='/'){
                    flag_string=0;
                    if(tmp=="."){
                        tmp="";
                        continue;
                    }else if(tmp==".."){
                        if(aaa.size()>=1){
                            aaa.pop_back();
                            tmp="";
                        }
                        else tmp="";
                    }else{
                        tmp='/'+tmp;
                        aaa.push_back(tmp);
                        tmp="";
                    }
                    
                }else{
                    tmp+=path[i];
                }
            }
        }
        
        if(tmp!=""){
            if(tmp=="."){
                ;
            }else if(tmp==".."){
                if(aaa.size()>=1){
                    aaa.pop_back();
                }
            }else{
                tmp='/'+tmp;
                aaa.push_back(tmp);
            }
        }
        string ans="/";
        if(aaa.size()==0) return ans;
        ans="";
        for(int t=0;t<aaa.size();t++){
            ans=ans+aaa[t];
        }
        
        return ans;
    }
};
