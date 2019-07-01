// 347TopKFrequentElements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>
using namespace std;

/*https://leetcode.com/problems/top-k-frequent-elements/
Given a non-empty array of integers, return the k most frequent elements.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Note:
You may assume k is always valid, 1 �� k �� number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.*/

//�������map��multimapʵ�֡�
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		//��Ԫ��ֵ��Ϊmap��key��Ԫ�ظ�����Ϊmap��value��
		map<int, int> table;
		for (size_t i = 0; i < nums.size(); i++)
			table[nums[i]]++;

		//��Ԫ�صĸ�����Ϊmap��key��Ԫ��ֵ��Ϊmap��value��
		multimap<int, int> times_element;
		for (map<int, int>::iterator iter = table.begin(); iter != table.end(); iter++)
			times_element.insert(make_pair(iter->second, iter->first));

		vector<int> ans;
		auto iter = times_element.rbegin();
		for (int i = 0; i < k; i++)
		{
			ans.push_back(iter->second);
			iter++;
		}
		return ans;
	}
};

//����vector<vector<int>>��
class Solution2 {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		int length = nums.size();

		//����"Ԫ��ֵ->Ԫ�ظ���"�Ĺ�ϣ��
		unordered_map<int, int> freq_map;
		for (auto d : nums)
			freq_map[d]++;

		//����"Ԫ�ظ���>Ԫ��ֵ"��vector��ά���飬Ԫ�ظ�����ͬ��Ԫ�ػ�����һ��vector�С�
		vector<vector<int>> freq_vec(length, vector<int>());
		for (auto item : freq_map) {
			freq_vec[item.second - 1].push_back(item.first);
		}

		//freq_vec[i]��ʾnums��Ԫ�صĸ���Ϊi+1�ļ��ϣ���˵���ȡ��
		vector<int> ret;
		for (int i = length - 1; i >= 0; --i) {
			for (auto d : freq_vec[i]) {
				if (ret.size() < k)
					ret.push_back(d);
				else
					return ret;
			}
		}
		return ret;
	}
};

//����std::priority_queue������ʵ�֡�
class Solution3 {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		//��Ԫ��ֵ��Ϊmap��key��Ԫ�ظ�����Ϊmap��value��
		map<int, int> table;
		for (size_t i = 0; i < nums.size(); i++)
			table[nums[i]]++;

		//https://zh.cppreference.com/w/cpp/container/priority_queue
		//https://zh.cppreference.com/w/cpp/language/decltype
		auto cmp = [](const pair<int, int> &n1, const pair<int, int> &n2) {	return n1.second < n2.second; };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);

		for (map<int, int>::iterator iter = table.begin(); iter != table.end(); iter++)
			heap.push(make_pair(iter->first, iter->second));

		vector<int> ans;
		for (int i = 0; i < k; i++)
		{
			ans.push_back(heap.top().first);
			heap.pop();
		}
		return ans;
	}
	//private:
	//	struct compare
	//	{
	//		bool operator()(const pair<int, int> &n1, const pair<int, int> &n2)
	//		{
	//			return n1.second < n2.second;
	//		}
	//	};
};


int main()
{
	Solution3 sln;
	vector<int> testcase{ 1,1,1,2,2,3 };
	vector<int> ans = sln.topKFrequent(testcase, 2);
	for (const auto & i : ans)
		cout << i << " ";
	cout << endl;
	std::cout << "Hello World!\n";
}
