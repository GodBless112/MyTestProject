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
	cout << "Ĭ�ϵ�candybarΪ��" << endl;
	init(candybar);
	display(candybar);
	char newBrand[MAX];
	double newWeight;
	int newEnergy;
	cout << "�������µ�candybar����:" << endl;
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
	cout << "�µ�candybarΪ��\n";
	cout << "brand: " << cb.brand << endl;
	cout << "weight: " << cb.weight << endl;
	cout << "energy: " << cb.energy << endl;
}