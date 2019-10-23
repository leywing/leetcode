#include "leetcode.h"

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int size = nums.size();
		vector<int> ans;


		if (size == 0) {
			ans.push_back(-1);
			ans.push_back(-1);
			return ans;
		}
		else if (size == 1) {
			if (nums[0] == target) {
				ans.push_back(0);
				ans.push_back(0);
				return ans;
			}
			else {
				ans.push_back(-1);
				ans.push_back(-1);
				return ans;
			}
		}
		else {
			//size>=2
			//double target_min = target - 0.1;
			//double target_max = target + 0.1;

			//首先先查找是否存在target
			int signal = two_spilt_search(nums, target);
			if (signal == -1) {
				ans.push_back(-1);
				ans.push_back(-1);
				return ans;
			}
			else {
				//则说明存在这个数
				//那么就可以从返回的序号开始，往左找第一个，往右找最后一个
				int min_lf = 0;
				int min_rg = signal;
				//				int min_ans=min_rg;
				int min_mid = (min_lf + min_rg) / 2;
				//(0+0+1)/2-1=-1?????????   54行fixed

				int max_lf = signal;
				int max_rg = size - 1;
				//				int max_ans=max_lf;
				int max_mid = (max_lf + max_rg) / 2;


				if (min_rg == min_lf) {
					//					min_ans = min_rg;
				}
				else {
					while (1) {
						if (nums[min_mid] == target) {
							min_rg = min_mid;
						}
						else {
							//nums[min_mid]<target
							min_lf = min_mid;
						}

						if (min_lf == min_rg) break;
						else if ((min_rg - min_lf) == 1) {
							if (nums[min_lf] == target) {
								min_rg = min_lf;
								break;
							}
							else {
								break;
							}
						}
						else {
							min_mid = (min_lf + min_rg) / 2;
						}

					}
				}

				if (max_rg == max_lf) {
					//					min_ans = min_rg;
				}
				else {
					while (1) {
						if (nums[max_mid] == target) {
							max_lf = max_mid;
						}
						else {
							//nums[max_mid]>target
							max_rg = max_mid;
						}

						if (max_lf == max_rg) break;
						else if (max_rg - max_lf == 1) {
							if (nums[max_rg] == target) {
								max_lf = max_rg;
								break;
							}
							else {
								break;
							}
						}
						else {
							max_mid = (max_lf + max_rg) / 2;
						}

					}
				}

				ans.push_back(min_rg);
				ans.push_back(max_lf);

				return ans;


			}

		}


	}
	int two_spilt_search(vector<int>& nums, int target) {
		int nums_size = nums.size();

		int left = 0;
		int right = nums_size - 1;

		if (nums_size == 0) return -1;
		else if (nums_size == 1) return (nums[0] == target ? 0 : -1);
		else {
			//nums_size>=2
			int mid = (left + right) / 2;
			while (1) {
				if (nums[mid] == target) return mid;
				else if (nums[mid + 1] == target) return mid + 1;
				else if (target < nums[mid]) {
					right = mid - 1;
				}
				else {
					//nums[mid]<target
					left = mid + 1;
				}

				if (left > right) { return -1; }
				if (right - left == 1) {
					if (nums[left] == target) return left;
					else if (nums[right] == target) return right;
					else return -1;
				}
				if (right == left) {
					if (nums[left] == target) return left;
					else return -1;
				}

				mid = (left + right) / 2;

			}

		}
	}
};



//别人写的，真简单啊!!!!
//vector<int> searchRange(int A[], int n, int target) {
//	int i = 0, j = n - 1;
//	vector<int> ret(2, -1);
//	// Search for the left one
//	while (i < j)
//	{
//		int mid = (i + j) / 2;
//		if (A[mid] < target) i = mid + 1;
//		else j = mid;
//	}
//	if (A[i] != target) return ret;
//	else ret[0] = i;
//
//	// Search for the right one
//	j = n - 1;  // We don't have to set i to 0 the second time.
//	while (i < j)
//	{
//		int mid = (i + j) / 2 + 1;	// Make mid biased to the right
//		if (A[mid] > target) j = mid - 1;
//		else i = mid;				// So that this won't make the search range stuck.
//	}
//	ret[1] = j;
//	return ret;
//}