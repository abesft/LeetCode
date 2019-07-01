// 32longestValidParentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/longest-valid-parentheses/
Given a string containing just the characters '(' and ')',
find the length of the longest valid(well - formed) parentheses substring��

Example 1:

Input: "(()"
	Output : 2
	Explanation : The longest valid parentheses substring is "()"*/

class Solution {
public:
	int longestValidParentheses(string s) {
		int length = s.size();
		if (length == 0 || length == 1)
			return 0;
		//dp������ʾ��ǰ�±�֮ǰ���ַ�����Ч�����ĳ���
		int * dp = new int[length];
		memset(dp, 0, sizeof(int)*length);

		//ֻ�н�β��')'�����Ų���Ҫ����dp���顣
		//��ʱ�������������'()'��'))'.

		for (int i = 1; i < length; i++)  //ע��i��Ҫ��size_t����
		{
			//ֻ�ж��ַ�Ϊ')'�����
			if (s[i] == ')')
			{
				if (s[i - 1] == '(')
				{
					//���ǰһ���ַ��պ�Ϊ'(',�����dp[i-2]�ĳ��ȣ�ע��߽���ж�
					dp[i] = (i - 2) >= 0 ? dp[i - 2] + 2 : 2;
				}
				else if (s[i - 1] == ')' && s[i - dp[i - 1] - 1] == '(')
				{
					//���ǰһ���ַ�Ϊ')',����ǰ����dp[i-dp[i-1]-1]���ַ��Ƿ�Ϊ'('
					dp[i] = (i - dp[i - 1] - 2) >= 0 ?
						dp[i - 1] + 2 + dp[i - dp[i - 1] - 2] : dp[i - 1] + 2;
				}
			}
		}
		int value = *std::max_element(dp, dp + length);
		delete[] dp;
		return value;
	}
};

int main()
{
	Solution sln;
	cout << sln.longestValidParentheses("(())") << endl;
	std::cout << "Hello World!\n";
}
