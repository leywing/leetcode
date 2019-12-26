//
//  111_minimum_depth_of_binary_tree.cpp
//  test
//
//  Created by ley on 2019/12/26.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int ans=INT_MAX;
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        traverse(root, 1);
        
        return ans;
    }
    
    void traverse(TreeNode* root,int i){
        if(root==nullptr) return;
        
        if(root->left==nullptr&&root->right==nullptr){
            ans=ans<i?ans:i;
        }else{
            traverse(root->left, i+1);
            traverse(root->right, i+1);
        }
    }
};
