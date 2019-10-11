#include "leetcode.h"

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> st;
		int ans = 0;
		
		int s_length = s.size();
		for (int i = 0; i < s_length; i++) {
			if (s[i] == '(') st.push(0);
			else {
				if (st.empty()) ;
				else if (st.top() == 0) {
					st.pop();
//                    int tmp_num = 1;
//                    while (!st.empty()&&st.top() > 0) {
//                            int tmp2 = st.top();
//                            tmp_num += tmp2;
//                            st.pop();
//                        }
//                    ans = tmp_num > ans ? tmp_num : ans;
//                    st.push(tmp_num);
                    st.push(1);
				}
				else if(st.top()>0){
                    int tmp22=0;
                    while(!st.empty()&&st.top()>0){
                        tmp22+=st.top();
                        st.pop();
                    }
                    ans=tmp22>ans?tmp22:ans;
                    
                    if(st.empty()) ;
                    else if(st.top()==-1){
                        ;
                    }else{
                        //==0
                        st.pop();
                        tmp22+=1;
                        ans=tmp22>ans?tmp22:ans;
                        st.push(tmp22);
                    }
                    
                }else{
                    st.push(-1);
				}

			}

		}
        int tmp009=0;
        while(!st.empty()){
            if(st.top()>0) {
                tmp009+=st.top();
                ans=tmp009>ans?tmp009:ans;
                st.pop();
            }else{
                tmp009=0;
                st.pop();
            }
            
        }
        
        return ans*2;
	}
};
