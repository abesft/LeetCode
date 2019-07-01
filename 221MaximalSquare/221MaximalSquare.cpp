// 221MaximalSquare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*https://leetcode.com/problems/maximal-square
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4*/

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {

		int rows = matrix.size();
		if (rows == 0)
			return 0;

		int cols = matrix[0].size();
		if (cols == 0)
			return 0;

		//״̬ת�ƾ����е�dp��ʾ���ǵ�ǰλ�������ɵ���������εı߳�
		//��������dp[rows+1][cols+1],���ٱ�Ե���ж�
		vector<vector<int>> dp(rows, vector<int>(cols));

		//�����п���ֻ��һ���� ����һ�� һ��
		int ans = dp[0][0];

		//�����һ��
		for (size_t i = 0; i < rows; i++)
		{
			dp[i][0] = matrix[i][0] - '0';
			ans = max(ans, dp[i][0]);
		}

		//�����һ��
		for (size_t i = 0; i < cols; i++)
		{
			dp[0][i] = matrix[0][i] - '0';
			ans = max(ans, dp[0][i]);
		}

		//
		for (size_t i = 1; i < rows; i++)
		{
			for (size_t j = 1; j < cols; j++)
			{
				if (matrix[i][j] == '1')
					dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
				else
					dp[i][j] = 0;
				ans = max(ans, dp[i][j]);
			}
		}
		return ans * ans;
	}
};


int main()
{
	Solution sln;
	vector<vector<char>> testcase{ {'1','0','1','0','0'},{'1','0','1','1','1'},
	{'1','1','1','1','1'},{'1','0','0','1','0'} };
	cout << sln.maximalSquare(testcase) << endl;
	std::cout << "2018-12-18.Hello World!\n";
}
