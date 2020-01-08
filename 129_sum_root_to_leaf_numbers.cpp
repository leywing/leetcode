//
//  129_sum_root_to_leaf_numbers.cpp
//  test
//
//  Created by ley on 2020/1/9.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int ans=0;
    int sumNumbers(TreeNode* root) {
        if(root==nullptr) return 0;
        sum2(root, 0);
        return ans;
    }
    
    void sum2(TreeNode* root,int tmp_num){
        if(root->left==nullptr&&root->right==nullptr){
            tmp_num=tmp_num*10+root->val;
            ans+=tmp_num;
        }else if(root->left==nullptr){
            tmp_num=tmp_num*10+root->val;
            sum2(root->right, tmp_num);
        }else if(root->right==nullptr){
            tmp_num=tmp_num*10+root->val;
            sum2(root->left, tmp_num);
        }else{
            tmp_num=tmp_num*10+root->val;
            sum2(root->left, tmp_num);
            sum2(root->right, tmp_num);
        }
    }
};
