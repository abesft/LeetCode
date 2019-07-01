// 76MinimumWindowSubstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
#include<numeric>
#include<map>
#include<limits>
using namespace std;

/*https://leetcode.com/problems/minimum-window-substring
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.*/

class Solution {
public:
	string minWindow(string s, string t) {
		std::map<char, int> ref;
		for (auto c : t)
			ref[c]++;

		int cnt = t.size(), begin = 0, end = 0;
		int d = INT_MAX, head = 0; //d��ʾ��ǰ�����������ַ�����

		while (end < s.size())
		{
			auto iter = ref.find(s[end]);

			//���s[end]��t��
			if (iter != ref.end())
			{
				if (iter->second > 0)
					cnt--;                //��Ҫ��ϳ��ַ���t���ַ�������1

				iter->second--;  //����map���Ӧ��ֵ
			}

			end++;    //βָ��ָ����һ���ַ�

			//begin��end���ַ����Ѿ�������t�е������ַ�������ͷָ�룬��Сd
			while (cnt == 0)
			{
				if (end - begin < d)
				{
					head = begin;
					d = end - head;
				}
				auto iter_start = ref.find(s[begin]);

				//������ַ�Ϊt�е��ַ�
				if (iter_start != ref.end())
				{
					iter_start->second++;

					if (iter_start->second > 0)
						cnt++;
				}
				begin++;
			}
		}
		return (d == INT_MAX) ? "" : s.substr(head, d);
	}
};

int main()
{
	Solution sln;
	cout << sln.minWindow("ADOBECODEBANC", "ABC") << endl;
	std::cout << "Hello World!\n";
}
