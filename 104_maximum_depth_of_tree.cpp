//
//  104_maximum_depth_of_tree.cpp
//  test
//
//  Created by ley on 2019/12/25.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    int ans=0;
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return ans;
        
        traverse(root,1);
        
        return ans;
    }
    
    void traverse(TreeNode* root,int i){
        if(root==nullptr) return ;
        
        traverse(root->left, i+1);
        ans=ans>i?ans:i;
        traverse(root->right, i+1);
    }
    
};
