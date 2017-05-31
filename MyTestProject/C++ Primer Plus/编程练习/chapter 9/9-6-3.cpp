// static.cpp -- using a static local variable
#include <iostream>
#include <string>
// constants
//const int ArSize = 10;

// function prototype
using namespace std;
struct chaff
{
	char dross[20];
	int slag;
};
char buffer[512];
int main()
{
	chaff *cf1,*cf2;
	cf1 = new chaff[2];
	cf2 = new(buffer)chaff[2];
	strcpy_s(cf1[0].dross, "sha a");
	cf1[0].slag = 1;
	strcpy_s(cf1[1].dross, "nige");
	cf1[1].slag = 2;
	strcpy_s(cf2[0].dross, "sha a");
	cf2[0].slag = 1;
	strcpy_s(cf2[1].dross, "nige");
	cf2[1].slag = 2;
	for (int i = 0; i < 2; i++)
	{
		cout << "Num " << i + 1 <<" at "<< &cf1[i] << "  " << "droos: " << cf1[i].dross << "slag: " << cf1[i].slag<<endl;
		cout << "Num " << i + 1 <<" at "<<&cf2[i] << "  " << "droos: " << cf2[i].dross << "slag: " << cf2[i].slag<<endl;
	}
	// code to keep window open for MSVC++
	delete[]cf1;
	//delete[]cf2; 不能删除放入指定区域的new生成的动态数组
	cin.clear();
	while (cin.get() != '\n')
	continue;
	cin.get();
	
	return 0;
}

