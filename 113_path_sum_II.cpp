//
//  113_path_sum_II.cpp
//  test
//
//  Created by ley on 2019/12/28.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==nullptr){
            return ans;
        }
        vector<int> tmp_vector;
        traverse(root, 0, sum,tmp_vector);
        return ans;
    }
    
    void traverse(TreeNode* root,int tmp_sum,int target,vector<int>& tmp_vector){
        if(root==nullptr) return;
        
        tmp_sum+=root->val;
        tmp_vector.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr){
            if(tmp_sum==target){
                ans.push_back(tmp_vector);
            }
            tmp_vector.pop_back();
            return;
        }
        
        traverse(root->left, tmp_sum, target,tmp_vector);
        traverse(root->right, tmp_sum, target,tmp_vector);
        tmp_vector.pop_back();
    }
};
