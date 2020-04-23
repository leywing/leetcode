//
//  230_kth_smallest_element_in_a_bst.cpp
//  test
//
//  Created by ley on 2020/4/24.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//easy

//follow up:
//What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
//那。最快。。。。就 遍历BST，弄个数组出来呗
//不能增加数据结构的话。。。。 想了想，不行啊，你增加删除，就会修改当前结构啊。没法通过移动指针来弄吧？还是可以？ 算了不想了。。。


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int temp=0;
        int ans;
        kth2(root, temp, k,ans);
        return ans;
    }
    
private:
    void kth2(TreeNode* root ,int& t,int& target,int& ans){
        if(!root) return ;
        
        kth2(root->left, t, target, ans);
        if(t==target) return;
        t++;
        if(t==target){
            ans=root->val;
            return;
        }
        kth2(root->right, t, target, ans);
        if(t==target) return;
    }
};


