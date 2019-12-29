//
//  125_valid_palindrome.cpp
//  test
//
//  Created by ley on 2019/12/29.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    bool isPalindrome(string s) {
        unsigned long n=s.size();
        if(n==0||n==1) return true;
        unsigned long i=0;
        unsigned long j=n-1;
        while(i<j && i<=n-1 && j>=0 && i>=0 &&j<=n-1){
            if (  !( (s[i]-'a'>=0&&s[i]-'z'<=0)||(s[i]-'A'>=0&&s[i]-'Z'<=0)||(s[i]-'0'>=0&&s[i]-'9'<=0) )  ){
                i++;
            }else if (  !( (s[j]-'a'>=0&&s[j]-'z'<=0)||(s[j]-'A'>=0&&s[j]-'Z'<=0)||(s[j]-'0'>=0&&s[j]-'9'<=0) )  ){
                j--;
            }else if( (s[i]-'0'>=0&&s[i]-'9'<=0)||(s[j]-'0'>=0&&s[j]-'9'<=0) ){
                if(s[j]-'0'>=0&&s[j]-'9'<=0){
                    if(s[j]-'0'>=0&&s[j]-'9'<=0){
                        if(s[i]-'0'==s[j]-'0'){
                            i++;
                            j--;
                            continue;
                        }else{
                            return false;
                        }
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }else{
                if(s[i]-'a'==s[j]-'a'
                     ||s[i]-'a'==s[j]-'A'
                     ||s[i]-'A'==s[j]-'a'
                     ||s[i]-'A'==s[j]-'A'){
                    i++;
                    j--;
                    continue;
                }else{
                     return false;
                }
            }
            
        }
        
        return true;
    }
};
