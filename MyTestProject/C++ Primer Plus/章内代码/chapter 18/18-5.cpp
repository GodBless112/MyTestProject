#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<ctime>
#include "test.h"
// constants
using namespace std;
const long Size1 = 390000L;
// function prototype

int main(int argc, char* argv[])
{
	vector<int> numbers(Size1);
	srand(time(0));
	generate(numbers.begin(), numbers.end(), rand);

	int count3 = count_if(numbers.begin(), numbers.end(), 
		[](int x) { return x % 3 == 0; });
	cout << "Count of numbers divisible by 3:" << count3 << endl;
	int count13 = 0;
	for_each(numbers.begin(), numbers.end(),
		[&count13](int x) {count13 += x % 13 == 0; });
	cout << "Count of numbers divisible by 13:" << count13 << endl;
	count3 = count13 = 0;
	for_each(numbers.begin(), numbers.end(),
		[&](int x) {count3 += x % 3 == 0; count13 += x % 13 == 0; });
	cout << "Count of numbers divisible by 3:" << count3 << endl;
	cout << "Count of numbers divisible by 13:" << count13 << endl;
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}


