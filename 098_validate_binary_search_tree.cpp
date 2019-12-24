//
//  098_validate_binary_search_tree.cpp
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
    
    //这道题想了想，可以中序遍历，然后建个堆，当放堆的数，小于top(),则false
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        ans=inorderTraversal(root);
        for(int i=0;i<ans.size();i++){
            if(i==0) continue;
            else if(ans[i]>ans[i-1]) continue;
            else return false;
        }
        
        return true;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root==nullptr) return ans;
        st.push(root);
        
        while(st.size()!=0){
            
            
            if(st.top()->left!=nullptr){
                st.push(st.top()->left);
            }else{
                ans.push_back(st.top()->val);
                if(st.top()->right!=nullptr){
                    st.push(st.top()->right);
                }else{
                    //no right   no left
                    st.pop();
                    if(st.size()!=0){
                        if(st.top()->left!=nullptr) st.top()->left=nullptr;
                        else{
                            while(st.size()>0&&st.top()->left==nullptr){
                                st.pop();
                            }
                            if(st.size()==0) break;
                            st.top()->left=nullptr;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
