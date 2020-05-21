//
//  284_peeking_iterator.cpp
//  test
//
//  Created by ley on 2020/4/30.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//see the discussion  know the answer
//found that  i have forget all about class  , succeed class

//so have some practice

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *        struct Data;
 *         Data* data;
 *        Iterator(const vector<int>& nums);
 *         Iterator(const Iterator& iter);
 *
 *         // Returns the next element in the iteration.
 *        int next();
 *
 *        // Returns true if the iteration has more elements.
 *        bool hasNext() const;
 *    };
 */

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        Iterator it(*this);
        //copy current state to a new Iterator
        //use it to get the next() without influence *this
        return it.next();
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        return Iterator::next();
    }
    
    bool hasNext() const {
        return Iterator::hasNext();
    }
};
