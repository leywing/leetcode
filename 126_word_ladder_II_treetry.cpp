//
//  126_word_ladder_II_treetry.cpp
//  test
//
//  Created by ley on 2020/1/3.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"


//still time limit exceeded.......
//oh my god......
//.........................
class Solution {
public:
    struct StreeNode {
        string val;
        StreeNode *parent;
        StreeNode(string x) : val(x), parent(NULL) {}
    };
    
    vector<vector<string>> ans;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        StreeNode* head=new StreeNode(beginWord);
        vector<string> tmp;
        int flag01=0;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==beginWord){
                continue;
            }else if(wordList[i]==endWord){
                flag01=1;
                tmp.push_back(wordList[i]);
            }else{
                tmp.push_back(wordList[i]);
            }
        }
        
        if(flag01==0) return ans;
        
        if(beginWord.size()==1){
            vector<string> tmp02;
            tmp02.push_back(beginWord);
            tmp02.push_back(endWord);
            ans.push_back(tmp02);
            return ans;
        }
        
        vector<StreeNode*> leaf;
        vector<StreeNode*> root;
        root.push_back(head);
        find2(root,tmp,leaf,endWord);
        
        return ans;
    
    }
    
    void find2(vector<StreeNode*>& root,vector<string>& tmp, vector<StreeNode*>& leaf,string endWord){
        if(tmp.size()==0) return;
        if(root.size()==0) return;
        leaf.clear();
        vector<StreeNode*> final_ans;
        
        vector<int> note(tmp.size(),0);
        
        for(int i=0;i<root.size();i++){
            //each root
            StreeNode* tmp_root=root[i];
            int n=tmp_root->val.size();
            for(int j=0;j<tmp.size();j++){
                for(int k=0;k<n;k++){
                    if(k==0){
                        if(tmp_root->val.substr(1)==tmp[j].substr(1)){
                            note[j]++;
                            StreeNode* tmp_SN=new StreeNode(tmp[j]);
                            tmp_SN->parent=tmp_root;
                            leaf.push_back(tmp_SN);
                            if(tmp[j]==endWord){
                                final_ans.push_back(tmp_SN);
                            }
                            break;
                        }
                    }else if(k==n-1){
                        if(tmp_root->val.substr(0,n-1)==tmp[j].substr(0,n-1)){
                            note[j]++;
                            StreeNode* tmp_SN=new StreeNode(tmp[j]);
                            tmp_SN->parent=tmp_root;
                            leaf.push_back(tmp_SN);
                            if(tmp[j]==endWord){
                                final_ans.push_back(tmp_SN);
                            }
                            break;
                        }
                    }else{
                        if((tmp_root->val.substr(0,k)==tmp[j].substr(0,k))&&(tmp_root->val.substr(k+1)==tmp[j].substr(k+1))){
                            note[j]++;
                            StreeNode* tmp_SN=new StreeNode(tmp[j]);
                            tmp_SN->parent=tmp_root;
                            leaf.push_back(tmp_SN);
                            if(tmp[j]==endWord){
                                final_ans.push_back(tmp_SN);
                            }
                            break;
                        }
                    }
                }
            }
        }
        
        if(final_ans.size()!=0){
            for(int i=0;i<final_ans.size();i++){
                vector<string> tmp_string;
                StreeNode* tmptmp=final_ans[i];
                while(tmptmp!=nullptr){
                    tmp_string.push_back(tmptmp->val);
                    tmptmp=tmptmp->parent;
                }
                reverse(tmp_string.begin(), tmp_string.end());
                ans.push_back(tmp_string);
            }
            return;
        }
        
        vector<string> tmpley=tmp;
        tmp.clear();
        for(int i=0;i<tmpley.size();i++){
            if(note[i]>0) continue;
            else{
                tmp.push_back(tmpley[i]);
            }
        }
        
        find2(leaf, tmp, root, endWord);
        
    }
    
    
};
