//
//  017phone_number.cpp
//  test
//
//  Created by ley on 2019/4/9.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unsigned long size=digits.size();
        vector<string> ans_empty;
        if(size==0) return ans_empty;
        int num=1;
        for(int i=0;i<size;i++){
            if(digits[i]=='9'||digits[i]=='7'){
                num=4*num;
            }
            else{
                num=3*num;
            }
        }
        
        vector<string> ans(num,"");
        int eihei=num;  //不太对，eihei是用来算周期的，总的还是size？？该怎么写
        for(int i=0;i<size;i++){
            if(digits[i]=='9'||digits[i]=='7'){
                string temp_string2;
                if(digits[i]=='9') temp_string2="wxyz";
                else{
                    temp_string2="pqrs";
                }
                int temp=0;
                while(temp+eihei<=num){
                      for(int j=temp;j<(temp+eihei);j++){
                    if(j<temp+(eihei/4)){
                        ans[j]=ans[j]+temp_string2[0];
                    }else if(j<temp+(eihei/2)){
                        ans[j]=ans[j]+temp_string2[1];
                    }else if (j<temp+3*(eihei/4)){
                        ans[j]=ans[j]+temp_string2[2];
                    }else{
                        ans[j]=ans[j]+temp_string2[3];
                    }
                         
                      }
                    temp=temp+eihei;
                }
                eihei=eihei/4;
            }else{
                string temp_string;
                if(digits[i]=='2') temp_string="abc";
                else if(digits[i]=='3') temp_string="def";
                else if(digits[i]=='4') temp_string="ghi";
                else if(digits[i]=='5') temp_string="jkl";
                else if(digits[i]=='6') temp_string="mno";
                else{
                    temp_string="tuv";
                }
                int temp=0;
                while(temp+eihei<=num){
                    for(int j=temp;j<(temp+eihei);j++){
                        if(j<temp+(eihei/3)){
                            ans[j]=ans[j]+temp_string[0];
                        }else if (j<temp+2*(eihei/3)){
                            ans[j]=ans[j]+temp_string[1];
                        }else{
                            ans[j]=ans[j]+temp_string[2];
                        }
                    }
                    temp=temp+eihei;
//                    for(int k=0;k<ans.size();k++){
//                        cout<<ans[k]<<endl;
//                    }
                }
                eihei=eihei/3;
            }
        }
        
        return ans;
    }
};


int main(){
    cout<<endl<<endl;
    
    string hahahaha="23";
    vector<string> answer;
    Solution aa;
    answer=aa.letterCombinations(hahahaha);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<endl;
    }
    
    cout<<endl;
    return 0;
}
