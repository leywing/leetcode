#include "leetcode.h"

//���֮ǰ��ҵ�Ӵ�����֪���ⷨ���Լ�д��
//ע��reverse()

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
				//��������д�ǲ��еģ���������
				//��������ɫ��Iterator������������ɫ��������ʺͱ���Ԫ�صĽӿڡ�
				reverse(nums.begin() + left , nums.end());
				//���Ҫѧ�������ˣ�����

				//ע�������left��������Ҫ�ĸ������±꣬Ҳ���ǵ�left+1����������������ֱ�Ӽ�left�ǶԵģ���Ϊ��һ����0��begin()+0
				//�������������ĵڼ�����begin+(i-1)��ָ����
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
