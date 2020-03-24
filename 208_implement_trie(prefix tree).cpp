//
//  208_implement_trie(prefix tree).cpp
//  test
//
//  Created by ley on 2020/3/24.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//others method     see it from submission
class TriNode{
public:
    TriNode* child[26];
    bool isword;
    TriNode():isword(false){
        for(auto &a:child){
            a=nullptr;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TriNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        length_max=word.size()>length_max?word.size():length_max;
        TriNode* tmp=root;
        for(auto &a:word){
            int n1=a-'a';
            if(!tmp->child[n1]) tmp->child[n1]=new TriNode;
            tmp=tmp->child[n1];
        }
        tmp->isword=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(word.size()>length_max) return false;
        TriNode* tmp=root;
        for(auto &a:word){
            int n1=a-'a';
            if(!tmp->child[n1]) return false;
            tmp=tmp->child[n1];
        }
        return tmp->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(prefix.size()>length_max) return false;
        TriNode* tmp=root;
        for(auto &a:prefix){
            int n1=a-'a';
            if(!tmp->child[n1]) return false;
            tmp=tmp->child[n1];
        }
        return true;
    }
private:
    TriNode* root;
    int length_max=0;
};



//still two slow    140ms  only pass 13.37%
//class Trie {
//public:
//    /** Initialize your data structure here. */
//    Trie() {
//
//    }
//
//    /** Inserts a word into the trie. */
//    void insert(string word) {
//        if(ley_set.find(word)==ley_set.end()){
//            ley_set.insert(word);
//            length_max=word.size()>length_max?word.size():length_max;
//            if(head.find(word[0])!=head.end()){
//                ListNode* tmp=head[word[0]];
//                for(int i=1;i<word.size();i++){
//                    if(tmp->next.find(word[i])!=tmp->next.end()){
//                        tmp=tmp->next[word[i]];
//                    }else{
//                        //not found
//                        tmp->next[word[i]]=new ListNode(word[i]);   //new listnode
//                        tmp=tmp->next[word[i]];
//                    }
//                }
//            }else{
//                //head not exit
//                head[word[0]]=new ListNode(word[0]);
//                ListNode* tmp=head[word[0]];
//                for(int i=1;i<word.size();i++){
//                    tmp->next[word[i]]=new ListNode(word[i]);   //new listnode
//                    tmp=tmp->next[word[i]];
//                }
//            }
//        }
//        //else already exit ,no need to operator
//    }
//
//    /** Returns if the word is in the trie. */
//    bool search(string word) {
//        if(ley_set.find(word)!=ley_set.end()) return true;
//        return false;
//    }
//
//    /** Returns if there is any word in the trie that starts with the given prefix. */
//    bool startsWith(string prefix) {
//        if(prefix.size()>length_max) return false;
//        if(ley_set.find(prefix)!=ley_set.end()) return true;
//        if(head.find(prefix[0])==head.end()){
//            return false;
//        }else{
//            //exit the first one
//            ListNode* tmp=head[prefix[0]];
//            for(int i=1;i<prefix.size();i++){
//                if(tmp->next.find(prefix[i])==tmp->next.end()){
//                    return false;
//                }else{
//                    tmp=tmp->next[prefix[i]];
//                }
//            }
//            return true;
//        }
//
//    }
//private:
//    struct ListNode {
//        char val;
//        unordered_map<char,ListNode*> next;
//        ListNode(int x) : val(x), next() {}
//    };
//    unordered_map<char,ListNode*> head;
//    unordered_set<string> ley_set;
//    int length_max=0;
//    //ley_vec.size()== the longest word.size()
//    //and the words are store in ley_vec[word.size()-1]
//
//};



////first try    speed only 5%........... hahahahaha
//class Trie {
//public:
//    /** Initialize your data structure here. */
//    Trie() {
//
//    }
//
//    /** Inserts a word into the trie. */
//    void insert(string word) {
//        if(ley_set.find(word)==ley_set.end()){
//            ley_set.insert(word);
//            if(word.size()>ley_vec.size()){
//                //for example   size()=0  word.size()=3
//                //size()=3, word.size()=5
//                for(int i=ley_vec.size();i<word.size();i++){
//                    ley_vec.push_back(vector<string>());
//                }
//            }
//            ley_vec[word.size()-1].push_back(word);
//        }
//        //else already exit ,no need to operator
//    }
//
//    /** Returns if the word is in the trie. */
//    bool search(string word) {
//        if(ley_set.find(word)!=ley_set.end()) return true;
//        return false;
//    }
//
//    /** Returns if there is any word in the trie that starts with the given prefix. */
//    bool startsWith(string prefix) {
//        if(prefix.size()>ley_vec.size()) return false;
//        if(ley_set.find(prefix)!=ley_set.end()) return true;
//        for(int i=prefix.size()-1;i<ley_vec.size();i++){
//            if(ley_vec[i].empty()) continue;
//            for(int j=0;j<ley_vec[i].size();j++){
//                if(ley_vec[i][j].substr(0,prefix.size())==prefix) return true;
//            }
//        }
//        return false;
//    }
//private:
//    unordered_set<string> ley_set;
//    vector<vector<string>> ley_vec;
//    //ley_vec.size()== the longest word.size()
//    //and the words are store in ley_vec[word.size()-1]
//
//};
//
///**
// * Your Trie object will be instantiated and called as such:
// * Trie* obj = new Trie();
// * obj->insert(word);
// * bool param_2 = obj->search(word);
// * bool param_3 = obj->startsWith(prefix);
// */
