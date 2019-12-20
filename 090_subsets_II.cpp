//
//  090_subsets_II.cpp
//  test
//
//  Created by ley on 2019/12/20.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> count;
        int n=nums.size();
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        
        int map_size=count.size();
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            vector<int> tmp_ans;
            sub2(ans, count, i+1, tmp_ans,n,map_size);
        }
        
        vector<int> tmp;
        ans.push_back(tmp);
        
        return ans;
        
        
    }
    
    void sub2(vector<vector<int>>& ans,unordered_map<int, int>& count,int lk,vector<int> tmp_ans,int left_n,int map_size){
        if(map_size<=0) return;
        if(lk>left_n) return ;
        else if(lk==left_n){
            for(auto i=count.begin();i!=count.end();i++){
                for(int j=1;j<=i->second;j++){
                    tmp_ans.push_back(i->first);
                }
            }
           // cout<<"lk=left_n "<<lk<<endl;
           // for(int m=0;m<tmp_ans.size();m++){
            //    cout<<tmp_ans[m]<<" ";
            //}
            //cout<<endl;
            ans.push_back(tmp_ans);
            return ;
        }
        else{
        //lk<left_n
            if(lk==1){
                for(auto i=count.begin();i!=count.end();i++){
                    tmp_ans.push_back(i->first);
//                    //cout<<"lk==1"<<endl;
//                    for(int m=0;m<tmp_ans.size();m++){
//                        cout<<tmp_ans[m]<<" ";
//                    }
//                    cout<<endl;
                    ans.push_back(tmp_ans);
                    tmp_ans.pop_back();
                }
            }else{
                auto k=count.begin();
                int tmp_num=k->first;
               // cout<<"k->first "<<tmp_num<<endl;
           
                int tmp_size=k->second;
             
                count.erase(k);
               // cout<<count.size()<<endl;
                if(tmp_size<lk){
                    for(int i=0;i<=tmp_size;i++){
                        for(int j=0;j<i;j++){
                            tmp_ans.push_back(tmp_num);
                        }
                        sub2(ans,count,lk-i,tmp_ans,left_n-tmp_size,map_size-1);
                        for(int yy=0;yy<i;yy++){
                            tmp_ans.pop_back();
                        }
                    }
                }else{
                    //tmp_size>=lk
                    for(int i=0;i<=lk-1;i++){
                        for(int j=0;j<i;j++){
                            tmp_ans.push_back(tmp_num);
                        }
                        sub2(ans,count,lk-i,tmp_ans,left_n-tmp_size,map_size-1);
                        for(int yy=0;yy<i;yy++){
                            tmp_ans.pop_back();
                        }
                    }
                    for(int j=0;j<lk;j++){
                        tmp_ans.push_back(tmp_num);
                    }
//                    cout<<"tmp_size>=lk"<<endl;
//                    for(int m=0;m<tmp_ans.size();m++){
//                        cout<<tmp_ans[m]<<" ";
//                    }
//                    cout<<endl;
                    ans.push_back(tmp_ans);
                    
                }
                count[tmp_num]=tmp_size;
            }
            
        
        }
        
        
    }
};


int main(){
    vector<int> nums={2,2,1};
    
    Solution aaa;
    aaa.subsetsWithDup(nums);
    cout<<"end"<<endl;
}
