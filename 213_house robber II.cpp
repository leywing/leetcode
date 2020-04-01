#include "leetcode.h"
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		int n = nums.size();
		int tmplast = nums[n - 1];
		nums.pop_back();
		int a1 = rob2(nums);
		nums.push_back(tmplast);
		nums.erase(nums.begin());
		int a2 = rob2(nums);
		return a1 > a2 ? a1 : a2;
	}

	int rob2(vector<int>& nums) {
		int n = nums.size();
		vector<int> ve(n + 2, 0);
		for (int i = 2; i < n + 2; i++) {
			ve[i] = max(ve[i - 1], ve[i - 2] + nums[i - 2]);
		}
		return ve[n + 1];
	}
};

