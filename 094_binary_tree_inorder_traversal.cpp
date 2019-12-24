//
//  094_binary_tree_inorder_traversal.cpp
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






//Recursive       Success    .....so easy     中序遍历

//class Solution {
//public:
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> ans;
//        if(root==nullptr) return ans;
//        ino2(ans, root);
//
//        return ans;
//
//    }
//
//    void ino2(vector<int>& ans,TreeNode* root){
//        if(root->left!=nullptr){
//            ino2(ans, root->left);
//        }
//
//        ans.push_back(root->val);
//
//        if(root->right!=nullptr){
//            ino2(ans, root->right);
//        }
//
//    }
//};
