//
//  173_binary_search_tree_iterator.cpp
//  test
//
//  Created by ley on 2020/2/29.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//others solution
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        findLeft(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* pp=st.top();
        st.pop();
        if(pp->right!=nullptr){
            findLeft(pp->right);
        }
        return pp->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(st.empty()) return false;
        return true;
    }
private:
    stack<TreeNode*> st;
    void findLeft(TreeNode* root){
        TreeNode* p=root;
        while(p!=nullptr){
            st.push(p);
            p=p->left;
        }
    }
};




//我的方法太蠢了。。。。。但是也只用了24.7MB,看大部分人用的空间都是这么大？？？？？。速度上肯定很快
//class BSTIterator {
//public:
//    BSTIterator(TreeNode* root) {
//        diedai(root);
//        n=nums.size();
//    }
//
//    /** @return the next smallest number */
//    int next() {
//        i++;
//        return nums[i-1];
//    }
//
//    /** @return whether we have a next smallest number */
//    bool hasNext() {
//        if(i<n) return true;
//        else return false;
//    }
//private:
//    vector<int> nums;
//    int n;
//    int i=0;
//    void diedai(TreeNode* root){
//        if(root==nullptr) return;
//
//        diedai(root->left);
//        //next();
//        //hasNext();
//        nums.push_back(root->val);
//        diedai(root->right);
//    }
//};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
