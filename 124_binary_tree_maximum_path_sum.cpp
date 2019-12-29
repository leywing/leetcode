//
//  124_binary_tree_maximum_path_sum.cpp
//  test
//
//  Created by ley on 2019/12/29.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return ans;
    }
    
    int traverse(TreeNode* root){
        if(root==nullptr) return 0;
        int lf=traverse(root->left);
        int rg=traverse(root->right);
        
        int tmp;
        tmp=root->val+(lf>0?lf:0)+(rg>0?rg:0);
        
        ans=tmp>ans?tmp:ans;
        
        lf+=root->val;
        rg+=root->val;
        if(lf>rg){
            return lf>0?lf:0;
        }else{
            //lf<=rg
            return rg>0?rg:0;
        }
        
    }
    
};
