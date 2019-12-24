//
//  097_interleaving_string.cpp
//  test
//
//  Created by ley on 2019/12/23.
//  Copyright © 2019 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"
class Solution {
public:
    //看了discussion 果然是DP，唉，我怎么就没想到。
    //others
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size();
        int n2=s2.size();
        if(s3.size()!=n1+n2) return false;
        
        vector<vector<bool>> table(n1+1,vector<bool> (n2+1,0));
        
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0&&j==0){
                    table[i][j]=true;
                }else if(i==0){
                    table[i][j]=table[i][j-1]&&s2[j-1]==s3[i+j-1];
                }else if(j==0){
                    table[i][j]=table[i-1][j]&&s1[i-1]==s3[i-1+j];
                }else{
                    table[i][j]=(table[i-1][j]&&s1[i-1]==s3[i-1+j])||(table[i][j-1]&&s2[j-1]==s3[i+j-1]);
                }
            }
        }
        
        return table[n1][n2];
    }
    
    
    
    
//    bool isInterleave(string s1, string s2, string s3) {
//        //初步想法是用递归
//
//        //当只有一个人是匹配时，就i++ or j++
//
//        //当两个人都匹配时，则进入递归，调用下一个函数
//        // i++ 一个函数，   j++ 一个函数
//
//        //但是总感觉前面有这种题，但这种写法，肯定会死在 aaaaaaaaaaaaa这种上吧？会吗？
//
//        //总记得前面这种类似的题，都是靠DP？？还是压栈，都是走不通了，才返回去找上一次分歧的
//
//
//        //果然不行！！！！超时了
//        int n1=s1.size();
//        int n2=s2.size();
//        int n3=s3.size();
//        if(n3!=n1+n2) return false;
//        if(n1==0){
//            if(s2==s3) return true;
//            else return false;
//        }
//        if(n2==0){
//            if(s1==s3) return true;
//            else return false;
//        }
//
//        return is2(s1,s2,s3,0,0,0);
//
//    }
//
//    bool is2(string& s1,string& s2,string& s3,int i,int j,int t){
//        int n1=s1.size();
//        int n2=s2.size();
//        int n3=s3.size();
//
//        int flag=0;
//        while(i<=n1-1&&j<=n2-1){
//            if(s1[i]==s3[t]&&s2[j]==s3[t]){
//                flag=1;
//                break;
//            }
//            else if(s1[i]==s3[t]){
//                i++;
//                t++;
//            }else if(s2[j]==s3[t]){
//                j++;
//                t++;
//            }else{
//                return false;
//            }
//        }
//
//        if(flag==1){
//            if(is2(s1, s2, s3, i+1, j, t+1)) return true;
//            else if(is2(s1, s2, s3, i, j+1, t+1)) return true;
//            else return false;
//        }
//
//        if(i>n1-1&&j>n2-1){
//            return true;
//        }else if(i>n1-1){
//            if(s2.substr(j)==s3.substr(t)) return true;
//            else return false;
//        }else{
//            //j>n2-1
//            if(s1.substr(i)==s3.substr(t)) return true;
//            else return false;
//        }
//
//
//
//
//    }
};
