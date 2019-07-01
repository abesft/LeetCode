// 060PermutationSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
using namespace std;

/*https://leetcode.com/problems/permutation-sequence/
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

	"123"
	"132"
	"213"
	"231"
	"312"
	"321"

Given n and k, return the kth permutation sequence.

Note:
	Given n will be between 1 and 9 inclusive.
	Given k will be between 1 and n! inclusive.

Example 1:
Input: n = 3, k = 3
Output: "213"

Example 2:
Input: n = 4, k = 9
Output: "2314"
*/

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<bool> used(n, false);
		string res;
		backtracking(n, k, used, res);
		return res;
	}

private:
	void backtracking(int n, int& k, vector<bool>& used, string& res) {
		if (res.size() == n) {
			--k;
			return;
		}

		for (int i = 0; i < n; i++)
		{
			if (used[i]) continue;
			res.push_back(i + '1');
			used[i] = true;
			backtracking(n, k, used, res);
			//����Ѿ��������˵�k�����������еĻ���
			if (k == 0) break;
			res.pop_back();
			used[i] = false;
		}
	}
};

/*https://leetcode.com/problems/permutation-sequence/discuss/22507/%22Explain-like-I'm-five%22-Java-Solution-in-O(n)*/
class Solution1 {
public:
	string getPermutation(int n, int k) {
		//n��������Ԫ��
		vector<char> value(n);
		for (int i = 0; i < n; ++i) {
			value[i] = '1' + i;
		}

		//�׳� factorial[] = {1, 1, 2, 6, 24, ... n!}
		vector<int> factorial(n + 1);
		factorial[0] = 1;
		for (int i = 1; i <= n; ++i) {
			factorial[i] = factorial[i - 1] * i;
		}

		string res;
		--k;  //�ӵ�0����ʼ

		//��value�е�ѭ��ѡ��n�����ظ����ַ��õ�res
		//ÿ��ѭ��ȷ��res[i]��ֵ�Ƕ��١�
		for (int i = 1; i <= n; ++i) {
			//ȷ��k����������value�еڼ�������ʼ��ȫ����
			int index = k / factorial[n - i];
			res.push_back(value[index]);
			//�Ƴ��Ѿ���ѡ�����
			value.erase(value.begin() + index);
			//��Ϊ�����Ѿ�ȷ����Ҫ���ֵ����indx��ͷ��ȫ�����У�
			//���Ҫ�ų�ǰ���0��ͷ��ȫ���У���1��ͷ��ȫ����...��index-1��ͷ��ȫ���У�����k
			k -= index * factorial[n - i];
		}
		return res;
	}
};

int main()
{
	Solution sln;
	cout << sln.getPermutation(4, 9) << endl;
	std::cout << "Hello World!\n";
}
