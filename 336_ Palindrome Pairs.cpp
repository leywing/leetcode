//
//  336_ Palindrome Pairs.cpp
//  test
//
//  Created by ley on 2020/6/10.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//jave solution all use Trie Tree
//but is complex. I don't think I can write it out....

//really fast   O(n* k^2) k averge length of words
//others' solution using unordered_map
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> dict;
        int num_w=words.size();
        
        for(int i=0;i<num_w;i++){
            dict[words[i]]=i;
        }
        
        for(int i=0;i<num_w;i++){
            for(int j=0;j<=words[i].size();j++){
                //check suffix word
                //   ab + " palindrome  " +   ba(other word)
                //  include   "palindrome "  + ""
                if(ispalindrome(words[i], j, words[i].size()-1)){
                    string suffix=words[i].substr(0,j);
                    reverse(suffix.begin(), suffix.end());
                    if(dict.find(suffix)!=dict.end() && dict[suffix]!=i){
                        ans.push_back({i,dict[suffix]});
                    }
                }
                //check prefix word
                //  ab(other word)+"palindrome"+ba
                
                
                //if without  j>0   means   prefix can    (other word)+" palindrom [i]"
                //while in suffix  there every i have a op to be in the first
                //if j==0 will apear twotimes  [1,0]
                //for example   "ab"  "ba"
                //in the "ab" round      [0,1] [1,0]                            //with j>0      "ab" round     [0,1]
                //in the "ba" round      [1,0] [0,1]   is wrong                 //              "ba" round     [1,0]
                if(j>0 && ispalindrome(words[i], 0, j-1)){
                    string prefix=words[i].substr(j);
                    reverse(prefix.begin(), prefix.end());
                    if(dict.find(prefix)!=dict.end() && dict[prefix]!=i){
                        ans.push_back({dict[prefix],i});
                    }
                    
                    
                }
                
            }
        }
        return ans;
    }
private:
    bool ispalindrome(string& s,int start,int end){
        while(start<end){
            if(s[start]==s[end]){
                start++;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }
};

////time limit exceeded.......... hahahahaha i knew it
//class Solution {
//public:
//    vector<vector<int>> palindromePairs(vector<string>& words) {
//        int num_w=words.size();
//        vector<vector<int>> ans;
//        for(int i=0;i<num_w;i++){
//            for(int j=i+1;j<num_w;j++){
//                string tmp_s=words[i]+words[j];     //i+j
//                if(ispalindrome(tmp_s)){
//                    vector<int> tmp={i,j};
//                    ans.push_back(tmp);
//                    if(words[i].size()==words[j].size()){
//                        vector<int> tmp2={j,i};
//                        ans.push_back(tmp2);
//                        continue;
//                    }
//                }
//
//                tmp_s=words[j]+words[i];            //j+i
//                if(ispalindrome(tmp_s)){
//                    vector<int> tmp{j,i};
//                    ans.push_back(tmp);
//                }
//
//            }
//        }
//        return ans;
//
//    }
//private:
//    bool ispalindrome(string s){
//        int len=s.size();
//        int i=0,j=len-1;
//        while(i<j){
//            if(s[i]==s[j]){
//                i++;j--;
//            }else{
//                return false;
//            }
//        }
//        return true;
//    }
//};
