//
//  211_add and search word_data strucure design.cpp
//  test
//
//  Created by ley on 2020/3/30.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//by myself      summit in leetcode-cn......because the leetcode.com can't not open?20200331
class wordNode{
public:
    wordNode* c[26];
    bool isWord;
    wordNode():isWord(false){
        for(auto& a:c){
            a=nullptr;
        }
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new wordNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        lengthmax=lengthmax>word.size()?lengthmax:word.size();
        wordNode* tmp=root;
        for(auto& a:word){
            int n=a-'a';
            if(!tmp->c[n]){
                //not exit
                tmp->c[n]=new wordNode;
            }
            tmp=tmp->c[n];
        }
        tmp->isWord=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(word.size()>lengthmax) return false;
        return sear2(root, word, 0);
    }
private:
    wordNode* root;
    int lengthmax=0;
    bool sear2(wordNode* tmp,string& word,int i){
        for(int j=i;j<word.size();j++){
            if(word[j]=='.'){
                for(int t=0;t<26;t++){
                    if(tmp->c[t]){
                        if(sear2(tmp->c[t], word, j+1)) return true;
                    }
                }
                return false;
            }
            int n=word[j]-'a';
            if(!tmp->c[n]) return false;
            tmp=tmp->c[n];
        }
        return tmp->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
