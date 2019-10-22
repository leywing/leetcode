#include "leetcode.h"

//我好棒！！！完全独立写的！！！
//20191011
//二分查找终于会了

//所以重点是mid=(left+right+1)/2-1

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int size = nums.size();

		int max_n=0;

		int left = 0, right = size - 1;
		//这里是不是单独考虑下只有1，2个元素的情形？？
		if (size == 0) return -1;
		else if (size == 1) {
			if (nums[0] == target) return 0;
			else {
				return -1;
			}
		}
		else if(size==2){
			if (nums[0] == target) return 0;
			else if (nums[1] == target) return 1;
			else return -1;
		}


		int tmp = (size + 1) / 2 - 1;
		while (1) {
			if (tmp == left || tmp == right) {
				max_n = nums[left] > nums[right] ? left : right;
				break;
			}
			if (nums[left] < nums[tmp]) {
				//说明最大值还在右边
				left = tmp;
				tmp = (left + right) / 2;
				//偶数中间是tmp、tmp+1；奇数就是tmp
			}
			else {
				//nums[tmp]<nums[left]
				//说明最大值在tmp左边了
				if (tmp - 1 > left) {
					right = tmp - 1;
					tmp = (left + right) / 2;
				}
				else {
					max_n = left; break;
				}
			}

		}

		//有max_n,接下来直接二分查找就好了
		int lf = 0, rg = 0;
		if (nums[0] < target) {
			lf = 1;
			rg = max_n;
		}
		else if (nums[0] == target) {
			return 0;
		}
		else {
			//target<nums[0]
			lf = max_n + 1;
			rg = size - 1;
		}

		if (lf > rg) { return -1; }

		int mid = (lf + rg+1) / 2 - 1;
		while (1) {
			if (nums[mid] == target) return mid;
			else if (nums[mid + 1] == target) return mid + 1;
			else if (target < nums[mid]) {
				rg = mid - 1;
			}
			else {
				//nums[mid]<target
				lf = mid + 1;
			}

			if (lf > rg) { return -1; }
			if (rg - lf == 1) {
				if (nums[lf] == target) return lf;
				else if (nums[rg] == target) return rg;
				else return -1;
			}
			if (rg == lf) {
				if (nums[lf] == target) return lf;
				else return -1;
			}

			mid = (lf + rg+1) / 2 - 1;
		}


	
	}
	
};