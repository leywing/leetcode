//
//  112_path_sum.cpp
//  test
//
//  Created by ley on 2019/12/28.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    bool ans=false;
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr){
            return false;
        }
        traverse(root, 0, sum);
        return ans;
    }
    
    void traverse(TreeNode* root,int tmp_sum,int target){
        if(ans==true) return;
        if(root==nullptr) return;
        
        tmp_sum+=root->val;
        
        if(root->left==nullptr&&root->right==nullptr){
            if(tmp_sum==target) ans=true;
            return;
        }
        
        traverse(root->left, tmp_sum, target);
        traverse(root->right, tmp_sum, target);
        }
};
