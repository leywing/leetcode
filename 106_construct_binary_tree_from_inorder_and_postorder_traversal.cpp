//
//  106_construct_binary_tree_from_inorder_and_postorder_traversal.cpp
//  test
//
//  Created by ley on 2019/12/25.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0) return nullptr;
        
        
        return bui2(postorder.size()-1, 0, inorder.size()-1, postorder, inorder);
    }
    
    TreeNode* bui2(int post_i,int in_start,int in_end,vector<int>& postorder,vector<int>& inorder){
        if(post_i<0||in_start>in_end) return nullptr;
        
        TreeNode* root=new TreeNode(postorder[post_i]);
        int index=0;
        for(int i=in_start;i<=in_end;i++){
            if(root->val==inorder[i]){
                index=i;
                break;
            }
        }
        
        root->left=bui2(post_i-1-(in_end-index), in_start, index-1, postorder, inorder);
        root->right=bui2(post_i-1, index+1, in_end, postorder, inorder);
        return root;
    }
};
