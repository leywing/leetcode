//
//  103_binary_tree_zigzag_level_order_traversal.cpp
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return ans;
        
        traverse(root, 0);
        for(int i=0;i<ans.size();i++){
            if(i%2==1){
                reverse(ans[i].begin(), ans[i].end());
            }
        }
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
