//
//  010regular_expression_matching.cpp
//  test
//
//  Created by ley on 2019/4/1.
//  Copyright © 2019年 ley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//下面的俩都是看别人的答案的，可惜，可惜
//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        if(p.empty()) return s.empty();
//
//        if(p[1]=='*'){
//            return isMatch(s, p.substr(2))||(!s.empty()&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1), p));//厉害了
//        }else{
//            return !s.empty()&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1), p.substr(1));
//        }
//
//    }
//};
//上面这个写得好简单，但是太慢了，内存占用也大；

//动态规划
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<bool>> f(m+1,vector<bool>(n+1,false));
        f[0][0]=true;//f(m)(n)对应说s[0,m-1],p[0,n-1]
        for(int i=1;i<=m;i++){
            f[i][0]=false;    //这一步，前面初始化的时候已经false,应该不用写吧
        }//s有，p空情形
        for(int j=1;j<=n;j++){
            f[0][j]=j>1&&p[j-1]=='*'&&f[0][j-2];//j>1
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*'){
                    f[i][j]=f[i][j-2]||((s[i-1]==p[j-2]||p[j-2]=='.')&&f[i-1][j]);//1.重复0次。 2.若等于p[j-2],则可直接判断下一个
                }else{
                    f[i][j]=f[i-1][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='.');  //1.相等，则i-1，j-1；
                }
            }
        }
        return f[m][n];
    }
};

int main(){
    string s="";
    string p= ".*b";
    Solution aa;
    cout<<endl<<endl<<"answer:1/0"<<endl<<aa.isMatch(s, p)<<endl;
    
    
    return 0;
}
