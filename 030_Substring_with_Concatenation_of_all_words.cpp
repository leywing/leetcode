#include "leetcode.h"

using namespace std;

//先看了解析，再边看别人答案，边写，边理解的

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
			//这里很神奇了，原来map可以这样用，学起来
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
								//这里有必要进行这个判断吗？？？疑惑，不用吧？？
								//需要！
							  //非str，在-1后都小于，count都减小；
								//str,它没有count+1,所以不能减
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