//
//  307_ Range Sum Query _ Mutable.cpp
//  test
//
//  Created by ley on 2020/5/27.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//see the discussion
struct SegmentTreeNode{
    int s,e,sum;
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    SegmentTreeNode(int _s,int _e):s(_s),e(_e),sum(0),left(nullptr),right(nullptr){}
};

class SegmentTree{
public:
    SegmentTree(vector<int>& nums){
        int e=nums.size()-1;
        root=buildST(nums,0,e);
    }
    
    void update(int i,int val){
        update(root,i, val); //重载
    }
    
    int sumRange(int i,int j){
        return sumRange(root,i, j);
    }
    
    
private:
    SegmentTreeNode* root;
    SegmentTreeNode* buildST(vector<int>& nums,int s,int e){
        if(s>e){
            return nullptr;
        }else{
            //s<=e
            SegmentTreeNode* tmpNode=new SegmentTreeNode(s,e);
            if(s==e){
                tmpNode->sum=nums[s];
            }else{
                int mid=(e-s)/2+s;
                tmpNode->left=buildST(nums, s, mid);
                tmpNode->right=buildST(nums, mid+1, e);
                tmpNode->sum=tmpNode->left->sum+tmpNode->right->sum;
            }
            return tmpNode;
        }
        
    }
    
    void update(SegmentTreeNode* root,int i,int val){
        if(root->s==root->e){
            root->sum=val;
        }else{
            int mid=(root->e-root->s)/2+root->s;
            if(i<=mid){
                //left    s   mid
                //right   mid+1   e
                update(root->left, i,val);
            }else{
                update(root->right, i,val);
            }
            root->sum=root->left->sum+root->right->sum;
        }
    }
    
    int sumRange(SegmentTreeNode* root,int s,int e){
        if(root->s==s && root->e==e){
            return root->sum;
        }else{
            int mid=(root->e-root->s)/2+root->s;
            if(s>=mid+1){
                return sumRange(root->right, s,e);
            }else if(e<=mid){
                return sumRange(root->left, s,e);
            }else{
                return sumRange(root->left, s,mid)+sumRange(root->right, mid+1,e);
            }
        }
    }
    
};



class NumArray {
public:
    NumArray(vector<int>& nums) {
        tre=new SegmentTree(nums);
    }
    
    void update(int i, int val) {
        tre->update(i, val);
    }
    
    int sumRange(int i, int j) {
        return tre->sumRange(i, j);
    }
private:
    SegmentTree* tre;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

//see the discussion, should use segement TREE

//too slow !!!!
//class NumArray {
//public:
//    NumArray(vector<int>& nums) {
//        nn=&nums;
//        long tmp=0;
//        len=nums.size();
//        sum.push_back(0);
//        for(int i=0;i<len;i++){
//            tmp+=nn->at(i);
//            sum.push_back(tmp);
//        }
//    }
//    
//    void update(int i, int val) {
//        int old_value=nn->at(i);
//        int del=old_value-val;
//        for(int t=i+1;t<=len;t++){
//            sum[t]=sum[t]-del;
//        }
//        nn->at(i)=val;
//    }
//
//    int sumRange(int i, int j) {
//        return sum[j+1]-sum[i];
//    }
//private:
//    int len;
//    vector<int>* nn;
//    vector<long> sum;
//};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
