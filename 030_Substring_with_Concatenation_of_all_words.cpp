#include "leetcode.h"

using namespace std;

//�ȿ��˽������ٱ߿����˴𰸣���д��������

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		int s_length = s.size();
		int words_num = words.size();

		vector<int> ans;
		if (s_length <= 0 || words_num <= 0) return ans;

		unordered_map<string,int> map_word;

		for (int i = 0; i < words_num; i++) {
			map_word[words[i]]++;
			//����������ˣ�ԭ��map���������ã�ѧ����
		}

		int w_length = words[0].size();
		for (int i = 0; i < w_length; i++) {
			int left = i;
			int count = 0;

			unordered_map<string, int> map_tmp;
			for (int j = i; j <= s_length - w_length; j+=w_length) {
				string str = s.substr(j,w_length);

				if (map_word.count(str)) {
					map_tmp[str]++;
					if (map_tmp[str] <= map_word[str]) {
						count++;
					}
					else
					{
						while (map_tmp[str] > map_word[str]) {
							string str1 = s.substr(left, w_length);
							map_tmp[str1]--;
							if (map_tmp[str1] < map_word[str1]) {
								count--;
								//�����б�Ҫ��������ж��𣿣����ɻ󣬲��ðɣ���
								//��Ҫ��
							  //��str����-1��С�ڣ�count����С��
								//str,��û��count+1,���Բ��ܼ�
							}

							left += w_length;

						}
					}

					if (count == words_num) {
						ans.push_back(left);

						map_tmp[s.substr(left, w_length)]--;
						count--;
						left += w_length;
					}
				}
				else {
					map_tmp.clear();
					count = 0;
					left = j + w_length;
				}
				
			}
		}


		return ans;
	}
};