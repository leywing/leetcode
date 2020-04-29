//
//  273_integer_to_english_words.cpp
//  test
//
//  Created by ley on 2020/4/28.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//from the discussion
//看了别人的。。。。。一看题目，就觉得应该超繁琐
//倒也不会。。。就是要注意细节。。大小写空格等
class Solution {
public:
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }else{
            string aa=num2(num);
            return aa.substr(1,aa.size()-1);
        }
    }
    
private:
    string num2(int num){
        if(num>=1000000000){
            return num2(num/1000000000)+" Billion"+num2(num%1000000000);
        }else if(num>=1000000){
            return num2(num/1000000)+" Million"+num2(num%1000000);
        }else if(num>=1000){
            return num2(num/1000)+" Thousand"+num2(num%1000);
        }else if(num>=100){
            return num2(num/100)+" Hundred"+num2(num%100);
        }else if(num>=20){
            return " "+tens[num/10-2]+num2(num%10);
        }else if(num>=1){
            return " "+to19[num-1];
        }else{
            return "";
        }
        
    }

    vector<string> to19={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
        "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"
    };
    vector<string> tens={"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    
};
