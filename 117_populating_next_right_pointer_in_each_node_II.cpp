//
//  117_populating_next_right_pointer_in_each_node_II.cpp
//  test
//
//  Created by ley on 2019/12/29.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    
    //跟116一模一样。。。。
    vector<vector<Node*>> ley;
    Node* connect(Node* root) {
        if(root==nullptr) return nullptr;
        Node* ans=root;
        traverse(root, 0);
        return ans;
    }
    
    void traverse(Node* root,int level){
        if(root==nullptr) return ;
        if(ley.size()<level+1){
            for(int i=ley.size();i<level+1;i++){
                ley.push_back(vector<Node*>());
            }
        }
        
        if(ley[level].size()==0){
            ley[level].push_back(root);
        }else{
            ley[level].back()->next=root;
            ley[level].push_back(root);
        }
        
        traverse(root->left, level+1);
        traverse(root->right, level+1);
    }
};
