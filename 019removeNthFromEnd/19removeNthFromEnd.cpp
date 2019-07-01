// 19removeNthFromEnd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

/***********
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Given a linked list, remove the n-th node from the end of list and return its head.
Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
************/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int length = 1;
		ListNode* tmp = head;
		
		//�ж��ܹ��ж��ٽ��
		while (tmp->next != NULL)
		{
			length++;
			tmp = tmp->next;
		}

		//����Ҫɾ�����ǵڼ������
		int deleteNode = length - n;

		tmp = head;

		//�ж�����ȡ���Ǵ�������Ϊ"[1] 1"����� 
		for (size_t i = 1; i <= length; i++)
		{
			if (deleteNode == i)
			{
				ListNode * p;
				p = tmp->next;
				tmp->next = tmp->next->next;
				delete p;
				p = nullptr;
			}
			//����ɾ����һ�����
			else if (deleteNode == 0)
			{
				tmp = head->next;
				delete head;
				head = nullptr;
				return tmp;
			}
			else
				tmp = tmp->next;
		}
		return head;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
