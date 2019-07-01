// 054SpiralMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/spiral-matrix/
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]*/

/*https://leetcode.com/problems/spiral-matrix/solution/*/
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int rows = matrix.size();
		if (rows == 0)
			return res;
		int cols = matrix[0].size();
		//����Ƿ��Ѿ��߹���
		vector<vector<bool>> seen(matrix.size(), vector<bool>(matrix[0].size(), false));

		//r,c:��ǰλ�õ��к��У�di��ʾ�ƶ��ķ���
		int r = 0, c = 0, di = 0;

		//�� #��#��#��#��# ĳ���������ƶ�ʱ��r��c�ĸ��¹���
		const int dr[4] = { 0, 1, 0, -1 };
		const int dc[4] = { 1, 0, -1, 0 };

		//�ܹ�Ҫ��rows*cols����
		for (int i = 0; i < rows*cols; i++) {
			res.push_back(matrix[r][c]);
			seen[r][c] = true;

			//��һ�����ܵ�λ��
			int rr = r + dr[di];
			int cc = c + dc[di];

			//���matrix[rr][cc]�ڷ�Χ����û�߹�
			if (0 <= rr && rr < rows && 0 <= cc && cc < cols && seen[rr][cc] == false) {
				r = rr;
				c = cc;
			}
			else {
				//��������ƶ��ķ���
				di = (di + 1) % 4;
				r += dr[di];
				c += dc[di];
			}
		}
		return res;
	}
};

int main()
{
	Solution sln;
	vector<vector<int>> testcase{ {1, 2, 3},{4, 5, 6},{7, 8, 9} };
	vector<int> res = sln.spiralOrder(testcase);
	for (auto i : res)
		cout << i << " ";
	std::cout << "Hello World!\n";
}
