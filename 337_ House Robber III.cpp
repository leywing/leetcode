//
//  337_ House Robber III.cpp
//  test
//
//  Created by ley on 2020/6/11.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//others' solution  ...... smart!!! use & ,i like it.
class Solution {
public:
    int rob(TreeNode* root) {
        int l=0,r=0;
        return helper(root, l, r);
    }
private:
    int helper(TreeNode* root,int& l,int& r){
        if(root==nullptr) return 0;
        int ll=0,lr=0,rl=0,rr=0;
        l=helper(root->left, ll, lr);
        r=helper(root->right, rl, rr);
        
        return max(root->val+ll+lr+rl+rr,l+r);
        
    }
};

////by myself   DP.  but seems too slow only beat 30%
//class Solution {
//public:
//    int rob(TreeNode* root) {
//        //  dp    爷爷+孙子。 和。 儿子。 之间的比较
//        if(root==nullptr) return 0;
//        if(u_map.find(root)!=u_map.end()){
//            return u_map[root];
//        }
//
//        int ye=root->val;
//        if(root->left!=nullptr){
//            ye+=rob(root->left->left)+rob(root->left->right);
//        }
//        if(root->right!=nullptr){
//            ye+=rob(root->right->left)+rob(root->right->right);
//        }
//
//        int fu=rob(root->left)+rob(root->right);
//        int ans=max(ye,fu);
//        u_map[root]=ans;
//        return ans;
//
//    }
//private:
//    unordered_map<TreeNode*, int> u_map;
//};
