//
//  108_convert_sorted_array_to_binary_search_tree.cpp
//  test
//
//  Created by ley on 2019/12/25.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return nullptr;
        return sor2(nums, 0, n-1);
    }
    
    TreeNode* sor2(vector<int>& nums,int start,int end){
        if(start>end) return nullptr;
        else if(end==start){
            TreeNode* root=new TreeNode(nums[start]);
            return root;
        }else if(end-start==1){
            TreeNode* root=new TreeNode(nums[end]);
            root->left=new TreeNode(nums[start]);
            return root;
        }else if(end-start==2){
            TreeNode* root=new TreeNode(nums[start+1]);
            root->left=new TreeNode(nums[start]);
            root->right=new TreeNode(nums[end]);
            return root;
        }else{
            //>2,more than 4numbers
            int mid=start+(end-start)/2;
            TreeNode* root=new TreeNode(nums[mid]);
            root->left=sor2(nums, start, mid-1);
            root->right=sor2(nums, mid+1, end);
            return root;
        }
        
    }
};
