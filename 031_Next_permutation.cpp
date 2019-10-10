#include "leetcode.h"

//这个之前作业接触过，知道解法，自己写的
//注意reverse()

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		if (n == 1 || n == 0) ;
		else if(n==2){
			int temp = nums[0];
			nums[0] = nums[1];
			nums[1] = temp;
		}
		else{
			int left = n;
			for (int i = n - 2; i >= 0; i--) {
				if (nums[i] < nums[i+1]) {
					left = i + 1;
					break;
				}
			}
			
			if (left == n) {
				reverse(nums.begin(), nums.end());
			}
			else{
				//reverse(nums[i + 2], nums.end());
				//上面这样写是不行的！！！！！
				//迭代器角色（Iterator）：迭代器角色负责定义访问和遍历元素的接口。
				reverse(nums.begin() + left , nums.end());
				//这个要学！！会了！！！

				//注意这里的left就是我想要的该数的下标，也就是低left+1个数，所以我这里直接加left是对的，因为第一个是0，begin()+0
				//就是它，其他的第几个，begin+(i-1)就指向它
				for (int j = left; j <= n - 1; j++) {
					if (nums[left - 1] < nums[j]) {
						int tmp2 = nums[j];
						nums[j] = nums[left - 1];
						nums[left - 1] = tmp2;

						break;
					}
				}

			}
		}
	}
	
};
