//
//  235_lowest_common_ancestor_of_a_binary_search_tree.cpp
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

//BST easy
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        int a,b;
        a=p->val<q->val?p->val:q->val;
        b=p->val>q->val?p->val:q->val;
        low2(root, a, b, ans);
        return ans;
    }
private:
    void low2(TreeNode* root,int& x,int& y,TreeNode* &ans){
        if(root==nullptr) return;
        if(root->val>=x){
            if(root->val<=y){
                ans=root;
                return;
            }else{
                //root->val >y
                low2(root->left, x, y, ans);
            }
        }else{
            //root->val<x
            low2(root->right, x, y, ans);
        }
    }
};
