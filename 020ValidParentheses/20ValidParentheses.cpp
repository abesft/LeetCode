// 20ValidParentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;


/*https://leetcode.com/problems/valid-parentheses/
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.*/


class Solution {
public:
	map<char, int> table{ {'(' ,-1}, {')' , 1}, {'{' ,-2}, {'}' , 2}, {'[' ,-3}, {']' , 3} };
	bool isValid(string s) {
		vector<int> stack;


		map<char, int>::iterator p;
		for (size_t i = 0; i < s.size(); i++)
		{
			p = table.find(s[i]);
			//����ǷǷ��ַ�������false
			if (p == table.end())
				return false;
			else
			{
				//�����ǰջ��û��Ԫ�أ���ֱ��ѹջ
				if (stack.size() == 0)
					stack.push_back(p->second);
				else
				{
					//�ж���ѹջ�������ܷ��֮ǰ��ƥ���ϣ���ƥ�������ջ���������ѹջ
					if (*(stack.end() - 1) + p->second == 0)
						stack.pop_back();
					else
						stack.push_back(p->second);
				}
			}
		}

		//������е��ַ���ƥ���ϣ���ջӦ���ǿյ�
		if (stack.size() == 0)
			return true;
		else
			return false;
	}
};

int main()
{
	Solution sln;
	cout << sln.isValid("()") << endl;
	cout << sln.isValid("()[]{}") << endl;
	cout << sln.isValid("(]") << endl;
	cout << sln.isValid("([)]") << endl;
	cout << sln.isValid("{[]}") << endl;
    std::cout << "Hello World!\n"; 
}
