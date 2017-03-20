///深度优先应用算法-欧拉回路
//欧拉回路
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
vector<int> Prime(int n)
{
	vector<int> result;
	result.push_back(2);
	int i, j, k;
	for ( i = 3; i <= n; i += 2)		//偶数肯定不是素数
	{
		double temp = static_cast<int>(i);
		int mid = static_cast<int>(sqrt(temp));
		for (j = 0; j < result.size(); j++)
		{
			k = result[j];
			if (k > mid)
				break;
			if (i%k == 0)
				break;
		}
		if (k > mid || j == result.size())
			result.push_back(i);
	}
	return result;
}
//class FindMaxPath
//{
//private:
//	int **value;
//	int row;	//matrix size row X column
//	int column;
//	//int start[2];
//	//int end[2];
//	int **Path;
//	struct Grid
//	{
//		int i;
//		int j;
//		int value;
//		priority_queue<Grid*>
//	};
//public:
//	FindMaxPath(int **theValue = nullptr, int therow = 0, int thecolum = 0)
//		:value(theValue), row(therow), column(thecolum) 
//	{
//		Path = new int*[row];
//		for (int i = 0; i < row; i++)
//			Path[i] = new int[column];
//	}
//	~FindMaxPath() 
//	{
//		for (int i = 0; i < row; i++)
//			delete Path[i];
//		delete Path;
//	}
//	vector<int> GetPath(int maxstep, int start[2], int end[2])
//	{
//		vector<int> maxpath;
//		int currentStep = maxstep;
//		int next[2];
//		int maxValue = value[start[0]][start[1]];
//		int direction = 0;
//		int lastdirection;
//		next[0] = start[0];
//		next[1] = start[1];
//		while (currentStep > 0)
//		{
//			switch (direction)
//			{
//				//分别为上左下右,回溯
//			case 0:
//				next[0] = next[0] - 1;
//				next[1] = next[1];
//				currentStep--;
//				if (next[0] < 0 || Path[next[0]][next[1]] == 1 || (abs(next[0] - end[0]) + abs(next[1] - end[1])) > currentStep)
//				{
//					next[0] = next[0] + 1;
//					direction++;
//					currentStep++;
//					continue;
//				}
//				Path[next[0]][next[1]] == 1;
//				maxValue += value[next[0]][next[1]];
//				lastdirection = direction;
//				direction = 0;
//				break;
//			case 1:
//				next[0] = next[0];
//				next[1] = next[1] - 1;
//				currentStep--;
//				if (next[1] < 0 || Path[next[0]][next[1]] == 1 || (abs(next[0] - end[0]) + abs(next[1] - end[1])) > currentStep)
//				{
//					next[1] = next[1] + 1;
//					direction++;
//					currentStep++;
//					continue;
//				}
//				Path[next[0]][next[1]] == 1;
//				maxValue += value[next[0]][next[1]];
//				lastdirection = direction;
//				direction = 0;
//				break;
//			case 2:
//				next[0] = next[0] + 1;
//				next[1] = next[1];
//				currentStep--;
//				if (next[1] >= row || Path[next[0]][next[1]] == 1 || (abs(next[0] - end[0]) + abs(next[1] - end[1])) > currentStep)
//				{
//					next[0] = next[0] - 1;
//					direction++;
//					currentStep++;
//					continue;
//				}
//				Path[next[0]][next[1]] == 1;
//				maxValue += value[next[0]][next[1]];
//				lastdirection = direction;
//				direction = 0;
//				break;
//			case 3:
//				next[0] = next[0];
//				next[1] = next[1] + 1;
//				currentStep--;
//				if (next[0] >= column || Path[next[0]][next[1]] == 1 || (abs(next[0] - end[0]) + abs(next[1] - end[1])) > currentStep)
//				{
//					next[1] = next[1] - 1;
//					direction++;
//					currentStep++;
//					continue;
//				}
//				Path[next[0]][next[1]] == 1;
//				maxValue += value[next[0]][next[1]];
//				lastdirection = direction;
//				direction = 0;
//				break;
//			case 4:
//
//				break;
//			}
//		}
//	}
//};
class GetMaxGridPath
{
private:
	int start;
	int end;
	int row;
	int GridNum;
	int column;
	int **dist;
public:
	GetMaxGridPath(int therow = 0, int thecolumn = 0, int **Grid = nullptr, int thestart = 0, int theend = 0)
		:row(therow), column(thecolumn), start(thestart), end(theend)
	{
		GridNum = row*column;
		dist = new int*[GridNum];
		for (int i = 0; i < GridNum; i++)
			dist[i] = new int[GridNum];
		for (int i = 0; i < GridNum; i++)
			for (int j = 0; j < GridNum; j++)
				dist[i][j] = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (j + 1 < column)
				{
					dist[i*column + j][i*column + j + 1] = Grid[i][j] + Grid[i][j + 1];
					dist[i*column + j + 1][i*column + j] = dist[i*column + j][i*column + j + 1];
				}
				if (i + 1 < row)
				{
					dist[i*column + j][(i+1)*column + j] = Grid[i][j] + Grid[i+1][j];
					dist[(i + 1)*column + j][i*column + j] = dist[i*column + j][(i + 1)*column + j];
				}
			}
		}							
	}
	~GetMaxGridPath()
	{
		for (int i = 0; i < GridNum; i++)
			delete dist[i];
		delete dist;
	}
	int GetMaxValuePath()
	{
		for(int k=0;k<GridNum;k++)
			for(int i=0;i<GridNum;i++)
				for (int j = 0; j < GridNum; j++)
				{
					if (dist[i][k] && dist[k][j])
					{
						if (dist[i][j] < dist[i][k] + dist[k][j])
							dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
		return dist[start][end];
	}
};
int main()
{	
	int **a;
	a = new int*[3];
	for (int i = 0; i < 3; i++)
		a[i] = new int[3];
	int count = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			a[i][j] = count++;
	GetMaxGridPath test(3, 3, a, 1, 3);
	cout<<test.GetMaxValuePath();
	cout << "Done.\n";
	// code to keep window open for MSVC++
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}


