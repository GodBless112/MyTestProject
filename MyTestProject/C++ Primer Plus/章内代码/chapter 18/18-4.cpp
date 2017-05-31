#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<ctime>
#include "test.h"
// constants
using namespace std;
const long Size1 = 39L;
const long Size2 = 100 * Size1;
const long Size3 = 100 * Size2;
// function prototype
bool f3(int x) { return x % 3 == 0; }
bool f13(int x) { return x % 13 == 0; }
int main(int argc, char* argv[])
{
	vector<int> numbers(Size1);
	srand(time(0));
	generate(numbers.begin(), numbers.end(), rand);
	cout << "Sample size = " << Size1 << endl;
	int count3 = count_if(numbers.begin(), numbers.end(), f3);
	cout << "Count of numbers divisible by 3:" << count3 << endl;
	int count13 = count_if(numbers.begin(), numbers.end(), f13);
	cout << "Count of numbers divisible by 13:" << count13 << endl;
	numbers.resize(Size2);
	generate(numbers.begin(), numbers.end(), rand);
	cout << "Sample size = " << Size2 << endl;
	class f_mod
	{
	private:
		int dv;
	public:
		f_mod(int d = 1) :dv(d) {}
		bool operator()(int x) { return x%dv == 0; }
	};
	count3 = count_if(numbers.begin(), numbers.end(), f_mod(3));
	cout << "Count of numbers divisible by 3:" << count3 << endl;
	count13 = count_if(numbers.begin(), numbers.end(), f_mod(13));
	cout << "Count of numbers divisible by 13:" << count13 << endl;
	numbers.resize(Size3);
	generate(numbers.begin(), numbers.end(), rand);
	cout << "Sample size = " << Size3 << endl;
	count3 = count_if(numbers.begin(), numbers.end(), 
		[](int x) { return x % 3 == 0; });
	cout << "Count of numbers divisible by 3:" << count3 << endl;
	count13 = count_if(numbers.begin(), numbers.end(), 
		[](int x) {return x % 13 == 0; });
	cout << "Count of numbers divisible by 13:" << count13 << endl;
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}


