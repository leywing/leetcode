//
//  218_the_skyline_problem.cpp
//  test
//
//  Created by ley on 2020/4/8.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
//others from the submission
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, int>       mp;         //mp的作用？        表面  到这个 x前的高度 h
        vector<vector<int>> ans;
        
        int idx = 0;
        while (idx < buildings.size() || !mp.empty()) {
            
            if (!mp.empty() && (idx == buildings.size() || mp.begin()->first < buildings[idx][0])) { //方块用尽、or mp里的x更小
                //当mp 非空，且 idx可能已经到m最后了。or   mp里的first小于当前 idx的x
                auto it = mp.begin();
                auto jt = next(it);
                //next  取迭代器的下一个
                
                int x0 = it->first;
                int h  = (jt == mp.end() ? 0 : jt->second);
                
                mp.erase(it, jt);
                
                if (ans.empty() || ans.back()[1] != h) {
                    ans.push_back(vector<int>{x0, h});
                }
            }
            else {
                //新的方块的x0最小
                int x0 = buildings[idx][0];
                int x1 = buildings[idx][1];
                int h  = buildings[idx][2];
                
                auto it = mp.find(x1);
                
                if (it == mp.end()) {       //当前x为独有，没有人的tail跟这个x一样
                    auto status = mp.insert({x1, h});       //map不允许重复key值，   该insert会返回。 pair<iterator,bool>      可根据第二个bool判断是否成功
                    auto nt     = next(status.first);       //而第一个则是指向当前元素的迭代器。（若成功，指向新的插入的，，若失败，指向原有的
                    
                    //为什么需要 下一个？
                    //懂了，因为后一个的x比你大，如果你的h小于后面的，那你的高度，自然是 max()  (被后面更晚结束更高的拉高了）
                    
                    it = status.first;
                    
                    if (nt != mp.end()) {//下一个非末尾
                        it->second = max(h, nt->second);
                    }
                }
                else {
                    it->second = max(it->second, h);        //原本已有该x,  更新高度
                }
                
                //经过上面的操作，每个x上，对应的当时的最高level（每个x都是tail)
                
                int mx = it->second;
                
                if (it != mp.begin()) { //并非开头
                    auto jt = prev(it);
                    while (jt != mp.begin() && jt->second <= mx) {
                        --jt;       //往前面找到，jt, jt->secondy小于这个  当前x的h
                    }
                    
                    if (jt->second > mx) ++jt;  //此时 后移一位，  此个的second 肯定<=mx  有可能是自己  (并非一定mp.begin())
                    else if (jt == mp.begin() && jt->second <= mx) {    // 这一步好多余，感觉没有必要。肯定是mp.begin() && jt->second<=mx
                        jt = mp.begin();
                    }
                    
                    mp.erase(jt, it);//？？？？ 删除 从jt 到it      含前不含后           因为这里加了新的 it，所以前面比它矮的，x又比它小的，全都可以删除
                }
                
                
                h = mp.begin()->second;     //当前的level
                if (!ans.empty() && ans.back()[0] == x0) {      //若ans非空，且 其最后一个插入点 的x  跟x0相同       只有这里需要重点考虑x0相同的方块，因为x1相同的方块，mp已按规则更新了
                    ans.back()[1] = max(ans.back()[1], h);      //更新为最大的
                }
                else if (ans.empty() || ans.back()[1] != h) {       //若是空的，或者 高度不等于 h       则插入新的
                    ans.push_back(vector<int>{x0, h});
                }
                ++idx;
            }
            
        }
        
        return ans;
    }
};



//bool comp1(vector<int>& a,vector<int>& b){
//    return a[0]<b[0];           //用于sort  升序
//    //从小到大
//}
//
//struct comp2{
//    bool operator()(vector<int>& a,vector<int>& b){
//        return a[1]<b[1];
//        //大顶堆   //反过来的
//    }
//};
//
//
////速度还是很慢，只超过了百分之10几的人
////但是我找不到其他优化的点， 能想到的，就是原本其是排序好的，所以，可以直接用该序。只存该块的tail(优先队列）
//class Solution {
//public:
//    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//        //  vector    0:x   1:y  2:num of buildings
//        //sort  according to x
//        // map<int,bool>。     入数的时候，建立一个 map  num,true    出数时，num,false
//
//        //priority_queue 优先队列。
//        //每次 头 入数。   改map,   num,true      查该数是不是最大的，是的话。 ans 插入点
//        //尾，出数    查是否top 是该数。是，则pop ，map num,false   然后check下一个top,(若false ,就pop,循环，直到找到一个数 or empty) ans 插入点
//        //             若top,不是该数， map   num,false
//
//        //那怎么解决x,一样的呢
//        //一样的，只需要进出
//        //不一样的，或者 the end of same x,才进行level判断
//        vector<int> tmp;
//        vector<vector<int>> ley_vec;
//        int buildings_num=buildings.size();
//        for(int i=0;i<buildings_num;i++){
//            tmp={buildings[i][0],buildings[i][2],i};
//            ley_vec.push_back(tmp);
//            tmp={buildings[i][1],buildings[i][2],i};
//            ley_vec.push_back(tmp);
//        }
//
//        sort(ley_vec.begin(), ley_vec.end(), comp1);
//
//        //unordered_map<int, bool> u_map;
//        vector<bool> u_map(buildings_num,false);
//        priority_queue<vector<int>,vector<vector<int>>,comp2> p_que;
//       // bool  flag=false;
//        int tmp_x=0;
//        vector<vector<int>> ans;
//        int len=ley_vec.size();
//        for(int i=0;i<len;i++){
//            if(i+1<len&&ley_vec[i+1][0]==ley_vec[i][0]){  //same x
//                //flag=true;
//                if(!u_map[ley_vec[i][2]]){
//                    //head
//                    u_map[ley_vec[i][2]]=true;
//                    p_que.push(ley_vec[i]);
//                }else{
//                    //tail
//                    u_map[ley_vec[i][2]]=false;
//                    while(!p_que.empty()&&!u_map[p_que.top()[2]]){
//                        p_que.pop();    //已经出了的块
//                    }
//                }
//            }else{      //the end of the same x  or nothing to do with same x
//               // flag=false;
//                if(!u_map[ley_vec[i][2]]){
//                    //head
//                    u_map[ley_vec[i][2]]=true;
//                    p_que.push(ley_vec[i]);
//                }else{
//                    //tail
//                    u_map[ley_vec[i][2]]=false;
//                    while(!p_que.empty()&&!u_map[p_que.top()[2]]){
//                        p_que.pop();    //已经出了的块
//                    }
//                }
//                if(!p_que.empty()&&p_que.top()[1]!=tmp_x){
//                    tmp={ley_vec[i][0],p_que.top()[1]};
//                    ans.push_back(tmp);
//                    tmp_x=tmp[1]; //new y-level
//                }else{
//                    if(p_que.empty()){
//                        if(0!=tmp_x){
//                            tmp={ley_vec[i][0],0};
//                            ans.push_back(tmp);
//                            tmp_x=0;
//                        }
//                    }
//                }
//            }
//        }
//
//        return ans;
//    }
//};
