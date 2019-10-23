#include "leetcode.h"

int main() {
	vector<int> nums = { 5,7,7,8,8,10 };
	int target = 8;
	vector<int> ans;
	Solution a;
	
	ans=a.searchRange(nums,target);
	
	for (int i = 0; i <=ans.size()-1; i++) {
		cout << ans[i] << endl;
	}
	

	return 0;
}