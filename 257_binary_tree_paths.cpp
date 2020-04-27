//
//  257_binary_tree_paths.cpp
//  test
//
//  Created by ley on 2020/4/28.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root!=nullptr){
            string tmp="";
            bin2(root, ans,tmp);
        }
        return ans;
    }
private:
    void bin2(TreeNode* root,vector<string>& ans,string tmp){
        if(root==nullptr) return;
        
        if(tmp.size()==0){
            tmp=to_string(root->val);
        }else{
            tmp=tmp+"->"+to_string(root->val);
        }
        
        if(root->left==nullptr&&root->right==nullptr){
            ans.push_back(tmp);
            return;
        }else{
            bin2(root->left, ans, tmp);
            bin2(root->right, ans, tmp);
        }
        
        
    }
};
