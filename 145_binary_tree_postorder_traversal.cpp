//
//  145_binary_tree_postorder_traversal.cpp
//  test
//
//  Created by ley on 2020/2/8.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        posto2(root, ans);
        return ans;
    }
    void posto2(TreeNode* root,vector<int>& ans){
        if(root==nullptr) return;
        posto2(root->left, ans);
        posto2(root->right, ans);
        ans.push_back(root->val);
    }
};
