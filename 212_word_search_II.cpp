//
//  212_word_search_II.cpp
//  test
//
//  Created by ley on 2020/3/30.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"


//watch the discussion,  they use trie
//use the words to build trie, and search (start from every point in the board)
//just beat 37% speed

//and i see a discussion who 44ms    and try to modify the code(37%)

//一个改动，速度提升了10倍，改了哪呢？
//就是改成了不传递 word,  而是找到 isword之后，根据idx去找word
class TriNode{
public:
    TriNode* child[26];
    bool isword;
    int idx;
    TriNode():isword(false),idx(0){
        for(auto &a:child){
            a=nullptr;
        }
        //fill_n(child[0],26,nullptr);
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie(vector<string>& words) {
        root=new TriNode;
        for(int i=0;i<words.size();i++){
            insert(words[i], i);
        }
    }

    TriNode* getRoot(){
        return root;
    }

    /** Inserts a word into the trie. */
    void insert(string word,int i) {
        TriNode* tmp=root;
        for(auto &a:word){
            int n1=a-'a';
            if(!tmp->child[n1]) tmp->child[n1]=new TriNode;
            tmp=tmp->child[n1];
        }
        tmp->isword=true;
        tmp->idx=i;
    }
private:
    TriNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* leyT=new Trie(words);
        TriNode* root=leyT->getRoot();
        vector<string> ans;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                fin2(i,j,board,root,ans,words);
            }
        }
       
        return ans;

    }
private:
    void fin2(int x,int y,vector<vector<char>>& board,TriNode* root,vector<string>& ans,vector<string>& words){
        if(x<0||y<0||x>=board.size()||y>=board[0].size()||board[x][y]==' ') return;

        if(root->child[board[x][y]-'a']!=nullptr){
            //exist this child
            root=root->child[board[x][y]-'a'];
            if(root->isword){
                ans.push_back(words[root->idx]);
                root->isword=false;
            }
            char c=board[x][y];
            board[x][y]=' ';
            fin2(x-1, y, board,  root, ans,words);
            fin2(x+1, y, board,  root, ans,words);
            fin2(x, y-1, board,  root, ans,words);
            fin2(x, y+1, board,  root, ans,words);
            board[x][y]=c;
        }

    }
};





//by myself too slow,speed only beat 12.88%
//class Solution {
//public:
//    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//        vector<string> ans;
//        int row=board.size();
//        if(row==0) return ans;
//        int col=board[0].size();
//        vector<vector<int>> note(row,vector<int>(col,INT_MAX));
//        //use to note which point have been walk through
//        vector<vector<pair<int,int>>> start(26,vector<pair<int,int>>());
//        for(int ri=0;ri<row;ri++){
//            for(int ci=0;ci<col;ci++){
//                pair<int,int> tmp(ri,ci);
//                int n=board[ri][ci]-'a';
//                start[n].push_back(tmp);
//            }
//        }//find all the start point
//
//        //asume the words.size() will not large than INT_MAX-1
//        for(int i=0;i<words.size();i++){    //check each word
//            int tmpn=words[i][0]-'a';
//            for(int j=0;j<start[tmpn].size();j++){
//                // this is the start point of words[i]  start[tmp][j]
//                note[start[tmpn][j].first][start[tmpn][j].second]=i;
//                if(fin2(start[tmpn][j].first,start[tmpn][j].second,board,note,1,words[i],row,col,i)){
//                    ans.push_back(words[i]);
//                    break;
//                }
//                note[start[tmpn][j].first][start[tmpn][j].second]=INT_MAX;
//            }
//        }
//
//        return ans;
//    }
//private:
//    bool fin2(int i,int j,vector<vector<char>>& board,vector<vector<int>>& note,int t,string& word,int& row,int& col,int k){
//        if(t==word.size()) return true;
//
//        //up
//        if(i-1>=0 && note[i-1][j]!=k && board[i-1][j]==word[t]){
//            note[i-1][j]=k;
//            if(fin2(i-1, j, board, note, t+1, word, row, col, k)) return true;
//            note[i-1][j]=INT_MAX;
//        }
//        //right
//        if(j+1<col && note[i][j+1]!=k && board[i][j+1]==word[t]){
//            note[i][j+1]=k;
//            if(fin2(i, j+1, board, note, t+1, word, row, col, k)) return true;
//            note[i][j+1]=INT_MAX;
//        }
//        //down
//        if(i+1<row && note[i+1][j]!=k && board[i+1][j]==word[t]){
//            note[i+1][j]=k;
//            if(fin2(i+1, j, board, note, t+1, word, row, col, k)) return true;
//            note[i+1][j]=INT_MAX;
//        }
//        //left
//        if(j-1>=0 && note[i][j-1]!=k && board[i][j-1]==word[t]){
//            note[i][j-1]=k;
//            if(fin2(i, j-1, board, note, t+1, word, row, col, k)) return true;
//            note[i][j-1]=INT_MAX;
//        }
//
//        return false;
//    }
//
//};
