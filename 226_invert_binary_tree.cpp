//
//  226_invert_binary_tree.cpp
//  test
//
//  Created by ley on 2020/4/22.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        inv2(root);
        return root;
    }
private:
    void inv2(TreeNode*root){
        if(!root) return;
        TreeNode* l=root->left;
        TreeNode* r=root->right;
        
        root->left=r;
        root->right=l;
        inv2(root->left);
        inv2(root->right);
    }
};
