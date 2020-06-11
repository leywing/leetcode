//
//  341_ Flatten Nested List Iterator.cpp
//  test
//
//  Created by ley on 2020/6/11.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
// Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
// Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

//........更慢了。。。
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }
    
    int next() {
        int ans=st.top().getInteger();
        st.pop();
        return ans;
    }
    
    bool hasNext() {
        while(!st.empty() && !st.top().isInteger()){
            auto tmp=st.top().getList();
            st.pop();
            helper(tmp);
        }
        return !st.empty();
    }
private:
    stack<NestedInteger> st;
    void helper(const vector<NestedInteger> & nestedList){
        int len=nestedList.size();
        for(auto a=nestedList.rbegin();a!=nestedList.rend();a++){
            st.push(*a);
        }
    }
};




//by myself ,but it's not real iterator
//class NestedIterator {
//public:
//    NestedIterator(vector<NestedInteger> &nestedList) {
//        helper(nestedList);
//        i=0;
//        len=nums.size();
//    }
//    
//    int next() {
//        return nums[i++];
//    }
//
//    bool hasNext() {
//        if(i<len) return true;
//        else return false;
//    }
//private:
//    int i;
//    int len;
//    vector<int> nums;
//    void helper(const vector<NestedInteger> &nestedList){
//        int len=nestedList.size();
//        for(int i=0;i<len;i++){
//            if(nestedList[i].isInteger()){
//                nums.push_back(nestedList[i].getInteger());
//            }else{
//                helper(nestedList[i].getList());
//            }
//        }
//    }
//};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
