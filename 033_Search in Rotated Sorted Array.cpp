#include "leetcode.h"

//�Һð���������ȫ����д�ģ�����
//20191011
//���ֲ������ڻ���

//�����ص���mid=(left+right+1)/2-1

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int size = nums.size();

		int max_n=0;

		int left = 0, right = size - 1;
		//�����ǲ��ǵ���������ֻ��1��2��Ԫ�ص����Σ���
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
				//˵�����ֵ�����ұ�
				left = tmp;
				tmp = (left + right) / 2;
				//ż���м���tmp��tmp+1����������tmp
			}
			else {
				//nums[tmp]<nums[left]
				//˵�����ֵ��tmp�����
				if (tmp - 1 > left) {
					right = tmp - 1;
					tmp = (left + right) / 2;
				}
				else {
					max_n = left; break;
				}
			}

		}

		//��max_n,������ֱ�Ӷ��ֲ��Ҿͺ���
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