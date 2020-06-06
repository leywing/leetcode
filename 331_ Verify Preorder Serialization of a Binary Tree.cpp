//
//  331_ Verify Preorder Serialization of a Binary Tree.cpp
//  test
//
//  Created by ley on 2020/6/7.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int res_count=1;
        int i=0;
        int len=preorder.size();
        if(len==0) return false;
        
        if(preorder[i]=='#'){
            if(len==1) return true;
            else return false;
        }
        while(i<len && preorder[i]!=','){
            i++;
        }
        if(i==len) return false;
        //from now each find two
        while(i<len && res_count>0){
            res_count--;
            
            i++;
            if(i>=len) return false;
            if(preorder[i]=='#'){
                i++;
            }else{
                while(i<len && preorder[i]!=',') i++;
                res_count++;
            }
            
            i++;
            if(i>=len) return false;
            if(preorder[i]=='#') i++;
            else{
                while(i<len && preorder[i]!=',') i++;
                res_count++;
            }
        }
        
        return (res_count==0 && i>=len);
    }

};
