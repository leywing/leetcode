//
//  100_same_tree.cpp
//  test
//
//  Created by ley on 2019/12/25.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q==nullptr) return true;
        else if(p==nullptr||q==nullptr) return false;
        else{
            return traverse(p, q);
        }
    }
    
    bool traverse(TreeNode* p,TreeNode* q){
        if(p==nullptr&&q==nullptr) return true;
        else if(p==nullptr||q==nullptr) return false;
        else{
            bool tmp=traverse(p->left, q->left)&&traverse(p->right, q->right)&&p->val==q->val;
            return tmp;
        }
    }
};
