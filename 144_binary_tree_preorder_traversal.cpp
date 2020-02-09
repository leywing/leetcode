//
//  144_binary_tree_preorder_traversal.cpp
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preo2(ans,root);
        return ans;
    }
    
    void preo2(vector<int>& ans,TreeNode* root){
        if(root==nullptr) return;
        ans.push_back(root->val);
        preo2(ans, root->left);
        preo2(ans, root->right);
    }
};
