//
//  155_min_stack.cpp
//  test
//
//  Created by ley on 2020/2/25.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class MinStack {
public:
    /** initialize your data structure here. */
    //看了别人的答案，有一个点非常重要：
    //先压栈的，后出栈     所以比前面的数 大的数，是不可能成为min的！！！！！所以只需要保留 比前面的数更小的数就好了
    MinStack() {
       
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty()||s2.top()>x) s2.push(x);
    }
    
    void pop() {
        if(s1.top()==s2.top()) s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
