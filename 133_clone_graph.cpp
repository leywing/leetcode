//
//  133_clone_graph.cpp
//  test
//
//  Created by ley on 2020/1/22.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//class Node {
//public:
//    int val;
//    vector<Node*> neighbors;
//
//    Node() {}
//
//    Node(int _val, vector<Node*> _neighbors) {
//        val = _val;
//        neighbors = _neighbors;
//    }
//};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        Node* head=new Node(1,vector<Node*> ());
        vector<Node*> ley_node;
        vector<int> ley_signal={0};
        ley_node.push_back(head);
        clo2(head,node,ley_node,ley_signal);
        
        return head;
    }
    
    void clo2(Node* copy,Node* father,vector<Node*>& ley_node,vector<int>& ley_signal){
        int n=father->neighbors.size();
        if(n==0){
            return;
        }
        //if(ley_signal.size()>=copy->val-1){
        //    if(ley_signal[copy->val-1]==1) return;//have finish     minus 1
        //}//这个可以在进入前判断了就行吧，就不用又开个函数
        
        int tmp_size=ley_node.size();
        for(int i=0;i<n;i++){
            if(father->neighbors[i]->val>tmp_size){
                //the node not seen before
                for(int t=tmp_size+1;t<=father->neighbors[i]->val;t++){
                    Node* tmp_node=new Node(t,vector<Node*> ());
                    ley_signal.push_back(0);
                    ley_node.push_back(tmp_node);
                }
                tmp_size=father->neighbors[i]->val;
            }
            //--------
            copy->neighbors.push_back(ley_node[father->neighbors[i]->val-1]);// minus 1
        }
        
        ley_signal[copy->val-1]=1;
        
        for(int i=0;i<n;i++){
            if(ley_signal[copy->neighbors[i]->val-1]==0){
                clo2(copy->neighbors[i], father->neighbors[i], ley_node, ley_signal);
            }
        }
    }
};
