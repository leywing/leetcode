//
//  236_lowest_common_ancestor_of_a_binary_tree.cpp
//  test
//
//  Created by ley on 2020/4/24.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a=p->val;
        int b=q->val;
        bool a_found=false;
        bool b_found=false;
        TreeNode* ans=nullptr;
        low3(root, a, b, a_found, b_found,ans);
        return ans;
    }
private:
    void low3(TreeNode* root,int& a,int& b,bool& a_found,bool& b_found,TreeNode* &ans){
        if(root==nullptr) return ;
        
        bool tmp_a_f=false,tmp_b_f=false;
        low3(root->left, a, b, tmp_a_f, tmp_b_f, ans);
        if(tmp_a_f&&tmp_b_f) return;
        
        bool tmp1_a_f=false,tmp1_b_f=false;
        low3(root->right, a, b, tmp1_a_f, tmp1_b_f, ans);
        if(tmp1_a_f&&tmp1_b_f) return;
        
        if(a==root->val) a_found=true;
        if(b==root->val) b_found=true;
        
        a_found=a_found||tmp_a_f||tmp1_a_f;
        b_found=b_found||tmp_b_f||tmp1_b_f;
        
        if(a_found&&b_found){
            ans=root;
        }
        
    }
};
