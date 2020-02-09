//
//  146_LRU_cache.cpp
//  test
//
//  Created by ley on 2020/2/9.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class LRUCache {
public:
    unordered_map<int, list<pair<int,int>>::iterator> map;  //key,iter
    list<pair<int, int>> lis;   //key,value
    int cap;
    
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(map.find(key)==map.end()){
            return -1;
            //not found
        }else{
            //found
            pair<int,int> tmp=*(map[key]);
            lis.erase(map[key]);
            lis.push_back(tmp);
            map[key]=(--lis.end());
            return tmp.second;
        }
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            //already exit
            //1.update the list position to the tail
            lis.erase(map[key]);
            lis.push_back(pair<int,int>(key,value));
            map[key]=(--lis.end());
            
        }else{
            //not found, need to put
            if(map.size()<cap){
                //just put and add to the tail
                lis.push_back(pair<int,int>(key,value));
                map[key]=(--lis.end());
            }else{
                //map.size()==cap  need to remove the head and add to the tail
                map.erase(lis.front().first);
                lis.erase(lis.begin());
                lis.push_back(pair<int, int>(key,value));
                map[key]=(--lis.end());
            }
            
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(){
    LRUCache ley(2);
    ley.put(1, 5);
    cout<<"hello world"<<endl;
    int tmp=ley.get(1);
    cout<<tmp<<endl;
    
   
    
    return 0;
}
