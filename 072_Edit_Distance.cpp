//
//  072_Edit_Distance.cpp
//  test
//
//  Created by ley on 2019/12/14.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word2.size()==0) return word1.size();
        if(word1.size()==0) return word2.size();
        return minD2(word1, word2, 0, 0, 0);
    }
    //这种递归方法可行，但是太慢了，得用DP；通不过测试，time limit exceeded
    
    int minD2(string& word1,string& word2,int i1,int i2,int steps_count){
        if(steps_count+abs_ley(word2.size()-i2-(word1.size()-i1))>word2.size()) return word2.size();
        while(i1<word1.size() && i2<word2.size() && word1[i1]==word2[i2]){
            i1++;
            i2++;
        }
        if(i1==word1.size()||i2==word2.size()){
            steps_count=steps_count+word1.size()-i1+word2.size()-i2;
            return steps_count;
        }else{
            return min_of_three(minD2(word1, word2, i1, i2+1, steps_count+1),
                                minD2(word1, word2, i1+1, i2, steps_count+1),
                                minD2(word1, word2, i1+1, i2+1, steps_count+1));
        }
        
        
        
    }
    
    int min_of_three(int i1,int i2,int i3){
        int min=i1<i2?i1:i2;
        min=min<i3?min:i3;
        
        return min;
    }
    
    int abs_ley(int i){
        return i>0?i:-i;
    }
};
