///Dijkstra算法
//贪心算法，将所有点集分为已知和未知两部分，初始化选择一个点开始，然后每次选择
//未知集中离起点距离最近的点，并更新未知集中的距离信息，直到没有未知点为止。
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cmath>
#include<ctime>
#include<iomanip>
#include<exception>
#include<cstdlib>
#include<fstream>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#include<algorithm>
#include<functional>
#include<numeric>
#include<iterator>
#include<unordered_map>
#include<Windows.h>
#include "test.h"
// constants
using namespace std;
// function prototype
//伪代码
namespace Graph
{
#define DistType int
	struct Vertex
	{
		vector<Vertex *> adj;	//连接点的列表
		bool known;			//路径是否已知
		DistType dist;		//路径代价
		Vertex *path;		//存储路径
		int index;
	};
	vector<Vertex> s;
	int **c;
	void printPath(Vertex *v);
	void dijkstra(Vertex *v);
	Vertex* findSmallUnknownDist(vector<Vertex> &rhs);
}
using Graph::Vertex;
void Graph::printPath(Vertex *v)
{
	if (v->path != nullptr)
	{
		printPath(v->path);
		cout << " to ";
	}
	cout << v->index;
}
void Graph::dijkstra(Vertex *v)
{
	int index = 0;
	for (auto &x : s)
	{
		x.dist = 999999;
		x.known = false;
		x.index = index++;
	}
	v->dist = 0;
	for (;;)
	{
		Vertex* vv = findSmallUnknownDist(s);
		if (vv == nullptr)
			break;
		vv->known = true;
		for (int i = 0; i < vv->adj.size(); i++)
		{
			Vertex* w = vv->adj[i];
			if (!w->known)
				if ((vv->dist + c[vv->index][w->index])< w->dist)
				{
					w->dist = vv->dist + c[vv->index][w->index];
					w->path = vv;
				}
		}
	}
}
Vertex* Graph::findSmallUnknownDist(vector<Vertex>& rhs)
{
	Vertex* result = nullptr;
	DistType mindist = 999999;
	for (auto &v : rhs)
	{
		if (v.known == false && v.dist < mindist)
		{
			result = &v;
			mindist = v.dist;
		}
	}
	return result;
}
int main()
{
	using Graph::s;
	using Graph::c;
	s.resize(7);
	s[0].adj.push_back(&s[1]);
	s[0].adj.push_back(&s[3]);
	s[1].adj.push_back(&s[3]);
	s[1].adj.push_back(&s[4]);
	s[2].adj.push_back(&s[0]);
	s[2].adj.push_back(&s[5]);
	s[3].adj.push_back(&s[4]);
	s[3].adj.push_back(&s[5]);
	s[3].adj.push_back(&s[6]);
	s[3].adj.push_back(&s[2]);
	s[4].adj.push_back(&s[6]);
	s[6].adj.push_back(&s[5]);
	c = new int*[7];
	for (int i = 0; i < 7; i++)
		c[i] = new int[6];
	c[0][0] = 0; c[0][1] = 2; c[0][2] = 999999; c[0][3] = 1; c[0][4] = 999999; c[0][5] = 999999; c[0][6] = 999999;
	c[1][0] = 999999; c[1][1] = 0; c[1][2] = 999999; c[1][3] = 3; c[1][4] = 10; c[1][5] = 999999; c[1][6] = 999999;
	c[2][0] = 4; c[2][1] = 999999; c[2][2] = 0; c[2][3] = 999999; c[2][4] = 999999; c[2][5] = 5; c[2][6] = 999999;
	c[3][0] = 999999; c[3][1] = 999999; c[3][2] = 2; c[3][3] = 0; c[3][4] = 2; c[3][5] = 8; c[3][6] = 4;
	c[4][0] = 999999; c[4][1] = 999999; c[4][2] = 999999; c[4][3] = 999999; c[4][4] = 0; c[4][5] = 999999; c[4][6] = 6;
	c[5][0] = 999999; c[5][1] = 999999; c[5][2] = 999999; c[5][3] = 999999; c[5][4] = 999999; c[5][5] = 0; c[5][6] = 999999;
	c[6][0] = 999999; c[6][1] = 999999; c[6][2] = 999999; c[6][3] = 999999; c[6][4] = 999999; c[6][5] = 1; c[6][6] = 0;
	vector<int> test(10);
	for (auto &x : test)
		x = 1;
	Graph::dijkstra(&s[0]);
	Graph::printPath(&s[1]);
	cout << endl;
	Graph::printPath(&s[2]);
	cout << endl;
	Graph::printPath(&s[3]);
	cout << endl;
	Graph::printPath(&s[4]);
	cout << endl;
	Graph::printPath(&s[5]);
	cout << endl;
	Graph::printPath(&s[6]);
	cout << endl;

	cout << "Done.\n";
	// code to keep window open for MSVC++
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}


