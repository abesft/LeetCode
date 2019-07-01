// 207CourseSchedule.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<unordered_set>

using namespace std;

/*https://leetcode.com/problems/course-schedule
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
						To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
			 To take course 1 you should have finished course 0, and to take course 0 you should
			 also have finished course 1. So it is impossible.*/

#if 0
class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
		vector<int> degree = indegree(numCourses, prerequisites);

		//���ͼ�в����ڻ�����i��ѭ��numCourses��
		for (int i = 0; i < numCourses; i++)
		{
			int j;
			//�ҵ����Ϊ0�Ķ���
			for (j = 0; j < numCourses; j++) {
				if (degree[j] == 0)
					break;
			}

			//������ڻ�,���ڲ��ѭ���������ѭ���������
			if (j == numCourses)
				return false;

			//������Ϊ0�ĵ�Ϊ-1��ͬʱ���������й����Ķ�������
			degree[j] = -1;
			for (auto const & s : graph[j])
				degree[s]--;
		}
		return true;
	}
private:

	//����ͼ�ڽӱ�
	vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph(numCourses);
		for (auto const &pre : prerequisites)
			graph[pre.second].insert(pre.first);
		return graph;
	}

	//����ÿ����������
	vector<int> indegree(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> degree(numCourses, 0);
		for (auto const s : prerequisites)
			degree[s.first]++;
		return degree;
	}
};
#else

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
		//0: δ���ʵĶ���
		//1: �Ѿ�������Ķ���
		//-1:���ڷ��ʵĶ���
		vector<int> visited(numCourses, 0);


		for (size_t i = 0; i < numCourses; i++)
		{
			if (DFS(graph, visited, i) == false)
				return false;
		}
		return true;
	}
private:

	//����ͼ�ڽӱ�
	vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph(numCourses);
		for (auto const &pre : prerequisites)
			graph[pre.second].insert(pre.first);
		return graph;
	}

	//���ر�ʾ��ǰ�Ƿ�����������
	bool DFS(vector<unordered_set<int>> &graph, vector<int> & visited, int vert) {
		if (visited[vert] == -1)
			return false;

		visited[vert] = -1;
		//ѭ����ǰ�����µ����й����Ķ���
		for (auto const &s : graph[vert])
		{
			if (DFS(graph, visited, s) == false)
				return false;
		}
		visited[vert] = 1;

		return true;
	}
};
#endif // 0

int main()
{
	Solution sln;
	int numCourses = 2;
	vector<pair<int, int>> prerequisites{ make_pair(0,1),make_pair(1,0) };
	cout << sln.canFinish(numCourses, prerequisites) << endl;
	std::cout << "2018-12-16.Hello World!\n";
}
