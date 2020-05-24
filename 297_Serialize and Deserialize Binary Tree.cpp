//
//  297_Serialize and Deserialize Binary Tree.cpp
//  test
//
//  Created by ley on 2020/5/22.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//others  from discussion
//stringstream

//getline(sstream,string,',');      awesome!!!!!    stringstream
//stringstream  ss;   ss<<"123"<<" "<<"235";
//int b;
//ss>>b;
//cout<<b<<"#";
//ss>>b;
//cout<<b;

//123#235


class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr){
            return "#";
        }else{
            return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#") return nullptr;
        stringstream s(data);       //#include <sstream>
        return des2(s);
    }
    
    TreeNode* des2(stringstream& data){
        string str;
        getline(data, str, ',');
        if(str=="#"){
            return nullptr;
        }else{
            TreeNode* root=new TreeNode(stoi(str));
            root->left=des2(data);
            root->right=des2(data);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// //time limit exceed ......... so sad.............
//class Codec {
//public:
//
//    // Encodes a tree to a single string.
//    string serialize(TreeNode* root) {
//        //遍历
//        string ans;
//        if(root==nullptr){
//            ans="n";
//            return ans;
//        }
//        ans=to_string(root->val);
//        ser2(root, ans);
//        return ans;
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode* deserialize(string data) {
//        stack<TreeNode*> st;
//        queue<TreeNode*> da;
//        des1(da, data);
//
//        TreeNode* fa;
//        TreeNode* ans;
//        if(da.front()==nullptr){
//            return nullptr;
//        }else{
//            fa=da.front();
//            ans=fa;
//            da.pop();
//        }
//        while(fa!=nullptr||(!st.empty())){
//            if(fa==nullptr){
//                fa=st.top();
//                st.pop();
//                continue;
//            }
//            TreeNode* le=da.front();
//            da.pop();
//            TreeNode* rg=da.front();
//            da.pop();
//            fa->left=le;
//            fa->right=rg;
//
//            if(le==nullptr && rg==nullptr){
//                fa=nullptr;
//            }else if(le==nullptr){
//                fa=rg;
//            }else if(rg==nullptr){
//                fa=le;
//            }else{
//                //  le  rg   not nullptr
//                fa=le;
//                st.push(rg);
//            }
//
//        }
//
//        return  ans;
//
//    }
//private:
//    void des1(queue<TreeNode*>& da, string data){
//        int len=data.size();
//        int i=0;
//        string tmp="";
//        bool flag=false;
//        while(i<len){
//            if(data[i]==','){
//                if(flag){
//                    int t1=stoi(tmp);
//                    TreeNode* tt=new TreeNode(t1);
//                    da.push(tt);
//                    tmp="";
//                    flag=false;
//                }
//            }else if (data[i]=='n'){
//                da.push(nullptr);
//            }else{
//                tmp=tmp+data[i];
//                flag=true;
//            }
//            i++;
//        }
//        if(flag){
//            int t1=stoi(tmp);
//            TreeNode* tt=new TreeNode(t1);
//            da.push(tt);
//            flag=false;
//        }
//    }
//
//    void ser2(TreeNode* root,string& a){
//        if(root==nullptr){
//            return;
//        }
//
//        if(root->left==nullptr){
//            a=a+","+"n";
//        }else{
//            a=a+","+to_string(root->left->val);
//        }
//
//        if(root->right==nullptr){
//            a=a+","+"n";
//        }else{
//            a=a+","+to_string(root->right->val);
//        }
//
//        ser2(root->left, a);
//        ser2(root->right, a);
//    }
//};
//
//// Your Codec object will be instantiated and called as such:
//// Codec codec;
//// codec.deserialize(codec.serialize(root));
