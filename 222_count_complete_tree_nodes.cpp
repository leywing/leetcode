//
//  222_count_complete_tree_nodes.cpp
//  test
//
//  Created by ley on 2020/4/22.
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* l=root;
        TreeNode* r=root;
        int hl=0;
        int hr=0;
        while (l) {
            hl++;
            l=l->left;
        }
        while (r) {
            hr++;
            r=r->right;
        }
        
        if(hr==hl) return pow(2,hr)-1;//1:1  2:3  3:7  4:15
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};


//by myself easy
//class Solution {
//public:
//    int countNodes(TreeNode* root) {
//        ans=0;
//        cou2(root);
//        return ans;
//    }
//private:
//    int ans=0;
//    void cou2(TreeNode* root){
//        if(root==nullptr) return;
//        ans++;
//        cou2(root->left);
//        cou2(root->right);
//    }
//};
