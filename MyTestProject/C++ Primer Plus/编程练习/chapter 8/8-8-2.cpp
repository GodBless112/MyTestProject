#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 60;
struct CandyBar {
	char brand[MAX];
	double weight;
	int energy;
};
void init(
	CandyBar & cb,
	const char *br = "Millennium Munch",
	double we = 2.85,
	int ca = 350
	);
void display(const CandyBar & cb);
int main()
{
	CandyBar candybar;
	cout << "默认的candybar为：" << endl;
	init(candybar);
	display(candybar);
	char newBrand[MAX];
	double newWeight;
	int newEnergy;
	cout << "请输入新的candybar数据:" << endl;
	cout << "brand: ";
	cin.get(newBrand, MAX);
	cout << "weight: ";
	cin >> newWeight;
	cout << "Energy: ";
	cin >> newEnergy;
	init(candybar, newBrand, newWeight, newEnergy);
	display(candybar);
	while (1);
	return 0;
}
void init(CandyBar &cb, const char *br, double we, int ca)
{
	strcpy_s(cb.brand, br);
	cb.weight = we;
	cb.energy = ca;
}
void display(const CandyBar &cb)
{
	cout << "新的candybar为：\n";
	cout << "brand: " << cb.brand << endl;
	cout << "weight: " << cb.weight << endl;
	cout << "energy: " << cb.energy << endl;
}