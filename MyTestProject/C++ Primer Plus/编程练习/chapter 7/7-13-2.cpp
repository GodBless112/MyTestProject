#include <iostream>
#include<cmath>
const int limit = 10;
double result(int a, int b);
int fill_array(double *scroe, int limit);
double show_array(double* score, int size);
void avg_array(double sum, int size);
using namespace std;
int main()
{
	double score[limit];
	int size = fill_array(score, limit);
	double sum = show_array(score, size);
	avg_array(sum, size);
	while (1);
	return 0;
}
int fill_array(double *score, int limit) 
{
	double temp;
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << "Enter score #" << i + 1 << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			//while (cin.get() != '\n')
				//continue;
			cout << "Bad Input!\n";
			break;
		}
		else if (temp < 0)
			break;
		score[i] = temp;
	}
	return i;
}
double show_array(double* score, int size)
{
	int i;
	double sum = 0.0;
	cout << "所有成绩： ";
	for (i = 0; i < size; i++)
	{
		sum += score[i];
		cout << score[i]<<" ";
	}
	return sum;
}
void avg_array(double sum, int size)
{
	cout << "平均值为：" << sum / size << endl;
}