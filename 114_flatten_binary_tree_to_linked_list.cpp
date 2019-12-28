//
//  114_flatten_binary_tree_to_linked_list.cpp
//  test
//
//  Created by ley on 2019/12/28.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    TreeNode* tmp;
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        tmp=root;
        TreeNode* tmp1=root->left;
        TreeNode* tmp2=root->right;
        traverse(tmp1);
        traverse(tmp2);
    }
    
    void traverse(TreeNode* root){
        if(root==nullptr) return;
        tmp->right=root;
        tmp->left=nullptr;
        tmp=root;
        TreeNode* tmp1=root->left;
        TreeNode* tmp2=root->right;
        traverse(tmp1);
        traverse(tmp2);
    }
};
