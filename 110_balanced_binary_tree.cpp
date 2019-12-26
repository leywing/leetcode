//
//  110_balanced_binary_tree.cpp
//  test
//
//  Created by ley on 2019/12/26.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
       
        if(root==nullptr) return true;
        int zuo=is2(root->left);
        int you=is2(root->right);
        if(zuo==-1||you==-1) return false;
        else if(you-zuo<2&&zuo-you<2){
            return true;
        }else{
            return false;
        }
    }
    
    int is2(TreeNode* root){
        if(root==nullptr) return 0;
        int zuo=is2(root->left);
        int you=is2(root->right);
        if(zuo==-1||you==-1) return -1;
        else if(you-zuo<2&&zuo-you<2){
            return you>zuo?you+1:zuo+1;
        }else{
            return -1;
        }
    }
    
    
};
