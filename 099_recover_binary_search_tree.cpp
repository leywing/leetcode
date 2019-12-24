//
//  099_recover_binary_search_tree.cpp
//  test
//
//  Created by ley on 2019/12/24.
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
    TreeNode* firstNode=nullptr;
    TreeNode* secondNode=nullptr;
    
    TreeNode* prevNode=new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        traverse(root);
        
        int tmp=firstNode->val;
        firstNode->val=secondNode->val;
        secondNode->val=tmp;
    }
    
    void traverse(TreeNode* root){
        if(root==nullptr) return;
        
        traverse(root->left);
        
        if(firstNode==nullptr&&prevNode->val>root->val){
            firstNode=prevNode;
        }
        if(firstNode!=nullptr&&prevNode->val>root->val){
            secondNode=root;
        }
        
        //二叉搜索树。每个数都不一样，所以>   以防例子里真有INT_MIN
        //注意第二个secondNode=root 找到后为什么不马上return
        //因为这个是立即的。比如。   1235467。 那么这样就找到了5，4
        //但是马上return，就无法找到后面出现的了
        //比如。 123 8 467 5 10
        
        
        prevNode=root;
        
        traverse(root->right);
    }
};
