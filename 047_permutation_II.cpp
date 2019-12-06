//
//  047_permutation_II.cpp
//  test
//
//  Created by ley on 2019/12/6.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
      
        per3(0, nums, ans);
        return ans;
    }
    
    void per3(int spot,vector<int>& nums,vector<vector<int>>& ans){
        if(spot>=nums.size()-1){
            //cout<<" nums "<<endl;
            ans.push_back(nums);
            return;
        }
        
        unordered_map<int, int> u_map;

        
        for(int i=spot;i<nums.size();i++){
            if(nums[spot]==nums[i]&&i!=spot){continue;}
            else{
                
                if(u_map.find(nums[i])==u_map.end()) {
                    u_map[nums[i]]=i;
                    swap(nums[spot],nums[i]);
                    per3(spot+1, nums, ans);
                    swap(nums[spot],nums[i]);
                    //这里不swap回去，那么nums，就改变了，会影响下一次循环，那为什么上一题没影响啊？？？？
                    //w因为上一题，只要保证放到前面的数确定了，后面的数一样，会遍历完。
                }else{
                    continue;
                }
                
            }
        }
    }
};
//下面是别人写的 20ms的。多好啊！！！学学。
//也不知道为啥这叫dfs。。。。。deep first search
//思想就是：你完全可以建个map，记录每个数有多少个，然后每次往前传的。每一个位置，每个数放一次。   思路明确。

//class Solution {
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        vector<vector<int>> res;
//        vector<int> pmt;
//        unordered_map<int,int> cnt;
//        for (int num : nums) {
//            cnt[num]++;
//        }
//        dfs(res,pmt,cnt,nums);
//        return res;
//    }
//private:
//    void dfs(vector<vector<int>>& res,
//             vector<int>& pmt,
//             unordered_map<int,int>& cnt,
//             vector<int>& nums) {
//        for (auto it = cnt.begin(); it != cnt.end(); it++) {
//            if (it->second) {
//                pmt.push_back(it->first);
//                it->second--;
//                if (pmt.size() == nums.size())
//                    res.push_back(pmt);
//                else
//                    dfs(res, pmt, cnt, nums);
//                pmt.pop_back();
//                it->second++;
//            }
//        }
//    }
//};



int main(){
    cout<<endl<<endl;
    cout<<"start"<<endl;
    
    Solution a;
    vector<int> input={3,3,0,3};
    a.permuteUnique(input);
    
    
    return 0;
}
