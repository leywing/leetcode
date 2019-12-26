//
//  105_construct_binary_tree_from_preorder_and_inorder_traversal.cpp
//  test
//
//  Created by ley on 2019/12/25.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    
    //other's method
    //!!!!!!!!
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return nullptr;
        
    
        return bui2(0, 0, inorder.size()-1, preorder, inorder);
 
    }
    
    TreeNode* bui2(int pre_i,int in_start,int in_end,vector<int>& preorder,vector<int>& inorder){
        if(pre_i>preorder.size()-1||in_start>in_end) return nullptr;
        
        TreeNode* root=new TreeNode(preorder[pre_i]);
        int index=0;
        for(int i=in_start;i<=in_end;i++){
            if(root->val==inorder[i]){
                index=i;
                break;
            }
        }
        
        root->left=bui2(pre_i+1, in_start, index-1, preorder, inorder);
        root->right=bui2(pre_i+index-in_start+1, index+1, in_end, preorder, inorder);
        return root;
    }
};
