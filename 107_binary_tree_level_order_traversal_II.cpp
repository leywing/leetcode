//
//  107_binary_tree_level_order_traversal_II.cpp
//  test
//
//  Created by ley on 2019/12/25.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        traverse(root, 0);
        reverse(ans.begin(), ans.end());
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
