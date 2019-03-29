//
//  006inverse_int.cpp
//  test
//
//  Created by ley on 2019/3/29.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int int_max=0x7fffffff;
        int int_min=0x80000000;
        //记得2e31，在c++里指的是2乘10的31次方。。。。。。
        if(x==int_min) return 0;
        int answer=0;
        int signal=0;
        if(x>0) {
            signal=1;
        }
        while(x!=0){
            int temp=x%10;
            if(answer>int_max/10||answer<int_min/10) return 0;
            answer=answer*10;
            //cout<<answer<<"? ";
            if(signal==1){
                if(temp>int_max-answer) return 0;
            }else{
                if(temp<int_min-answer) return 0;
            }
            //这个地方还是挺阴险的，一开始没想懂
            answer=answer+temp;
            //cout<<answer<<" ";
            x=x/10;
            //cout<<x<<"! ";
        }
        return answer;
    }
};

int main(){
    int aa=-123;
    int int_max=0x7fffffff;
    int int_min=0x80000000;
    cout<<endl<<endl<<"hello ley"<<endl;
//    cout<<aa%10<<" "<<aa/10<<endl;
    Solution b;
    cout<<"answer: "<<b.reverse(aa)<<endl;
    cout<<int_max<<" "<<int_min<<endl;
    return 0;
}
