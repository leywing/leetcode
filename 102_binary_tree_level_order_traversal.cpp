//
//  102_binary_tree_level_order_traversal.cpp
//  test
//
//  Created by ley on 2019/12/25.
//  Copyright © 2019 ley. All rights reserved.
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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        traverse(root, 0);
        
        return ans;
    }
    
    void traverse(TreeNode* root,int i){
        if(root==nullptr) return;
        
        traverse(root->left, i+1);
        
        
        while(ans.size()<i+1){
            vector<int> tmp;
            ans.push_back(tmp);
        }
        
        ans[i].push_back(root->val);
        
        traverse(root->right, i+1);
    }
};
