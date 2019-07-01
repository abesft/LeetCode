// 31nextPermutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;


/*https://leetcode.com/problems/next-permutation/
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1*/

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() == 0)
			return;

		auto pos = nums.end() - 1;
		
		//����������н����λ��
		while (pos != nums.begin() && *(pos) <= *(pos-1))
		{
			pos--;
		}
		//������������Ѿ��ǽ���ģ�����һ���ֵ�����Ϊ��ת
		if (pos == nums.begin())
		{
			reverse(nums.begin(), nums.end());
			return;
		}

		//ȷ������ֵ���ڵ�λ��
		auto left = pos - 1;
		
		//���ұȽ���ֵ���ֵ(��С���Ǹ�,�����кܶ��ֵ�Ƚ���ֵ��)
		pos = nums.end()-1;
		while (*left >= *pos)
		{
			pos--;
		}
		
		//������ֵ��pos����
		swap(*left, *pos);
		//�����������
		reverse(left+1, nums.end());
		return;
	}
};

#if 0
class Solution {
public:
	/**
	 * @param nums: A list of integers
	 * @return: A list of integers
	 */
	vector<int> nextPermutation(vector<int> &nums) {
		// write your code here
		int i = nums.size() - 2;
		while (i >= 0 && nums[i + 1] <= nums[i]) --i;
		if (i >= 0) {
			int j = nums.size() - 1;
			while (nums[j] <= nums[i]) --j;
			int tmp = nums[j];
			nums[j] = nums[i];
			nums[i] = tmp;
		}
		reverse(nums.begin() + i + 1, nums.end());
		return nums;
	}
};
#endif // 0

int main()
{
#if 0
	//ԭʼ��std����next_permutation���������
	/*next_permutation(num,num+n)�����Ƕ�����num�е�ǰn��Ԫ�ؽ���ȫ���У�ͬʱ���ı�num�����ֵ��
���⣬��Ҫǿ�����ǣ�next_permutation()��ʹ��ǰ��Ҫ�����������鰴�������򣬷���ֻ���ҳ�������֮���ȫ��������*/
	vector<int> test{ 1,2,3 };
	bool result = next_permutation(test.begin(), test.end());
	for (auto const & i : test)
		cout << i;

#endif // 0

	Solution sln;
	vector<int> testcase{ 1,3,2 };
	sln.nextPermutation(testcase);
	for (auto const & i : testcase)
		cout << i << endl;
	std::cout << "Hello World!\n"; 
}
