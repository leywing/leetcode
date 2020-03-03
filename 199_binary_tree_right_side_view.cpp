//
//  199_binary_tree_right_side_view.cpp
//  test
//
//  Created by ley on 2020/3/3.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> a;
        rig2(root, 1, a);
        return a;
    }
private:
    void rig2(TreeNode* root,int n,vector<int>& a){
        if(root==nullptr) return;
        
        if(n>a.size()) a.push_back(0);
        rig2(root->left, n+1, a);
        a[n-1]=root->val;
        rig2(root->right, n+1, a);
    }
};
