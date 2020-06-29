#include "leetcode.h"

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
	int len=envelopes.size();
	if(len==0) return 0;
	vector<int> dp;

	sort(envelopes.begin(),envelopes.end(),
		[](vector<int> a,vector<int> b){return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);} 	);
	//!!!!!!!
	for(auto tt:envelopes){
		auto iter = lower_bound(dp.begin(),dp.end(),tt[1]);		//!!!!!!
		if(iter==dp.end()){
			dp.push_back(tt[1]);
		}else{
			*iter = tt[1];	
		}
	}
	
	return dp.size();
	
		
    }
};
