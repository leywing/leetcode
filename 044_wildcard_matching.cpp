//
//  044_wildcard_matching.cpp
//  test
//
//  Created by ley on 2019/12/4.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

class Solution {
public:
    //这个不能通过大数据集的原因是
    //这里的算法是遍历，根本不往前走，硬是想把所有的可能都算了，所以根本算不完。。。指数增长的可能性
    
    //而别人的递归都是往前走，遇到不可能了，再回来尝试 ’*‘的下一个可能。所以碰到正确答案比我的快
    
    //这个通过了1700/1809，后面长过不了
    bool isMatch(string s, string p) {
        if(p.size()==0){
            if(s.size()==0) return true;
            else return false;
        }
        if(s.size()==0){
            int a=p.size();
            for(int i=0;i<a;i++){
                if(p[i]!='*') return false;
            }
            return true;
        }
        return sonisMatch(s, p, 0,0);
    }
    
    bool sonisMatch(string& s,string& p,int s1,int p1){
        //if(s1>s.size()-1||p1>p.size()-1) return false;
        
        if(s1==s.size()-1&&p1==p.size()-1){
            if(p[p1]=='?'||p[p1]==s[s1]||p[p1]=='*') return true;
            else return false; //!=
        }
        if(p1==p.size()-1){
            if(p[p1]=='*') return true;
            else return false;  //s not arrive at s.size()-1,so not equal
        }
        if(s1==s.size()-1){
            int a=p.size();
            int flag=0;
            for(int i=p1;i<a;i++){
                if(p[i]=='*') continue;
                else if((p[i]==s[s1]&&flag==0)||(p[i]=='?'&&flag==0)){
                    flag=1;
                }else{
                    return false;
                }
            }
            return true;
        }
        
        if(p[p1]=='?'||p[p1]==s[s1]) return sonisMatch(s, p, s1+1, p1+1);
        if(p[p1]!='*') return false;
        //  p[p1]='*'
        while(p1+1<=p.size()-1&&p[p1+1]=='*'){
            p1+=1;
        }
        bool ans=0;
        for(int i=0;i<=s.size()-s1-1;i++){
            //！！！this
            bool a=sonisMatch(s, p, s1+i, p1+1);
            if(a) {
                ans=1;
                break;
            }
        }
        
        return ans;
    }
};

int main(){
    string a="abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbba";
    string b="**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";

    
    Solution ley;
    cout<<"result is"<<endl<<endl;
    cout<<ley.isMatch(a, b)<<endl;
    
    return 0;
    
}
