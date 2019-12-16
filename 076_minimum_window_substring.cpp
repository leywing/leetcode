//
//  076_minimum_window_substring.cpp
//  test
//
//  Created by ley on 2019/12/15.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    
    
    //timer limited exceeded
    //超时。。。。。。
    //唉，我以为我这个方法已经够快了。。。。可惜啊
    string minWindow(string s, string t) {
        unordered_map<char, int> count_map;
        unordered_map<char, vector<int>> map;
        int ns=s.size();
        int nt=t.size();
        if(ns==0||nt==0) return "";
        if(ns<nt) return "";
        
        for(int i=0;i<nt;i++){
            count_map[t[i]]++;
        }
        //!!!!!
        for(auto i=count_map.begin();i!=count_map.end();i++){
            vector<int> tmp(i->second,-1);
            //cout<<i->first<<" "<<i->second<<endl;
            map[i->first]=tmp;
            //cout<<tmp.size()<<endl;
        }
        //use to check found all t[i]
        for(auto i=count_map.begin();i!=count_map.end();i++){
            i->second=0;
        }
        
        string ans;
        int tmp_size;
        int flag=0;
        
        int find_min_tmp_min;
        
        for(int i=0;i<ns;i++){
            if(map.find(s[i])==map.end()) continue;
            else{
                if(flag==0){
                    int min01tmp=map[s[i]][0];
                    int tmp_j=0;
                    int flag01tmp=0;
                    for(int j=0;j<map[s[i]].size();j++){
                        if(map[s[i]][j]==-1){
                            map[s[i]][j]=i;
                            flag01tmp=1;
                            break;
                        }else{
                            if(map[s[i]][j]<min01tmp){
                                tmp_j=j;
                                min01tmp=map[s[i]][j];
                            }
                        }
                    }
                    
                    if(flag01tmp==1){
                        count_map[s[i]]=1;
                        for(int j=0;j<map[s[i]].size();j++){
                            if(map[s[i]][j]==-1){
                                count_map[s[i]]=0;
                                break;
                            }
                        }
                        //if(s[i]=='d') cout<<count_map[s[i]]<<" "<<"d"<<" "<<map[s[i]][0]<<endl;
                        if(count_map[s[i]]==1){
                            int flag02tmp=0;
                            for(auto i=count_map.begin();i!=count_map.end();i++){
                                if(i->second==0){
                                    flag02tmp=1;
                                    break;
                                }
                            }
                            
                            if(flag02tmp==0){
                                //all found
                                flag=1;
                                find_min_tmp_min=find_min(map);
                                tmp_size=i-find_min_tmp_min+1;
                                
                               // cout<<"tmp_size "<<tmp_size<<endl;
                                //cout<<find_min(map)<<" "<<i+1<<endl;
                                ans=s.substr(find_min_tmp_min,tmp_size);
                                //cout<<"ans "<<ans<<endl;
                                //cout<<"hello ley"<<endl;
                            }
                            
                        }
                    }else{
                        //flag01tmp==0
                        //mean    all have number ,so change the min one to i
                        map[s[i]][tmp_j]=i;
                    }
                    
                    
                }else{
                    //flag==1
                    //have found
                    int tmptmp_k=0;
                    int tmptmp_min=map[s[i]][0];
                    for(int k=0;k<map[s[i]].size();k++){
                        if(map[s[i]][k]<tmptmp_min){
                            tmptmp_k=k;
                            tmptmp_min=map[s[i]][k];
                        }
                    }
                    
                    map[s[i]][tmptmp_k]=i;
                    
                    if(tmptmp_min==find_min_tmp_min){
                        find_min_tmp_min=find_min(map);
                    }
                    
                    int tmptmp=i-find_min_tmp_min+1;
                    if(tmptmp<tmp_size){
                        //cout<<"tmptmp"<<tmptmp<<endl;
                        tmp_size=tmptmp;
                        ans=s.substr(find_min_tmp_min,tmp_size);
                    }
                }
            }
        }
        
        if(flag==0) return "";
        else{
            return ans;
        }
    }
    
    int find_min(unordered_map<char, vector<int>>& map){
        int ans=map.begin()->second[0];
        for(auto i=map.begin();i!=map.end();i++){
            for(int j=0;j<i->second.size();j++){
                if(i->second[j]<ans) ans=i->second[j];
            }
        }
        return ans;
    }
};

int main(){
    string a="ADOBECODEBANC";
    string b="ABC";
    Solution aaa;
    cout<<aaa.minWindow(a, b)<<endl;
}
