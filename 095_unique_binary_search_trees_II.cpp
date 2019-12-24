//
//  095_unique_binary_search_trees_II.cpp
//  test
//
//  Created by ley on 2019/12/22.
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(n==0) return ans;
        return gen2(1,n);
    }
    
    vector<TreeNode*> gen2(int start,int end){
        vector<TreeNode*> ans;
        if(start>end){
            ans.push_back(nullptr);
            return ans;
        }
        if(start==end){
            TreeNode* a=new TreeNode(start);
            ans.push_back(a);
            //注意
            //这里我之前写的是。  TreeNode a(start);  ans.push_back(&a);
            //  error!!!! 因为这个括弧结束 a就被回收了啊，所以不行。得用new！！！！！！
            
            //ans.push_back(new TreeNode(start));
            return ans;
        }
        
        vector<TreeNode*> lnode,rnode;
        for(int i=start;i<=end;i++){
            lnode=gen2(start,i-1);
            rnode=gen2(i+1,end);
        
            for(auto l:lnode){
                for(auto r:rnode){
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
