#include "leetcode.h"

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> st;
		int ans = 0;
		
		int s_length = s.size();
		for (int i = 0; i < s_length; i++) {
			if (s[i] == '(') st.push(-1);
			else {
				if (st.empty()) ;
				else if (st.top() == -1) {
					st.pop();
					int tmp_num = 1;
					while (st.top() > 0) {
						int tmp2 = st.top();
						tmp_num += tmp2;
						st.pop();
					}
					ans = tmp_num > ans ? tmp_num : ans;
					st.push(tmp_num);
				}
				else {

				}

			}

		}
	}
};